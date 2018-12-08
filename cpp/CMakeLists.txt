cmake_minimum_required(VERSION 3.9)

# Project
set(TARGET_NAME bridges_finder)
project(bridges_finder)

# Sources
set(SOURCE_FILES
        main.cpp
)

# Includes
set(INCLUDE_DIRS
        common
        reader
)

# Compiler flags and options
set(CMAKE_CXX_STANDARD 17)

# Target
add_executable(${TARGET_NAME} ${SOURCE_FILES})
target_include_directories(${TARGET_NAME} PRIVATE ${INCLUDE_DIRS})
