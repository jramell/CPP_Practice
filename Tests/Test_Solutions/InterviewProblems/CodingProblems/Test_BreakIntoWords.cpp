#include "gtest/gtest.h"

#include "../../../../InterviewProblems/CodingProblems/BreakIntoWords/BreakIntoWords.h"

using std::string;
using std::unordered_set;

unordered_set<string> dictionary;

void setupDictionary() {
    dictionary.insert("pea");
    dictionary.insert("nut");
    dictionary.insert("butter");
}

TEST(Test_BreakIntoWords, InputWithEmptyDictionary) {
    EXPECT_EQ("", breakIntoWords("fastfisherman", dictionary));
}

TEST(Test_BreakIntoWords, EmptyString) {
    setupDictionary();
    std::string emptyString = "";
    EXPECT_EQ("", breakIntoWords(emptyString, dictionary));
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

TEST(Test_BreakIntoWords, FastFishermanWithAInDictionary) {
    unordered_set<string> otherDictionary;
    otherDictionary.insert("fast");
    otherDictionary.insert("fisher");
    otherDictionary.insert("man");
    otherDictionary.insert("a");
    //choosing fast fisher man still maximizes broken string size
    EXPECT_EQ("fast fisher man", breakIntoWords("fastfisherman", otherDictionary));
}

TEST(Test_BreakIntoWords, LongStringWithMediumDictionary) {
    unordered_set<string> otherDictionary;
    otherDictionary.insert("the");
    otherDictionary.insert("great");
    otherDictionary.insert("rather");
    otherDictionary.insert("fast");
    otherDictionary.insert("fisher");
    otherDictionary.insert("man");
    otherDictionary.insert("a");
    otherDictionary.insert("and");
    otherDictionary.insert("fish");
    otherDictionary.insert("fisherman");
    otherDictionary.insert("eat");
    otherDictionary.insert("who");
    otherDictionary.insert("eats");
    otherDictionary.insert("fishes");
    otherDictionary.insert("candy");
    otherDictionary.insert("fishing");
    otherDictionary.insert("boat");
    otherDictionary.insert("woman");
    otherDictionary.insert("greatness");
    otherDictionary.insert("greater");
    otherDictionary.insert("their");
    otherDictionary.insert("eating");
    otherDictionary.insert("fill");
    otherDictionary.insert("greatest");
    otherDictionary.insert("whom");
    EXPECT_EQ("the rather great fisher man who eats fishes", breakIntoWords("therathergreatfishermanwhoeatsfishes", otherDictionary));
}