#include "gtest/gtest.h"
#include "../../../../InterviewProblems/CodingProblems/StringRepetitions/StringRepetitionsToContainSubstring.h"

using jr::numberOfRepetitions;

TEST(Test_StringRepetitionsToContainSubstring, DefaultExample) {
    EXPECT_EQ(3, numberOfRepetitions("abcd", "cdabcdab"));
}

TEST(Test_StringRepetitionsToContainSubstring, SameCharacters1) {
    EXPECT_EQ(1, numberOfRepetitions("a", "a"));
}

TEST(Test_StringRepetitionsToContainSubstring, SameCharacters2) {
    EXPECT_EQ(1, numberOfRepetitions("aakfnoewinfwoeinq", "aakfnoewinfwoeinq"));
}

TEST(Test_StringRepetitionsToContainSubstring, SameCharacters3) {
    EXPECT_EQ(1, numberOfRepetitions("aakfnoewinfwoeindkdkfnvkgewovriuenwocrvojwnfoqdvockxmcokbwefbocibwq",
                                     "aakfnoewinfwoeindkdkfnvkgewovriuenwocrvojwnfoqdvockxmcokbwefbocibwq"));
}

TEST(Test_StringRepetitionsToContainSubstring, CantBeSubstring1) {
    EXPECT_EQ(-1, numberOfRepetitions("a", "b"));
}

TEST(Test_StringRepetitionsToContainSubstring, CantBeSubstring2) {
    EXPECT_EQ(-1, numberOfRepetitions("a", "balfa"));
}

TEST(Test_StringRepetitionsToContainSubstring, CantBeSubstring3) {
    EXPECT_EQ(-1, numberOfRepetitions("abcd", "cdba"));
}

TEST(Test_StringRepetitionsToContainSubstring, CantBeSubstring4) {
    EXPECT_EQ(-1, numberOfRepetitions("abcd", "cdabdcabcd"));
}

TEST(Test_StringRepetitionsToContainSubstring, CantBeSubstring5) {
    EXPECT_EQ(-1, numberOfRepetitions("aeiou", "aeiouaeiouaeioz"));
}

TEST(Test_StringRepetitionsToContainSubstring, CantBeSubstring6) {
    EXPECT_EQ(-1, numberOfRepetitions("aeiou", "eiouaeou"));
}

TEST(Test_StringRepetitionsToContainSubstring, CantBeSubstring7) {
    EXPECT_EQ(-1, numberOfRepetitions("ab", "abba"));
}

TEST(Test_StringRepetitionsToContainSubstring, ValidSubstring1) {
    EXPECT_EQ(1, numberOfRepetitions("aeiou", "aeiou"));
}

TEST(Test_StringRepetitionsToContainSubstring, ValidSubstring2) {
    EXPECT_EQ(2, numberOfRepetitions("aeiou", "aeiouaei"));
}

TEST(Test_StringRepetitionsToContainSubstring, ValidSubstring3) {
    EXPECT_EQ(7, numberOfRepetitions("aeiou", "ouaeiouaeiouaeiouaeiouaeiouaeio"));
}

TEST(Test_StringRepetitionsToContainSubstring, ValidSubstring4) {
    EXPECT_EQ(35, numberOfRepetitions("a", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
}

TEST(Test_StringRepetitionsToContainSubstring, ValidSubstring5) {
    EXPECT_EQ(11, numberOfRepetitions("abcde", "deabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabc"));
}