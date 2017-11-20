#include "BreakIntoWords.h"

#include <vector>
#include <iostream>

using std::string;
using std::unordered_set;
using std::vector;
using std::cout;
using std::endl;

string longest(const string &a, const string &b) {
    return (a.size() > b.size()) ? a : b;
}

//define NxN matrix where [i][j] is the best I can do considering all startpoints from 0..i
//and their endpoints from 0..j. So, [i][j] is the best between:
//  1. Best I can do considering i-1 as a startpoint and j as an endpoint
//  2. Best I can do considering i as a startpoint and j-1 as an endpoint
//  3. If it's a word, best I can do up to i-1 as startpoint and j-1 as endpoint + the word formed with characters between i and j
string breakIntoWords(string givenString, const unordered_set<string> &dictionary) {
    vector<vector<string>> wordMatrix(givenString.size(), vector<string>(givenString.size(), ""));
    string buffer = "";
    for (int j = 0; j < givenString.size(); j++) {
        buffer += givenString.at(j);
        if (dictionary.find(buffer) != dictionary.end()) {
            wordMatrix.at(0).at(j) = buffer;
            if (j == givenString.size() - 1) {
                return buffer;
            }
        } else if (j - 1 >= 0) {
            wordMatrix.at(0).at(j) = wordMatrix.at(0).at(j - 1);
        }
    }
    for (int i = 1; i < givenString.size(); i++) {
        buffer = "";
        for (int j = i; j < givenString.size(); j++) {
            buffer += givenString.at(j);
            const string &copyRef = wordMatrix.at(i - 1).at(j - 1);
            string bestPreviousAndICanDo = copyRef;
            if (dictionary.find(buffer) != dictionary.end()) {
                //if the character that came before without taking us into account had a valid string with spaces
                if (bestPreviousAndICanDo != "") {
                    bestPreviousAndICanDo += " "; //add us to it
                }
                bestPreviousAndICanDo += buffer;
            }
            const string &bestPreviousStartpointCanDoWithMe = wordMatrix.at(i - 1).at(j);
            const string &bestCurrentStartpointCanDoWithoutMe = wordMatrix.at(i).at(j - 1);
            string bestSoFar = longest(bestCurrentStartpointCanDoWithoutMe, bestPreviousStartpointCanDoWithMe);
            bestSoFar = longest(bestSoFar, bestPreviousAndICanDo);
            wordMatrix.at(i).at(j) = bestSoFar;
        }
    }
    if (wordMatrix.size() <= 0) {
        return "";
    }
    return wordMatrix.at(wordMatrix.size() - 1).at(wordMatrix.size() - 1);
}

