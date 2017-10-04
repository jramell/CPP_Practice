#include "gtest/gtest.h"

#include "../../InterviewProblems/BreakIntoWords.h"

using std::string;
using std::unordered_set;

unordered_set<string> dictionary;

void setupDictionary() {
    dictionary.insert("pea");
    dictionary.insert("nut");
    dictionary.insert("butter");
}

TEST(Test_BreakIntoWords, EmptyString) {
    std::string emptyString = "";
    EXPECT_EQ("", breakIntoWords(emptyString, dictionary));
}

TEST(Test_BreakIntoWords, InputWithEmptyDictionary) {
    EXPECT_EQ("", breakIntoWords("fastfisherman", dictionary));
}

TEST(Test_BreakIntoWords, PeanutString) {
    setupDictionary();
    EXPECT_EQ("pea nut", breakIntoWords("peanut", dictionary));
}

TEST(Test_BreakIntoWords, PeanutButterString) {
    setupDictionary();
    EXPECT_EQ("pea nut butter", breakIntoWords("peanutbutter", dictionary));
}

TEST(Test_BreakIntoWords, PeanutButterWithOtherDictionary) {
    unordered_set<string> otherDictionary;
    otherDictionary.insert("peanut");
    otherDictionary.insert("butter");
    EXPECT_EQ("peanut butter", breakIntoWords("peanutbutter", otherDictionary));
}

TEST(Test_BreakIntoWords, FastFisherman) {
    unordered_set<string> otherDictionary;
    otherDictionary.insert("fast");
    otherDictionary.insert("fisher");
    otherDictionary.insert("man");
    EXPECT_EQ("fast fisher man", breakIntoWords("fastfisherman", otherDictionary));
}