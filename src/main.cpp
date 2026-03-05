#include <filesystem>
#include <vector>
#include <thread>
#include <iostream>

import compileOpts;
import general;
import thelast;

#include "read-ast.hpp"

int main(int argc, char** argv) try
{
    ParaCL::general::init_logging();

    auto&& [inputs, outputs] = ParaCL::general::handleCompileOpts(argc, argv);

    for (size_t it = 0, ite = inputs.size(); it != ite; ++it)
    {
        auto&& inputPath = inputs[it];
        auto&& outputPath = outputs[it];
        auto&& program = ParaCL::general::generateAST(inputPath);
        auto&& parent = outputPath.parent_path();
        last::write(program, outputPath);
        last::dump(program, "ast.dot", "ast.svg");
        auto&& ast = last::read(outputPath);
        last::dump(ast, "ast.2.dot", "ast.2.svg");
    }

    return 0;
}
catch (const std::exception& e)
{    
    std::cerr << e.what() << std::endl;
    return 1;
}
catch (...)
{
    std::cerr << "Undefied exception catched.\n";
    return 1;
}
