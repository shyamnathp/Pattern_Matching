add_executable(benchmark AllPatternMatchers.cpp ../src/Dictionary.cpp)
target_include_directories(benchmark PUBLIC ../include)
target_include_directories(benchmark PUBLIC ../third_party/aho_corasick/src/aho_corasick)