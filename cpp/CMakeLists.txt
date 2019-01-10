cmake_minimum_required(VERSION 3.9)

# Project
set(TARGET_NAME bridges_finder)
set(BENCHMARK_NAME bridges_finder_bm)
project(bridges_finder)

# Dependencies
include(dependencies.cmake)

# Sources
set(SOURCE_FILES
        main.cpp
)
set(BENCHMARK_FILES
        benchmark.cpp
)

# Includes
set(INCLUDE_DIRS
        algorithm
        common
        lib
        reader
)

# Compiler flags and options
set(CMAKE_CXX_STANDARD 17)

# Targets
# Main
add_executable(${TARGET_NAME} ${SOURCE_FILES})
target_include_directories(${TARGET_NAME} PRIVATE ${INCLUDE_DIRS})

add_executable(${BENCHMARK_NAME} ${BENCHMARK_FILES})
target_include_directories(${BENCHMARK_NAME} PRIVATE ${INCLUDE_DIRS})
target_link_libraries(${BENCHMARK_NAME} benchmark -lpthread)
