module;

#include "projInfo.hpp"
#include "llvm/Support/CommandLine.h"
#include <string>
#include <iostream>
#include <utility>
#include <exception>
#include <sstream>

export module compileOpts;

llvm::cl::opt<std::string> OutputFileName(
    "o",
    llvm::cl::desc("Specify output filename"),
    llvm::cl::value_desc("filename"),
    llvm::cl::init("a.out")
);

llvm::cl::alias OutputAlias(
    "output",
    llvm::cl::desc("Alias for -o"),
    llvm::cl::aliasopt(OutputFileName)
);

llvm::cl::opt<std::string> AstDumpFile(
    "d",
    llvm::cl::desc("Dump AST to .dot file for Graphviz"),
    llvm::cl::value_desc("filename"),
    llvm::cl::init("")
);

llvm::cl::alias AstDumpAlias(
    "ast-dump",
    llvm::cl::desc("Alias for -d"),
    llvm::cl::aliasopt(AstDumpFile)
);

llvm::cl::opt<bool> ShowVersion(
    "v",
    llvm::cl::desc("Show version information"),
    llvm::cl::init(false)
);

llvm::cl::opt<bool> ShowHelp(
    "h",
    llvm::cl::desc("Show this help message"),
    llvm::cl::init(false)
);

llvm::cl::list<std::string> InputFiles(
    llvm::cl::Positional,
    llvm::cl::desc("<input .cl file>"),
    llvm::cl::ZeroOrMore
);

const std::string noInputFilesErrorMsg = "No input .cl files provided.\n";

std::string getBriefDescription()
{
    using namespace ParaCL::general::projInfo;
    
    std::stringstream ss;
    ss << "ParaCL — the best language in the world\n";
    ss << "Version: " << ParaCLVersion << "\n";
    ss << "Authors:\n";
    
    for (const auto& author : authors)
    {
        ss << "  - " << author.name << " (" << author.gitLink << ")\n";
    }
    
    return ss.str();
}

export namespace ParaCL::general
{

std::pair<std::string, std::string> handleCompileOpts(int argc, char** argv)
{
    std::string briefDescription = getBriefDescription();

    llvm::cl::ParseCommandLineOptions(argc, argv, briefDescription);

    if (ShowHelp) {
        llvm::cl::PrintHelpMessage();
        exit(0);
    }

    if (ShowVersion)
    {
        std::cout << "ParaCL version: " << ParaCL::general::projInfo::ParaCLVersion << '\n';
        exit(0);
    }

    if (InputFiles.empty())
    {
        throw std::runtime_error(noInputFilesErrorMsg);
    }

    std::string inputPath = InputFiles[0];
    std::string outputPath = OutputFileName.getValue();

    return std::make_pair(inputPath, outputPath);
}

} // namespace ParaCL::general