module;

#include <boost/json.hpp>
#include <string_view>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <fstream>

export module JSONToAst;

import ast;

namespace json = boost::json;

namespace ParaCL::front::AST
{

BinaryOperator::BinaryOperatorT string_to_bin_op(std::string_view op)
{
    using OpT = BinaryOperator::BinaryOperatorT;
    if (op == "+")   return OpT::ADD;     if (op == "-")   return OpT::SUB;
    if (op == "*")   return OpT::MUL;     if (op == "/")   return OpT::DIV;
    if (op == "%")   return OpT::REM;     if (op == "&&")  return OpT::AND;
    if (op == "||")  return OpT::OR;      if (op == ">")   return OpT::ISAB;
    if (op == ">=")  return OpT::ISABE;   if (op == "<")   return OpT::ISLS;
    if (op == "<=")  return OpT::ISLSE;   if (op == "==")  return OpT::ISEQ;
    if (op == "!=")  return OpT::ISNE;    if (op == "=")   return OpT::ASGN;
    if (op == "+=")  return OpT::ADDASGN; if (op == "-=")  return OpT::SUBASGN;
    if (op == "*=")  return OpT::MULASGN; if (op == "/=")  return OpT::DIVASGN;
    if (op == "%=")  return OpT::REMASGN;

    throw std::runtime_error("Unknown binary operator: " + std::string(op));
}

UnaryOperator::UnaryOperatorT string_to_un_op(std::string_view op)
{
    using OpT = UnaryOperator::UnaryOperatorT;
    if (op == "-") return OpT::MINUS;
    if (op == "+") return OpT::PLUS;
    if (op == "!") return OpT::NOT;

    throw std::runtime_error("Unknown unary operator: " + std::string(op));
}

// Внутренняя рекурсивная функция
template<typename RetT>
UniversalNode node_from_json(const json::value& jv)
{
    const auto& obj = jv.as_object();
    std::string_view kind = obj.at("kind").as_string();

    if (kind == "NumberLiteral")
        return make_node<NumberLiteral, RetT>(static_cast<int>(obj.at("value").as_int64()));
    
    if (kind == "StringLiteral")
        return make_node<StringLiteral, RetT>(std::string(obj.at("value").as_string()));

    if (kind == "Variable")
        return make_node<Variable, RetT>(std::string(obj.at("name").as_string()));

    if (kind == "Scan")
        return make_node<Scan, RetT>();

    if (kind == "Print") {
        std::vector<UniversalNode> args;
        for (const auto& arg_jv : obj.at("args").as_array()) 
            args.push_back(node_from_json<RetT>(arg_jv));
        return make_node<Print, RetT>(std::move(args));
    }

    if (kind == "UnaryOperator") {
        auto type = string_to_un_op(obj.at("operator").as_string());
        return make_node<UnaryOperator, RetT>(type, node_from_json<RetT>(obj.at("argument")));
    }

    if (kind == "BinaryOperator") {
        auto type = string_to_bin_op(obj.at("operator").as_string());
        auto left = node_from_json<RetT>(obj.at("left"));
        auto right = node_from_json<RetT>(obj.at("right"));
        return make_node<BinaryOperator, RetT>(type, std::move(left), std::move(right));
    }

    if (kind == "While" || kind == "If") {
        auto cond = node_from_json<RetT>(obj.at("condition"));
        auto body = node_from_json<RetT>(obj.at("body"));
        if (kind == "While") return make_node<While, RetT>(std::move(cond), std::move(body));
        return make_node<If, RetT>(std::move(cond), std::move(body));
    }

    if (kind == "Else")
        return make_node<Else, RetT>(node_from_json<RetT>(obj.at("body")));

    if (kind == "Scope") {
        std::vector<UniversalNode> stmts;
        for (const auto& s_jv : obj.at("statements").as_array())
            stmts.push_back(node_from_json<RetT>(s_jv));
        return make_node<Scope, RetT>(std::move(stmts));
    }

    if (kind == "Condition") {
        std::vector<UniversalNode> ifs;
        for (const auto& c_jv : obj.at("ifs").as_array())
            ifs.push_back(node_from_json<RetT>(c_jv));

        UniversalNode elseNode;
        if (obj.contains("else")) 
            elseNode = node_from_json<RetT>(obj.at("else"));

        return make_node<Condition, RetT>(std::move(ifs), std::move(elseNode));
    }

    throw std::runtime_error("Unsupported node kind during deserialization: " + std::string(kind));
}

export template<typename RetT = void>
ProgramAST from_json(std::string_view jsonData)
{
    json::value jv = json::parse(jsonData);
    const auto& jo = jv.as_object();

    if (jo.at("kind").as_string() != "ProgramAST")
        throw std::runtime_error("Root JSON element is not a ProgramAST");

    ProgramAST ast;
    for (const auto& stmt_jv : jo.at("statements").as_array()) {
        ast.addStatement(node_from_json<RetT>(stmt_jv));
    }

    return ast;
}

export template<typename RetT>
ProgramAST JSONToAst(std::string_view jsonFileNameReadFrom)
{
    std::ifstream in{std::string(jsonFileNameReadFrom)};
    
    if (!in) throw std::runtime_error("No such json file: " + std::string(jsonFileNameReadFrom));

    std::stringstream buffer;
    buffer << in.rdbuf(); 
    std::string jsonData = buffer.str();

    return from_json<RetT>(jsonData);
}

} // namespace ParaCL::front::AST