#include <iostream>
#include <random>
#include "InterviewProblems/BreakIntoWords.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <forward_list>
#include <unordered_set>
using std::forward_list;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::unordered_set;

void runTests(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
}

int main(int argc, char* argv[])
{
/*    cout << "START" << endl;
    unordered_set<string> dictionary;
    dictionary.insert("pea");
    dictionary.insert("nut");
    dictionary.insert("butter");
    string ans = breakIntoWords("peanutbutter", dictionary);
    cout << ans << endl;
    cout << "END" << endl;*/
    runTests(argc, argv);
}