#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct WordInfo {
    int ocurrences;
    int order;
    WordInfo(int order) : ocurrences(1), order(order) { }
};

void processWord(const string& word, unordered_map<string, WordInfo>& wordsTable, int& wordCount) {
    if(word.empty()) {
        return;
    }
    wordCount++;
    auto iter = wordsTable.find(word);
    if(iter != wordsTable.end()) {
        iter->second.ocurrences++;
    } else {
        wordsTable.emplace(word, WordInfo(wordCount));
    }
}

bool compareWords(const pair<string, WordInfo>& word1, const pair<string, WordInfo>& word2) {
    if(word1.second.ocurrences != word2.second.ocurrences) {
        return word1.second.ocurrences > word2.second.ocurrences;
    }
    return word1.second.order < word2.second.order;
}

vector<vector<string>> wordCountEngine( const string& document ) {
    unordered_map<string, WordInfo> wordsTable;
    string currentWord = "";
    int wordCount = 0;
    for(char character : document) {
        if(character == ' ') {
            processWord(currentWord, wordsTable, wordCount);
            currentWord = "";
        } else if(character >= 'A' && character <= 'z') {
            currentWord += tolower(character);
        }
    }
    processWord(currentWord, wordsTable, wordCount);
    vector<pair<string, WordInfo>> words;
    for(pair<string, WordInfo> pair : wordsTable) { //O(words)
        words.push_back(pair);
    }
    sort(words.begin(), words.end(), compareWords); //O(words log words)
    vector<vector<string>> answer;
    for(int i = 0; i < words.size(); i++) {
        vector<string> wordWithOcurrence { words.at(i).first,
                                           to_string(words.at(i).second.ocurrences) };
        answer.push_back(wordWithOcurrence);
    }
    return answer;
}