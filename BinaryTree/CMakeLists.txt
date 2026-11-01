cmake_minimum_required(VERSION 3.10)
project(Tree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Tree
    src/main.cpp
    src/BinaryTree.cpp
    include/BinaryTree.h
)

target_include_directories(Tree PRIVATE include)