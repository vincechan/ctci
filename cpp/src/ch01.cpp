#include "third_party/catch.hpp"

#include <string>
#include <unordered_set>
#include <algorithm>

/**
 * determine if a given string has all unique characters
 */
bool isUnique(const std::string& input) {
    std::unordered_set<char> set;
    for (auto character : input) {
        if (set.find(character) != set.end()) {
            return false;
        }
        set.insert(character);
    }
    return true;
}

/**
 * determine if a given string is all unique characters
 * new requirement: do not use additional data structure
 */
bool isUniqueNoDataStructure(std::string input) {
    if (input.size() <= 1) {
        return true;
    }

    // sort the input string in place
    std::sort(input.begin(), input.end());
    
    // iterate the string, if the current char is the same as last char, it's not unique
    char last = input[0];
    for (size_t i = 1; i < input.size(); i++) {
        if (input[i] == last) {
            return false;
        }
        last = input[i];
    }
    return true;
}

TEST_CASE("isUnique") {
    REQUIRE(isUnique("abcde"));
    REQUIRE(isUnique("aabcde") == false);
}

TEST_CASE("isUniqueNoDataStructure") {
    REQUIRE(isUniqueNoDataStructure("abcde"));
    REQUIRE(isUniqueNoDataStructure("aabcde") == false);
}
