#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include <fstream>
#include <filesystem>

#include <PatternMatchers.h>

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

    bool hasMathces = false;
    std::cout<<"Input Text:";
    std::string input;
    while (std::getline(std::cin, input))
    {
        std::cout<<"Matches: "<<"\t";
        for (const auto& concept: concepts)
        {
            auto pos = boyer_moore::search(input.begin(), input.end(), concept.begin(), concept.end(), boyer_moore::withStl);

            if (pos != input.end())
            {
                hasMathces = true;
                std::cout<<concept<<"\t";
            }
        }

        if (not hasMathces)
            std::cout<<"none"<<"\n";

        std::cout<<"\nInput Text:";
    }
}
