# =============================================================================
# front/CMakeLists.txt
# =============================================================================
cmake_minimum_required(VERSION 3.30)
project(ParaCL_Front VERSION 3.0.0)

set(AUTHORS 
    "Max Sebelev|https://github.com/Maksim-Sebelev"
    "Matthew Galicin|https://github.com/Matvey787"
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# generate project info
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/projInfo.cmake)




# all dependencies
find_package(LLVM REQUIRED CONFIG)
llvm_map_components_to_libnames(llvm_libs Support)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/deps/check-bison.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/deps/check-flex.cmake)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third-party/spdlog)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third-party/THE-LAST)









# ====================== BISON (Parser) ======================
set(PARSER_SRC_DIR          ${CMAKE_CURRENT_SOURCE_DIR}/parser)
set(BISON_PARSER_CPP_OUT    parser.tab.cpp)
set(BISON_PARSER_HPP_OUT    parser.tab.hpp)
set(BISON_INPUT_FILE        ${PARSER_SRC_DIR}/parser.y)
set(BISON_OUTPUT_DIR        ${CMAKE_BINARY_DIR}/generated/bison)

add_custom_command(
    OUTPUT
        ${BISON_OUTPUT_DIR}/${BISON_PARSER_CPP_OUT}
        ${BISON_OUTPUT_DIR}/${BISON_PARSER_HPP_OUT}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${BISON_OUTPUT_DIR}
    COMMAND ${BISON_EXECUTABLE}
        -d
        -o ${BISON_OUTPUT_DIR}/${BISON_PARSER_CPP_OUT}
        ${BISON_INPUT_FILE}
    DEPENDS ${BISON_INPUT_FILE}
    COMMENT "Generating Bison parser (${BISON_PARSER_CPP_OUT})"
    VERBATIM
)

add_library(parser STATIC)

target_sources(parser
    PRIVATE
        ${BISON_OUTPUT_DIR}/${BISON_PARSER_CPP_OUT}
        ${PARSER_SRC_DIR}/parse_error.cpp
        ${PARSER_SRC_DIR}/check_variables.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party/spdlog/include
)

target_include_directories(parser
    PUBLIC
        ${BISON_OUTPUT_DIR} # parser.tab.hpp
        ${PARSER_SRC_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/lexer/inc
)

target_link_libraries(parser 
    PUBLIC
        TheLast
        spdlog::spdlog_header_only
)









# ====================== FLEX (Lexer) ======================
set(LEXER_SRC_DIR          ${CMAKE_CURRENT_SOURCE_DIR}/lexer/src)
set(FLEX_LEXER_CPP_OUT     lexer.yy.cpp)
set(FLEX_INPUT_FILE        ${LEXER_SRC_DIR}/lexer.l)
set(FLEX_OUTPUT_DIR        ${CMAKE_BINARY_DIR}/generated/flex)

add_custom_command(
    OUTPUT
        ${FLEX_OUTPUT_DIR}/${FLEX_LEXER_CPP_OUT}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${FLEX_OUTPUT_DIR}
    COMMAND ${FLEX_EXECUTABLE}
        -o ${FLEX_OUTPUT_DIR}/${FLEX_LEXER_CPP_OUT}
        ${FLEX_INPUT_FILE}
    DEPENDS
        ${FLEX_INPUT_FILE}
        ${BISON_OUTPUT_DIR}/${BISON_PARSER_HPP_OUT}
    COMMENT "Generating Flex lexer (${FLEX_LEXER_CPP_OUT})"
    VERBATIM
)

add_library(lexer STATIC)

target_sources(lexer
    PRIVATE
        ${FLEX_OUTPUT_DIR}/${FLEX_LEXER_CPP_OUT}
)

target_include_directories(lexer
    PUBLIC
        ${FLEX_OUTPUT_DIR}   # lexer.yy.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/lexer/inc/
        ${BISON_OUTPUT_DIR}  # parser.tab.hpp
        ${PARSER_SRC_DIR}
)

target_link_libraries(lexer PRIVATE parser)

# ====================== Main executable ======================
add_executable(paracl-front src/main.cpp)

target_link_libraries(paracl-front
    PRIVATE
        boost_json
        lexer
        parser
        ${llvm_libs}
)

target_sources(paracl-front
    PUBLIC
        FILE_SET CXX_MODULES
        TYPE CXX_MODULES
        FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/general/compileOpts.cppm
            ${CMAKE_CURRENT_SOURCE_DIR}/general/general.cppm
            
)

target_include_directories(paracl-front
    PRIVATE 
        ${LLVM_INCLUDE_DIRS}
        ${CMAKE_CURRENT_BINARY_DIR}/generated # projInfo.hpp
        spdlog::spdlog_header_only
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party/spdlog/include
)
target_compile_definitions(paracl-front PRIVATE ${LLVM_DEFINITIONS})