#include <string>
#include <vector>

using std::string;
using std::vector;

//Compares anagrams assuming only lowercase english characters in words. Could be adapted for uppercase
//and non-english characters.
bool areAnagrams(const string& word1, const string& word2) {
    if(word1.size() != word2.size()) {
        return false;
    }
    vector<int> alphabet(26, 0);
    int remainingCharacters = 0;
    int arrayIndex = 0;
    for(char character : word1) {
        arrayIndex = character-'a';
        if(alphabet.at(arrayIndex) == 0) {
            remainingCharacters++;
        }
        alphabet.at(arrayIndex)++;
    }
    for(char character : word2) {
        arrayIndex = character-'a';
        alphabet.at(arrayIndex)--;
        if(alphabet.at(arrayIndex) == 0) {
            remainingCharacters--;
        } else if(alphabet.at(arrayIndex) < 0) {
            return false;
        }
    }
    return remainingCharacters == 0;
}

void swap(int i, int j, vector<string>& arr) {
    string temp = arr.at(i);
    arr.at(i) = arr.at(j);
    arr.at(j) = temp;
}

//Time complexity -
//  Worst case: O(n^2 * W) where W is the length of the longest word in words.
//              In the worst case, n^2 anagram checks of O(W) cost are made.
//  Avg. case: Because of this algorithm's similarity to QuickSort, I'd expect the
//             average case to be O(nlogn * W)
// Space complexity: For comparison O(alphabet size). For answer, O(1).
void groupAnagramsMine(vector<string>& words) {
    if(words.size() < 2) {
        return;
    }
    int i = 0;
    int anagramGroupEnd = 1;
    while (i < words.size()-1) {
        anagramGroupEnd = i+1;
        for(int j = i+1; j < words.size(); j++) {
            if(areAnagrams(words.at(i), words.at(j))) {
                swap(j, anagramGroupEnd, words);
                anagramGroupEnd++;
            }
        }
        i = anagramGroupEnd;
    }
}

//Note to myself: This is the first solution I thought of. It took me 44min to fully describe it and implement
//it, a bit too long. It might have been risky in a real interview, as I could've ran out of time before having a
//working solution. That's why thinking of a code efficient solution using the STL