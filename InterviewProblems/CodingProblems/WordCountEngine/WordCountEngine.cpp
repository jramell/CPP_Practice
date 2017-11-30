/**
 * Solution Pramp problem whose original statement is at: https://www.pramp.com/challenge/W5EJq2Jld3t2ny9jyZXG
 *
 * Word Count Engine
 * Implement a document scanning function wordCountEngine, which receives a string document and returns a list of all
 * unique words in it and their number of occurrences, sorted by the number of occurrences in a descending order, then
 * by the order of tokens in the sentence. Assume that all letters are in english alphabet. You function should be
 * case-insensitive, so for instance, the words “Perfect” and “perfect” should be considered the same word.
 *
 * The engine should strip out punctuation (even in the middle of a word) and use whitespaces to separate words.
 * Analyze the time and space complexities of your solution. Try to optimize for time while keeping a polynomial space complexity.

    Examples:

    input:  document = "Practice makes perfect. you'll only
                        get Perfect by practice. just practice!"

    output: [ ["practice", "3"], ["perfect", "2"],
              ["makes", "1"], ["get", "1"], ["by", "1"],
              ["just", "1"], ["youll", "1"], ["only", "1"] ]
    Important: please convert the occurrence integers in the output list to strings (e.g. "3" instead of 3). We ask this because in compiled languages such as C#, Java, C++, C etc., it’s not straightforward to create mixed-type arrays (as it is, for instance, in scripted languages like JavaScript, Python, Ruby etc.). The expected output will simply be an array of string arrays.

    Constraints:

    [time limit] 5000ms
    [input] string document
    [output] array.array.string
 */

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