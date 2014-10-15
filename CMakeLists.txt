cmake_minimum_required(VERSION 2.8)

project (xmacro_example)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories (
    ${xmacro_example_SOURCE_DIR}
    )

set (xmacro_example_SOURCES
    enum_utility.hpp
    msgcode.hpp
    msgcode.cpp
    example.cpp
    )

add_executable (xmacro_example
    ${xmacro_example_SOURCES}
    )
