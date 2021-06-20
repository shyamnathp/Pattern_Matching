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
    message("Test")
    include(FetchContent)
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
    )

    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    add_executable(
            tests
            tests/test_PatternMatchers.cpp
            tests/test_Dictionary.cpp
            src/Dictionary.cpp
    )
    target_include_directories(tests PUBLIC include)
    target_link_libraries(
            tests
            gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(tests)
endif ()
