//
// Created by shyamnath on 5/22/21.
//
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include <PatternMatchers.h>

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

    const std::vector<std::vector<std::string>> expectedMatches = {{"Thai"}, {"Sushi"}, {"none"}, {"East Asian"}, {"Indian", "West Indian"}, {"none"}};


}// namespace


TEST(BoyerMooreTest, WithStl) {
    std::vector<std::vector<std::string>> totalMatches;
    for (auto &input : inputs) {
        std::vector<std::string> matches;
        for (const auto &concept : concepts) {
            auto pos = boyer_moore::search(input.begin(), input.end(), concept.begin(), concept.end(), boyer_moore::withStl);

            if (pos != input.end())
                matches.emplace_back(concept);
        }
        if (not matches.empty())
            totalMatches.emplace_back(matches);
        else
            totalMatches.emplace_back(std::vector<std::string>({"none"}));
    }

    EXPECT_EQ(totalMatches, expectedMatches);
}

TEST(BoyerMooreTest, WithoutStl) {
    std::vector<std::vector<std::string>> totalMatches;
    for (auto &input : inputs) {
        std::vector<std::string> matches;
        for (const auto &concept : concepts) {
            auto pos = boyer_moore::search(input.begin(), input.end(), concept.begin(), concept.end(), boyer_moore::withoutStl);

            if (pos != input.end())
                matches.emplace_back(concept);
        }
        if (not matches.empty())
            totalMatches.emplace_back(matches);
        else
            totalMatches.emplace_back(std::vector<std::string>({"none"}));
    }

    EXPECT_EQ(totalMatches, expectedMatches);
}
