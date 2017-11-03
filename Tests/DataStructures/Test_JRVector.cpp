#include "gtest/gtest.h"

#include "../../DataStructures/JRVector/JRVector.h"

using std::string;

TEST(Test_JRVector, Insertion1) {
    JRVector<int> vector;
    ASSERT_NO_THROW(vector.push_back(5));
}

TEST(Test_JRVector, AtWhenEmpty1) {
    JRVector<int> vector;
    ASSERT_THROW(vector.at(0), std::out_of_range);
}

TEST(Test_JRVector, AtWhenEmpty2) {
    JRVector<int> vector;
    ASSERT_THROW(vector.at(20), std::out_of_range);
}

TEST(Test_JRVector, AtWithOneElement) {
    JRVector<int> vector;
    vector.push_back(10);
    ASSERT_EQ(10, vector.at(0));
    ASSERT_THROW(vector.at(1), std::out_of_range);
}

TEST(Test_JRVector, Resizing0) {
    JRVector<int> vector;
    vector.resize(0);
    ASSERT_EQ(0, vector.capacity());
}

TEST(Test_JRVector, Resizing1) {
    JRVector<int> vector;
    vector.resize(1);
    ASSERT_EQ(1, vector.capacity());
}

TEST(Test_JRVector, ResizingTo100) {
    JRVector<int> vector;
    vector.resize(100);
    ASSERT_EQ(100, vector.capacity());
}

TEST(Test_JRVector, InsertionNoResizing) {
    JRVector<int> vector;
    for(int i = 1; i < 10; i++) {
        ASSERT_NO_THROW(vector.push_back(i));
    }
}

TEST(Test_JRVector, EnlargingWithElements) {
    JRVector<int> vector;
    for(int i = 0; i < 9; i++) {
        vector.push_back(i);
    }
    vector.resize(100);
    for(int i = 0; i < 9; i++) {
        EXPECT_EQ(i, vector.at(i));
    }
}

TEST(Test_JRVector, ShrinkingWithElements) {
    JRVector<int> vector;
    for(int i = 0; i < 20; i++) {
        vector.push_back(i);
    }
    vector.resize(10);
    for(int i = 0; i < 9; i++) {
        EXPECT_EQ(i, vector.at(i));
    }
}

TEST(Test_JRVector, InsertionWithResizing) {
    JRVector<int> vector;
    for(int i = 0; i < 30; i++) {
        ASSERT_NO_THROW(vector.push_back(i));
    }
    for(int i = 0; i < 30; i++) {
       EXPECT_EQ(i, vector.at(i));
    }
}

TEST(Test_JRVector, SizeWhenEmpty) {
    JRVector<int> vector;
    ASSERT_EQ(0, vector.size());
}

TEST(Test_JRVector, EmptyFunctionWhenEmpty) {
    JRVector<int> vector;
    EXPECT_EQ(true, vector.empty());
}

TEST(Test_JRVector, EmptyFunctionWhenNotEmpty) {
    JRVector<int> vector;
    vector.push_back(102);
    EXPECT_EQ(false, vector.empty());
}

TEST(Test_JRVector, SizeAtOneInsertion) {
    JRVector<int> vector;
    vector.push_back(1);
    EXPECT_EQ(1, vector.size());
}

TEST(Test_JRVector, SizeWith50Insertions) {
    JRVector<int> vector;
    for(int i = 0; i < 50; i++) {
        vector.push_back(i);
    }
    EXPECT_EQ(50, vector.size());
}

TEST(Test_JRVector, SizeWith2000Insertions) {
    JRVector<int> vector;
    for(int i = 0; i < 2000; i++) {
        vector.push_back(i);
    }
    EXPECT_EQ(2000, vector.size());
}

TEST(Test_JRVector, ClearWhenEmpty) {
    JRVector<int> vector;
    ASSERT_NO_THROW(vector.clear());
    ASSERT_EQ(0, vector.size());
}

TEST(Test_JRVector, ClearWhenNotEmpty) {
    JRVector<int> vector;
    vector.push_back(6);
    vector.push_back(11);
    ASSERT_NO_THROW(vector.clear());
    ASSERT_EQ(0, vector.size());
}
