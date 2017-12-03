#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;

//Time complexity: O(n * wlogw) where n is the number of words and W the length of the longest word in words.
//Space complexity: O(n)
void groupAnagramsOptimal(vector<string>& words) {
    std::unordered_map<string, vector<string>> hashMap;
    for(const string& word : words) {
        string sortedWord = word;
        std::sort(sortedWord.begin(), sortedWord.end());
        auto iter = hashMap.find(sortedWord);
        if(iter != hashMap.end()) {
            iter->second.push_back(word);
        } else {
            vector<string> anagramGroup { word };
            hashMap.emplace(sortedWord, anagramGroup);
        }
    }
    vector<string> answer;
    for(auto pair : hashMap) {
        for(string word : pair.second) {
            answer.push_back(word);
        }
    }
    words = answer;
}