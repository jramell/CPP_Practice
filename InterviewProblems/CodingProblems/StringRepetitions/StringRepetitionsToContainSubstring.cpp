#include "StringRepetitionsToContainSubstring.h"


int jr::numberOfRepetitions(std::string A, std::string B) {
    int i = 0;
    int j = 0;
    while(B.at(0) != A.at(j)) {
        j++;
        if (j >= A.size()) {
            return -1; //first character of B never found in A
        }
    }
    int numberOfRepetitions = 0;
    while(i < B.size()) {
        if (A.at(j) != B.at(i)) {
            return -1; //sequences don't match, B can't be a substring of A
        }
        i++;
        j++;
        if (j >= A.size()) {
            numberOfRepetitions++;
            j = 0;
        }
    }
    if (j != 0) {
        numberOfRepetitions++; //for cases where the ending of B doesn't match that of A
    }
    return numberOfRepetitions;
}