import compileOpts;
import general;

import thelast;

#include <filesystem>

int main(int argc, char** argv)
{
    ParaCL::general::init_logging();

    auto&& [inputFileName, outputFileName] = ParaCL::general::handleCompileOpts(argc, argv);

    auto&& program = ParaCL::general::generateAST(inputFileName);

    auto&& buildDir = "build/generated/json";
    std::filesystem::create_directories(buildDir);
    last::write(program, buildDir / outputFileName.replace_extension(".json"));

}
