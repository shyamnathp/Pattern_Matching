add_executable(DictionaryMatch DictionaryMatch.cpp ../../src/Dictionary.cpp)
target_link_libraries(DictionaryMatch stdc++fs)
target_include_directories(DictionaryMatch PUBLIC ../../include)