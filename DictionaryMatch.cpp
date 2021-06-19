//
// Created by shyamnath on 5/22/21.
//
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>

#include <Dictionary.h>

namespace fs = std::filesystem;

int main() {

    std::vector<std::string> concepts;
    fs::path conceptsPath = fs::path("..") / "concepts.txt";
    fs::path fullPath = fs::canonical(conceptsPath);

    std::string token;
    std::ifstream is(fullPath.string());
    while (std::getline(is, token))
    {
        concepts.emplace_back(token);
    }

    auto wordMap = Dictionary(concepts);

    std::string input;
    std::cout<<"Input Text:";
    while (std::getline(std::cin, input)) {
        auto matchedWords = wordMap.findWords(input);

        std::cout<<"Matchers:";
        for(const auto& matchesWord: matchedWords)
            std::cout<<matchesWord<<"\t";

        std::cout<<"\nInput Text:";
    }
}
