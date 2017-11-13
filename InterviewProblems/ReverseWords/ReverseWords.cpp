#include "ReverseWords.h"
void jr::reverseWords(std::string& sentence) {
    std::string answer = "";
    for(int i = sentence.size() - 1; i > 0; i--) {
        if(sentence.at(i) == ' ') {
            if(!answer.empty()) {
                answer += " ";
            }
            for(int j = i+1; j < sentence.size() && sentence.at(j) != ' '; j++) {
                answer += sentence.at(j);
            }
        }
    }
    if(!answer.empty()) {
        answer += " ";
    }
    for(int i = 0; i < sentence.size() && sentence.at(i) != ' '; i++) {
        answer += sentence.at(i);
    }
    sentence = answer;
}
