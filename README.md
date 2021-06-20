# Pattern Matcher

Suppose you are given a list of context words. Let the list be:  

a= ["Indian", "Greek", "German"]  

and the user inputs a sentence   

b= "Although I am Indian, I like German food better"

Then the algorithm would return the context words of 'a' present in 'b'. In the above example, the output would be

output = ["Indian", "German"]

The objective behind this project was to play around with various aspects of C++ mentioned below:
1. [std::search](https://en.cppreference.com/w/cpp/algorithm/search) with boyer_moore_search seacher.
2. create a custom boyer moore searcher.
3. Implement both searches, using almost the same interface as stl std:search.
4. Implement both the boyer_moore searcher generically with templates.   
5. Use tag dispatching to differentiate both the custom boyer_moore searcher and the stl std:search base boyer moore searcher.
6. Writing tests in google test instead of catch2.
7. Use CMake FetchContent instead of Conan.   
8. Benchmark all the approaches.
9. Improve the approach with std::search by creating a dictionary.
10. Benchmark all three approaches with respect to Aho Corasick algorithm.

## How to run?

### Build
In the repository, do the following:
1. mkdir build && cd build
2. cmake .. -DBUILD_TESTING=ON -DBUILD_BENCHMARKS=ON
3. make 

Run the executables as:  

	./PatternMatching  
	./PatternMatchingStl  
	./DictionaryMatch  
	./tests  
	./benchmark
	./Aho_Corasick
	
## Inputs and Outpus

<u>Inputs</u>:  
    1. The concepts are read from the file concepts.txt in the project folder. Here, one can add more concepts and delete existing.
    2. The input text is read from the console.

<u>Ouputs</u>:
Outputs for each input are displayed in the console


## Approaches

All the apporaches convert the concepts to lowerCase and then proceed to do pattern matching in a case insensitive manner.

* Pattern Matching - with Stl  

In this approach, we iterate through each of the 'concepts' to see if they exist in the 'input'. This was implemented completely using Stl algorithms. Since, the algorithm should be case insensitive, special consideration was given to changing the 'input' to lower case. We use Boyer Moore Search for the pattern matching.  

* Pattern Matching - Without Stl  

In this algorithm, I implemented a custom Bayer Moore Search which converts each character in the "Input" to lowercase while comparing. This does not convert the input to lowercase in a separate step.  

* Dictionary Match  

The main problem with the above two apporaches is that as the numbers of concepts grows, they becomes terribly slow. In this approach, I create a dictionary based on the first letter of each concept. Here is the psuedo code.

1. Create a dictionary with key as the first letter, mapping the first letter to all the ‘concepts’ that has the same first letter.  
Example:  
*concepts*: Indian, West Indian, Indonesian  
*dictionary* = {‘i’: {‘indian’, ‘indonesian’}, ‘w’:{‘west indian’}}

2. For each word in ‘input’:
    • find first letter of word
    • fetch words beginning with letter from map
    • Check if fetched words are present in the input using PatternMatching-WithStl
    •  If word is present:
        		add word to an array
3. If array.empty()
	add “none” to array
	
* [Aho Corasick Algorithm](https://github.com/cjgdev/aho_corasick.git)

 Used a git submodule.

## Tests

Tests, using google test for all the three primary approaches can be found in the 'tests' folder.  

## Benchmarks

A benchmark that compares the primary three approaches with Aho_Corasick can be found in 'benchmark' folder.
 


	