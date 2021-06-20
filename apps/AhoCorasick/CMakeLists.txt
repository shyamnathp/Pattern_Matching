add_executable(Aho_Corasick AhoCorasickMatching.cpp)
target_link_libraries(Aho_Corasick stdc++fs)
target_include_directories(Aho_Corasick PUBLIC include)
target_include_directories(Aho_Corasick PUBLIC ../../third_party/aho_corasick/src/aho_corasick)