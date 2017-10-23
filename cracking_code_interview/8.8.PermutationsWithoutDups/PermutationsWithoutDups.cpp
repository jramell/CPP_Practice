#include "PermutationsWithoutDups.h"
#include <unordered_set>
using std::string;
using std::vector;
using std::unordered_set;

vector<string> jr::permutationsWithoutDups(string word) {
    vector<string> permutations;
    if (word.size() == 0) {
        permutations.push_back("");
        return permutations;
    }
    unordered_set<char> usedStartpoints;
    for(int i = 0; i < word.size(); i++) {
        char startChar = word.at(i);
        if (usedStartpoints.find(startChar) != usedStartpoints.end()) {
            continue;
        }
        vector<string> otherPerm = permutationsWithoutDups(word.substr(0, i) + word.substr(i+1, word.size()));
        for (string permutation : otherPerm) {
            permutations.push_back(startChar + permutation);
        }
        usedStartpoints.insert(startChar);
    }
    return permutations;
}
