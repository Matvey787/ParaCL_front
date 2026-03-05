#include <filesystem>
#include <vector>
#include <thread>
#include <iostream>

import compileOpts;
import general;
import thelast;

int main(int argc, char** argv) try
{
    ParaCL::general::init_logging();

    auto&& [inputs, outputs] = ParaCL::general::handleCompileOpts(argc, argv);

    for (size_t i = 0; i < inputs.size(); ++i)
    {
        auto&& inputPath = inputs[i];
        auto&& outputPath = outputs[i];
        auto&& program = ParaCL::general::generateAST(inputPath);
        auto&& parent = outputPath.parent_path();
        last::write(program, outputPath);

        last::dump(program, "ast.dot", "ast.svg");

    }

    // auto&& ast = read("");

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
