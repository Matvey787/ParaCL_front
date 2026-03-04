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

    auto&& defaultBuildDir = std::filesystem::path{"build/generated/json"};

    for (size_t i = 0; i < inputs.size(); ++i)
    {
        const auto& inputPath = inputs[i];
        const auto& outputPath = outputs[i];
        const auto& program = ParaCL::general::generateAST(inputPath);
        auto&& finalPath = std::filesystem::path{};
        
        if (outputPath.has_parent_path())
        {
            finalPath = outputPath;
        }
        else
        {    
            finalPath = defaultBuildDir / outputPath;
        }

        auto&& parent = finalPath.parent_path();
        
        if (!parent.empty())
        {
            std::filesystem::create_directories(parent);
        }

        last::write(program, finalPath);
    }

    return 0;
}
catch (const std::exception& e)
{    
    std::cerr << e.what() << std::endl;
}