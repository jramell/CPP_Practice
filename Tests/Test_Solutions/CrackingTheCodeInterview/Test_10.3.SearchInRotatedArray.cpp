#include "gtest/gtest.h"

#include "../../../cracking_code_interview/10.3.SearchInRotatedArray/10.3.SearchInRotatedArray.h"

using std::vector;

TEST(Test_CTCI_SearchInRotatedArray, Example) {
    vector<int> testcase {15, 16, 19, 20, 25, 1, 3,4,5,7,10, 14};
    EXPECT_EQ(8, jr::searchInRotatedArray(5, testcase));
}

TEST(Test_CTCI_SearchInRotatedArray, UnsortedLeft) {
    vector<int> testcase {20, 26, 5, 7, 9, 10};
    EXPECT_EQ(2, jr::searchInRotatedArray(5, testcase));
}

TEST(Test_CTCI_SearchInRotatedArray, TargetAtMiddle) {
    vector<int> testcase {20, 26, 5, 7, 9, 10};
    EXPECT_EQ(3, jr::searchInRotatedArray(7, testcase));
}

TEST(Test_CTCI_SearchInRotatedArray, OneSideDuplicates) {
    vector<int> testcase {2, 2, 2, 3, 32};
    EXPECT_EQ(4, jr::searchInRotatedArray(32, testcase));
}

TEST(Test_CTCI_SearchInRotatedArray, TwoSidesDuplicates1) {
    vector<int> testcase {2, 2, 2, 3, 9, 2, 2};
    EXPECT_EQ(4, jr::searchInRotatedArray(9, testcase));
}

TEST(Test_CTCI_SearchInRotatedArray, TwoSidesDuplicates2) {
    vector<int> testcase {2, 2, 2, 3, 4, 5, 6, 8, 9, 2};
    EXPECT_EQ(7, jr::searchInRotatedArray(8, testcase));
}
