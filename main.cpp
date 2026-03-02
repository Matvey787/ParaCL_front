import compileOpts;
import general;

import ast;
import astToJSON;
import JSONToAst;
#include <boost/json.hpp>


int main(int argc, char** argv)
{
    ParaCL::general::init_logging();

    auto [inputFileName, outputFileName] = ParaCL::general::handleCompileOpts(argc, argv);

    auto program = ParaCL::general::generateAST(inputFileName);

    ParaCL::front::AST::astToJSON(program, outputFileName);

    auto program_after_serialization_and_unserialization = 
    ParaCL::front::AST::JSONToAst<boost::json::value>(outputFileName);

    ParaCL::front::AST::astToJSON(program_after_serialization_and_unserialization, "ast.json");

    // auto var = ParaCL::front::AST::make_node<Variable, boost::json::value>("x");

}
