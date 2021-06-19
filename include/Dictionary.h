//
// Created by shyamnath on 5/22/21.
//

#ifndef PATTERN_MATCHING_DICTIONARY_H
#define PATTERN_MATCHING_DICTIONARY_H

#include <unordered_map>
#include <vector>
#include <string>

typedef std::unordered_map<char, std::vector<std::string>> dictionary;

class Dictionary {
    public:
        explicit Dictionary(const std::vector<std::string> &concepts);
        Dictionary() = delete;
        std::vector<std::string> findWords(std::string &input);

    private:
        dictionary wordMap;
    };

#endif//PATTERN_MATCHING_DICTIONARY_H
