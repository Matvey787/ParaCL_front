import compileOpts;
import general;

import thelast;

#include <filesystem>

int main(int argc, char** argv)
{
    ParaCL::general::init_logging();

    auto&& [inputFileName, outputFileName] = ParaCL::general::handleCompileOpts(argc, argv);

    auto&& program = ParaCL::general::generateAST(inputFileName);


    last::write(program, outputFileName.replace_extension(".json"));



    // auto program_after_serialization_and_unserialization = 
    // ParaCL::front::AST::JSONToAst<boost::json::value>(outputFileName);

    // ParaCL::front::AST::astToJSON(program_after_serialization_and_unserialization, "ast.json");

    // auto var = ParaCL::front::AST::make_node<Variable, boost::json::value>("x");

}
