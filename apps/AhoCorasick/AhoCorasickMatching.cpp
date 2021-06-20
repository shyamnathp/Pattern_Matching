//
// Created by shyamnath on 6/19/21.
//
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>

#include <aho_corasick.hpp>

namespace fs = std::filesystem;

int main()
{
    fs::path conceptsPath = fs::path("../../..") / "concepts.txt";
    fs::path fullPath = fs::canonical(conceptsPath);

    std::string token;
    aho_corasick::trie trie;
    trie.case_insensitive();

    std::ifstream is(fullPath.string());
    while (std::getline(is, token))
    {
        std::transform(token.begin(), token.end(), token.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
        trie.insert(token);
    }

    bool hasMathces = false;
    std::cout<<"Input Text:";
    std::string input;
    while (std::getline(std::cin, input))
    {
        std::cout<<"Matches: "<<"\t";
        auto results = trie.parse_text(input);

        for (const auto& result: results)
        {
            hasMathces = true;
            std::cout<<result.get_keyword()<<"\t";
        }

        if (not hasMathces)
            std::cout<<"none"<<"\n";

        std::cout<<"\nInput Text:";
    }

    return 0;
}