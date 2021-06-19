//
// Created by shyamnath on 5/22/21.
//

#include <sstream>
#include <iterator>
#include <set>

#include <Dictionary.h>
#include <PatternMatchers.h>

Dictionary::Dictionary(const std::vector<std::string> &concepts)
{
    for (const auto &concept : concepts) {
        this->wordMap[concept[0]].emplace_back(concept);
    }
}

std::vector<std::string> Dictionary::findWords(std::string& input) {

    bool hasMatches = false;
    std::vector<std::string> matchers;

    std::istringstream iss(input);
    std::vector<std::string> inputWords((std::istream_iterator<std::string>(iss)),
                                        std::istream_iterator<std::string>());

    std::set<char> lettersSeen;
    for (const auto &inputWord : inputWords) {
        char key = std::toupper(inputWord[0]); //assumption all concepts begin with capital letters

        //since all words that start with key are checked, we neednot check again when another word starts with key
        if(lettersSeen.find(key) == lettersSeen.end())
            lettersSeen.emplace(key);
        else
            continue;

        if (auto it = wordMap.find(key);it != wordMap.end()) {
            for(const auto& word: it->second)
            {
                //pattern match with all the concepts with first letter 'key'
                auto pos = boyer_moore::search(input.begin(), input.end(), word.begin(), word.end(), boyer_moore::withStl);
                if (pos != input.end()) {
                    hasMatches = true;
                    matchers.emplace_back(word);
                }
            }
        }
    }

    if (!hasMatches)
        matchers.emplace_back("none");

    return matchers;
}