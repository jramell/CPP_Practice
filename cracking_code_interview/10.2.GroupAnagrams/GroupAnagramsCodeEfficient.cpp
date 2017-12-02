#include <string>
#include <vector>
#include <algorithm>

bool anagramComp(const std::string& word1, const std::string& word2) {
    std::string word1Copy = word1;
    std::string word2Copy = word2;
    sort(word1Copy.begin(), word1Copy.end());
    sort(word2Copy.begin(), word2Copy.end());
    return word1Copy < word2Copy;
}

//Really code efficient solution.
//Time complexity = O(nlogn * wlogw) where w is the longest word in words and n is the amount of words
//Space complexity = O(w) because of comparison function, but O(1) for answer.
//Note for myself: I implemented this based on CTCI's solution suggestion. It's not the best solution, but its
//code efficiency means it would be good for a first code sample at an interview.
void groupAnagramsCodeEfficient(std::vector<std::string>& words) {
    sort(words.begin(), words.end(), anagramComp);
}