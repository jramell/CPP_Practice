#include "gtest/gtest.h"

#include "../../../../InterviewProblems/SumOfSubarrays/SumOfSubarrays.h"

using jr::sumOfContiguousSubarrays;
using std::vector;

TEST(Test_SumOfContiguousSubarrays, EmptyArray) {
    vector<int> empty;
    EXPECT_EQ(0, sumOfContiguousSubarrays(empty));
}

TEST(Test_SumOfContiguousSubarrays, Example) {
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(7);
    EXPECT_EQ(36, sumOfContiguousSubarrays(numbers));
}

TEST(Test_SumOfContiguousSubarrays, Example2) {
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(4);
    numbers.push_back(7);
    numbers.push_back(3);
    EXPECT_EQ(82, sumOfContiguousSubarrays(numbers));
}