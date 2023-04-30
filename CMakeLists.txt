cmake_minimum_required(VERSION 3.20)
project(cmake-template VERSION 0.0.1)

# set global CXX standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_DEBUG_POSTFIX d)

# set build output
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")


# options
option(BUILD_STATIC_LIB "Build static libraries" ON)
option(BUILD_EXECUTABLE "Build executable binaries" ON)
option(BUILD_TEST "Build library test" ON)


# 3rd lib fetch
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(FetchContent)
include(fetch/spdlog)
include(fetch/catch2)

add_subdirectory(src)
if (BUILD_TEST)
    add_subdirectory(test)
endif ()