cmake_minimum_required(VERSION 3.10)
project(MaLei_HashTable LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(HashTable
    src/main.cpp
    src/ChainedHashTable.cpp
    src/OpenHashTable.cpp
    include/HashTable.h
)

target_include_directories(HashTable PRIVATE include)