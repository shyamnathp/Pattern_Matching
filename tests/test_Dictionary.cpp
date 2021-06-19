//
// Created by shyamnath on 5/23/21.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include <Dictionary.h>

namespace {
    const std::vector<std::string> concepts = {"Indian",
                                               "Thai",
                                               "Sushi",
                                               "Caribbean",
                                               "Italian", "West Indian",
                                               "Pub",
                                               "East Asian",
                                               "BBQ",
                                               "Chinese",
                                               "Portuguese",
                                               "Spanish",
                                               "French",
                                               "East European"};

    std::vector<std::string> inputs = {
            "I would like some thai food",
            "Where can I find good sushi",
            "Find me a place that does tapas",
            "Which restaurants do East Asian food",
            "Which restaurants do West Indian food",
            "What is the weather like today"};

    const std::vector<std::vector<std::string>> expectedMatches = {{"Thai"}, {"Sushi"}, {"none"}, {"East Asian"}, {"West Indian", "Indian"}, {"none"}};


}// namespace

TEST(DictionaryMatch, WithStl) {
std::vector<std::vector<std::string>> totalMatches;
auto wordMap = Dictionary(concepts);

std::vector<std::string> inputsCopy = inputs;

for (auto &input : inputsCopy) {
std::vector<std::string> matches = wordMap.findWords(input);

if (not matches.empty())
totalMatches.emplace_back(matches);
else
totalMatches.emplace_back(std::vector<std::string>({"none"}));
}

EXPECT_EQ(totalMatches, expectedMatches);
}