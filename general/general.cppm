module;

import ast;
import astToJSON;
import JSONToAst;

#include "parser.tab.hpp"

#include <boost/json.hpp>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <cstdio>
#include <string_view>


extern FILE* yyin;
extern ParaCL::front::AST::ProgramAST program;

export module general;

export namespace ParaCL::general 
{

ParaCL::front::AST::ProgramAST generateAST(const std::string& inputFileName)
{
    FILE* inputFile = fopen(inputFileName.c_str(), "r");

    if (!inputFile) throw std::runtime_error("Can't open file: " + inputFileName);

    yyin = inputFile;

    yy::parser paracl_parser;
    
    int result = paracl_parser.parse();
    
    if (result != 0) throw std::runtime_error("Parsing errors occured.");

    std::fclose(inputFile);

    return program;
}




void init_logging()
{
    auto console = spdlog::stdout_color_mt("console");

    // По умолчанию уровень INFO 
    spdlog::set_default_logger(console);
    spdlog::set_level(spdlog::level::info);
}

}; // namespace ParaCL::general
