#include <boost/json.hpp>
#include <iostream>
#include <vector>

import ast;

using namespace ParaCL::front::AST;

int main()
{
    auto num  = make_json_node<NumberLiteral>(42);
    auto str  = make_json_node<StringLiteral>("hello world");
    auto var  = make_json_node<Variable>("x");
    auto scan = make_json_node<Scan>();

    std::cout << "=== NumberLiteral ===\n" << boost::json::serialize(to_json(num)) << "\n\n";
    std::cout << "=== StringLiteral ===\n" << boost::json::serialize(to_json(str)) << "\n\n";

    auto unary = make_json_node<UnaryOperator>(
        UnaryOperator::UnaryOperatorT::MINUS,
        make_json_node<NumberLiteral>(10)
    );
    std::cout << "=== UnaryOperator ===\n" << boost::json::serialize(to_json(unary)) << "\n\n";

    auto binary = make_json_node<BinaryOperator>(
        BinaryOperator::BinaryOperatorT::ADD,
        UniversalNode(var),
        make_json_node<NumberLiteral>(5)
    );

    std::cout << "=== BinaryOperator ===\n" << boost::json::serialize(to_json(binary)) << "\n\n";

    std::vector<UniversalNode> printArgs;
    printArgs.push_back(std::move(num));
    printArgs.push_back(std::move(str));
    auto print = make_json_node<Print>(std::move(printArgs));
    
    std::cout << "=== Print ===\n" << boost::json::serialize(to_json(print)) << "\n\n";

    auto whileBody = make_json_node<Scope>(std::move(print));
    auto whileStmt = make_json_node<While>(
        make_json_node<Variable>("i"),
        std::move(whileBody)
    );
    std::cout << "=== While ===\n" << boost::json::serialize(to_json(whileStmt)) << "\n\n";

    auto ifBody = make_json_node<Scope>(std::move(scan));
    auto ifStmt = make_json_node<If>(
        make_json_node<BinaryOperator>(BinaryOperator::BinaryOperatorT::ISEQ,
                                       make_json_node<Variable>("flag"),
                                       make_json_node<NumberLiteral>(1)),
        std::move(ifBody)
    );

    auto elseStmt = make_json_node<Else>(
        make_json_node<Scope>(make_json_node<StringLiteral>("else branch"))
    );

    std::vector<UniversalNode> ifs;
    ifs.push_back(std::move(ifStmt));
    auto condition = make_json_node<Condition>(std::move(ifs), std::move(elseStmt));
    std::cout << "=== Condition ===\n" << boost::json::serialize(to_json(condition)) << "\n\n";

    std::vector<UniversalNode> scopeStmts;
    scopeStmts.push_back(std::move(binary));
    scopeStmts.push_back(std::move(unary));
    auto finalScope = make_json_node<Scope>(std::move(scopeStmts));
    std::cout << "=== Final Scope ===\n" << boost::json::serialize(to_json(finalScope)) << "\n\n";

    ProgramAST program;
    program.addStatement(std::move(whileStmt));
    program.addStatement(std::move(condition));
    program.addStatement(std::move(finalScope));

    std::cout << "=== FULL PROGRAM AST ===\n" 
              << boost::json::serialize(to_json(program)) << "\n\n";

    std::cout << "Все ноды успешно сериализованы!\n";
    return 0;
}
