#include "TextJustification_LC68.h"

using std::string;
using std::vector;

vector<string> jr::fullJustify(vector<string>& words, int lineLength) {
    vector<string> lines;
    int currentLineLength = 0;
    string currentLine = "";
    int rangeStart = 0;
    int rangeEnd = 0;
    while(rangeStart < words.size()) {
        currentLineLength = 0;
        for(rangeEnd = rangeStart; rangeEnd < words.size(); rangeEnd++) {
            if (currentLineLength + words.at(rangeEnd).size() > lineLength - (rangeEnd-rangeStart)) {
                break;
            }
            currentLineLength += words.at(rangeEnd).size();
        }
        currentLine = words.at(rangeStart);
        int amountOfWords = rangeEnd - rangeStart;
        int neededSpaces = lineLength - currentLineLength;
        int spacesPerWord = neededSpaces / std::max(amountOfWords-1, 1);
        int extraSpaces = neededSpaces % std::max(amountOfWords-1, 1);
        for(int i = rangeStart+1; i < rangeEnd; i++) {
            if(rangeEnd >= words.size()) {
                currentLine += " ";
            } else {
                currentLine += string(spacesPerWord + ((i-(rangeStart+1)) < extraSpaces), ' ');
            }
            currentLine += words.at(i);
        }
        currentLine += string(lineLength - currentLine.size(), ' ');
        lines.push_back(currentLine);
        rangeStart += (rangeEnd-rangeStart);
    }
    return lines;
}
