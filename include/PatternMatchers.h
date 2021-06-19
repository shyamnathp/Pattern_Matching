//
// Created by shyamnath on 5/22/21.
//

#ifndef PATTERN_MATCHING_PATTERNMATCHERS_H
#define PATTERN_MATCHING_PATTERNMATCHERS_H

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

namespace boyer_moore {
    static struct WithStl {
    } withStl;
    static struct WithoutStl {
    } withoutStl;

    #define NO_OF_CHARS 256

    template<typename ForwardIt1>
    void badCharPosition(ForwardIt1 first, ForwardIt1 last, int size,
                                   int badchar[NO_OF_CHARS]) {
        for (int i = 0; i < NO_OF_CHARS; i++)
            badchar[i] = -1;

        for (int i = 0; i < size; i++)
            badchar[(int) *(first + i)] = i;
    }

    //boyer moore searcher without stl
    template<class ForwardIt1, class ForwardIt2>
    ForwardIt1 search(ForwardIt1 first, ForwardIt1 last,
                                ForwardIt2 s_first, ForwardIt2 s_last, WithoutStl) {
        int lenPat = std::distance<ForwardIt2>(s_first, s_last);
        int lenTxt = std::distance<ForwardIt2>(first, last);

        int badchar[NO_OF_CHARS];
        badCharPosition(first, last, lenTxt, badchar);

        int shift = 0;
        while (shift <= (lenTxt - lenPat)) {
            int j = lenPat - 1;

            //comparisons after making lower case
            while (j >= 0 && std::tolower(*(s_first + j)) == std::tolower(*(first + shift + j)))
                j--;

            if (j < 0) {
                //pattern is found
                return first + shift;
            } else
                shift += std::max(1, j - badchar[*(first + shift + j)]);
        }

        return last;
    }


    //boyer moore searcher using stl function
    template<class ForwardIt1, class ForwardIt2>
    ForwardIt1 search(ForwardIt1 first, ForwardIt1 last,
                      ForwardIt2 s_first, ForwardIt2 s_last, WithStl) {
        std::transform(first, last, first, [](unsigned char c) -> unsigned char { return std::tolower(c); });
        std::string conceptLower;
        std::transform(s_first, s_last, std::back_inserter(conceptLower), [](unsigned char c) -> unsigned char { return std::tolower(c); });
        return std::search(first, last, std::boyer_moore_searcher(conceptLower.begin(), conceptLower.end()));
    }

}// namespace boyer_moore

#endif//PATTERN_MATCHING_PATTERNMATCHERS_H
