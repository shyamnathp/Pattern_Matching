cmake_minimum_required(VERSION 3.17)
project(Pattern_Matching)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(apps/PatternMatching)

add_subdirectory(apps/DictionaryMatch)

add_subdirectory(apps/AhoCorasick)

if(BUILD_BENCHMARKS)
    add_subdirectory(benchmarks)
endif()

if (BUILD_TESTING)
    add_subdirectory(tests)
endif ()
