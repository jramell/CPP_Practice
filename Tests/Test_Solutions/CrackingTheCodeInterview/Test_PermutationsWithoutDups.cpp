#include "gtest/gtest.h"

#include "../../../cracking_code_interview/8.8.PermutationsWithoutDups/PermutationsWithoutDups.h"

using std::string;
using std::vector;

using jr::permutationsWithoutDups;

TEST(Test_PermutationsWithoutDups, EmptyWord) {
    string empty = "";
    vector<string> answer(1, "");
    EXPECT_EQ(answer, permutationsWithoutDups(empty));
}

TEST(Test_PermutationsWithoutDups, AllCharactersRepeated) {
    string repeated = "aaa";
    vector<string> answer(1, "aaa");
    EXPECT_EQ(answer, permutationsWithoutDups(repeated));
}

TEST(Test_PermutationsWithoutDups, TwoRepeated) {
    string repeated = "aac";
    vector<string> answer(3, "aac");
    answer.at(1) = "aca";
    answer.at(2) = "caa";
    EXPECT_EQ(answer, permutationsWithoutDups(repeated));
}

TEST(Test_PermutationsWithoutDups, TwoUnique) {
    string unique = "abab";
    vector<string> answer(6, "abab");
    answer.at(1) = "abba";
    answer.at(2) = "aabb";
    answer.at(3) = "baab";
    answer.at(4) = "baba";
    answer.at(5) = "bbaa";
    EXPECT_EQ(answer, permutationsWithoutDups(unique));
}

TEST(Test_PermutationsWithoutDups, AllUnique) {
    string unique = "abc";
    vector<string> answer(6, "abc");
    answer.at(1) = "acb";
    answer.at(2) = "bac";
    answer.at(3) = "bca";
    answer.at(4) = "cab";
    answer.at(5) = "cba";
    EXPECT_EQ(answer, permutationsWithoutDups(unique));
}