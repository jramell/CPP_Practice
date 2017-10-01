#include <string>
#include <vector>
#include "solutions1.h"

using std::string;
using std::vector;

string Solutions1::removeLowercaseEnglishDuplicates(const string& sentence)
{
    string result = "";
    result.reserve(26); //makes appending faster
    int duplicateChecker = 0;
    int currentCharacterZeroBasedIndex = 0;
    int shifted1ToCheckDuplicates = 0;
    bool isDuplicate = false;
    for (string::size_type i = 0; i < sentence.size(); i++)
    {
        currentCharacterZeroBasedIndex = sentence.at(i) - 'a';
        shifted1ToCheckDuplicates = 1 << currentCharacterZeroBasedIndex;
        isDuplicate = (duplicateChecker & shifted1ToCheckDuplicates) > 0;
        if (!isDuplicate)
        {
            result += sentence.at(i);
        }
        duplicateChecker |= shifted1ToCheckDuplicates;
    }
    return result;
}

std::string Solutions1::removeASCIIDuplicates(const string& word)
{
    vector<bool> hasFoundCharacter(256, false);
    string ans = "";
    ans.reserve(256);
    unsigned char currentCharacter = 0;
    for (string::size_type i = 0; i < word.size(); i++)
    {
        currentCharacter = word.at(i);
        if (!hasFoundCharacter.at(currentCharacter))
        {
            ans += currentCharacter;
        }
        hasFoundCharacter.at(currentCharacter) = true;
    }
    return ans;
}

bool Solutions1::areAnagrams(const string& string1, const string& string2)
{
    if (string1.size() != string2.size())
    {
        return false;
    }
    vector<short> characterAmounts(255);
    for (char character : string1)
    {
        characterAmounts.at(character)++;
    }
    for (char character : string2)
    {
        characterAmounts.at(character)--;
    }
    for (short characterAmount : characterAmounts)
    {
        if (characterAmount != 0)
        {
            return false;
        }
    }
    return true;
}