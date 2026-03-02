module;

#include <boost/json.hpp>
#include <sstream>
#include <iostream>
#include <fstream>
import ast;

export module astToJSON;


export boost::json::value;

namespace ParaCL::front::AST
{


template <>
boost::json::value visit<boost::json::value>(const NumberLiteral& node)
{
    boost::json::object obj;
    obj["kind"]  = "NumberLiteral";
    obj["value"] = node.value();
    return obj;
}

template <>
boost::json::value visit<boost::json::value>(const StringLiteral& node)
{
    boost::json::object obj;
    obj["kind"]  = "StringLiteral";
    obj["value"] = std::string{node.value()};
    return obj;
}

template <>
boost::json::value visit<boost::json::value>(const Variable& node)
{
    boost::json::object obj;
    obj["kind"] = "Variable";
    obj["name"] = std::string{node.name()};
    return obj;
}

template <>
boost::json::value visit<boost::json::value>(const Scan& /*node*/)
{
    boost::json::object obj;
    obj["kind"] = "Scan";
    return obj;
}

template <>
boost::json::value visit<boost::json::value>(const Print& node)
{
    boost::json::object obj;
    obj["kind"] = "Print";

    boost::json::array args_arr;
    for (const auto& arg : node.args())
        args_arr.emplace_back(arg.visit<boost::json::value>());

    obj["args"] = std::move(args_arr);
    return obj;
}

template <>
boost::json::value visit<boost::json::value>(const UnaryOperator& node)
{
    boost::json::object obj;
    obj["kind"] = "UnaryOperator";

    const char* op = nullptr;
    switch (node.type())
    {
        case UnaryOperator::UnaryOperatorT::MINUS: op = "-"; break;
        case UnaryOperator::UnaryOperatorT::PLUS:  op = "+"; break;
        case UnaryOperator::UnaryOperatorT::NOT:   op = "!"; break;
    }
    obj["operator"] = op;
    obj["argument"] = node.arg().visit<boost::json::value>();
    return obj;
}

template <>
boost::json::value visit<boost::json::value>(const BinaryOperator& node)
{
    boost::json::object obj;
    obj["kind"] = "BinaryOperator";

    const char* op = nullptr;
    using OpT = BinaryOperator::BinaryOperatorT;
    switch (node.type())
    {
        case OpT::ADD:      op = "+";   break;
        case OpT::SUB:      op = "-";   break;
        case OpT::MUL:      op = "*";   break;
        case OpT::DIV:      op = "/";   break;
        case OpT::REM:      op = "%";   break;
        case OpT::AND:      op = "&&";  break;
        case OpT::OR:       op = "||";  break;
        case OpT::ISAB:     op = ">";   break;
        case OpT::ISABE:    op = ">=";  break;
        case OpT::ISLS:     op = "<";   break;
        case OpT::ISLSE:    op = "<=";  break;
        case OpT::ISEQ:     op = "==";  break;
        case OpT::ISNE:     op = "!=";  break;
        case OpT::ASGN:     op = "=";   break;
        case OpT::ADDASGN:  op = "+=";  break;
        case OpT::SUBASGN:  op = "-=";  break;
        case OpT::MULASGN:  op = "*=";  break;
        case OpT::DIVASGN:  op = "/=";  break;
        case OpT::REMASGN:  op = "%=";  break;
    }
    obj["operator"] = op;
    obj["left"]     = node.larg().visit<boost::json::value>();
    obj["right"]    = node.rarg().visit<boost::json::value>();
    return obj;
}

template <>
boost::json::value visit<boost::json::value>(const While& node)
{
    boost::json::object obj;
    obj["kind"]      = "While";
    obj["condition"] = node.condition().visit<boost::json::value>();
    obj["body"]      = node.body().visit<boost::json::value>();
    return obj;
}

template <>
boost::json::value visit<boost::json::value>(const If& node)
{
    boost::json::object obj;
    obj["kind"]      = "If";
    obj["condition"] = node.condition().visit<boost::json::value>();
    obj["body"]      = node.body().visit<boost::json::value>();
    return obj;
}

template <>
boost::json::value visit<boost::json::value>(const Else& node)
{
    boost::json::object obj;
    obj["kind"] = "Else";
    obj["body"] = node.body().visit<boost::json::value>();
    return obj;
}

template <>
boost::json::value visit<boost::json::value>(const Condition& node)
{
    boost::json::object obj;
    obj["kind"] = "Condition";

    boost::json::array ifs_arr;
    for (const auto& if_node : node.getIfs())
        ifs_arr.emplace_back(if_node.visit<boost::json::value>());

    obj["ifs"] = std::move(ifs_arr);

    if (node.hasElse())
        obj["else"] = node.getElse().visit<boost::json::value>();

    return obj;
}

template <>
boost::json::value visit<boost::json::value>(const Scope& node)
{
    boost::json::object obj;
    obj["kind"] = "Scope";

    boost::json::array stmts;
    for (const auto& stmt : node.statements())
        stmts.emplace_back(stmt.visit<boost::json::value>());

    obj["statements"] = std::move(stmts);
    return obj;
}

template <>
boost::json::value visit<boost::json::value>(const ProgramAST& node)
{
    boost::json::object obj;
    obj["kind"] = "ProgramAST";

    boost::json::array stmts;
    for (const auto& stmt : node.getStatements())
        stmts.emplace_back(stmt.visit<boost::json::value>());

    obj["statements"] = std::move(stmts);
    return obj;
}

using json_value = boost::json::value;

template<typename T, typename... Args>
UniversalNode make_json_node(Args&&... args)
{
    return make_node<T, json_value>(std::forward<Args>(args)...);
}

json_value to_json(const ProgramAST& ast)
{
    return visit<json_value>(ast);
}

json_value to_json(const UniversalNode& node)
{
    return node.visit<json_value>();
}


export void
astToJSON(const ProgramAST& ast, std::string_view jsonFileNameWriteTo)
{
    auto json_ast = to_json(ast);

    std::ofstream out{std::string(jsonFileNameWriteTo)};

    // pretty_print(out, json_ast);
    
    if (out)
    {
        out << boost::json::serialize(json_ast);
    }

    out.close();
}

}