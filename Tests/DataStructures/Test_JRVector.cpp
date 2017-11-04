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

TEST(Test_JRVector, StringVectorInitialization) {
    ASSERT_NO_THROW(JRVector<string> vector);
}

TEST(Test_JRVector, StringVectorInsertion) {
    JRVector<string> vector;
    string helloWorld = "Hello, World";
    ASSERT_NO_THROW(vector.push_back(helloWorld));
    ASSERT_EQ(1, vector.size());
}

TEST(Test_JRVector, StringVectorAt) {
    JRVector<string> vector;
    string helloWorld = "Hello, World";
    vector.push_back(helloWorld);
    ASSERT_EQ(helloWorld, vector.at(0));
}

TEST(Test_JRVector, ShrinkWithStrings) {
    JRVector<string> vector;
    for(int i = 0; i < 50; i++) {
        ASSERT_NO_THROW(vector.push_back(std::to_string(i)));
    }
    ASSERT_NO_THROW(vector.resize(25));
    for(int i = 0; i < 25; i++) {
        ASSERT_EQ(std::to_string(i), vector.at(i));
    }
}

TEST(Test_JRVector, EraseEmpty) {
    JRVector<string> vector;
    ASSERT_THROW(vector.erase(0), std::out_of_range);
}

TEST(Test_JRVector, EraseOnlyExistent) {
    JRVector<string> vector;
    vector.push_back("HAIL2U");
    vector.erase(0);
    ASSERT_EQ(0, vector.size());
    ASSERT_THROW(vector.at(0), std::out_of_range);
}

TEST(Test_JRVector, EraseOne) {
    JRVector<string> vector;
    for(int i = 0; i < 10; i++) {
        vector.push_back(std::to_string(i));
    }
    vector.erase(0);
    ASSERT_EQ(9, vector.size());
    ASSERT_EQ("1", vector.at(0));
}

TEST(Test_JRVector, ConsecutiveErases) {
    JRVector<string> vector;
    for(int i = 0; i < 10; i++) {
        vector.push_back(std::to_string(i));
    }
    for(int i = 0; i < 3; i++) {
        ASSERT_NO_THROW(vector.erase(0));
    }
    ASSERT_EQ(7, vector.size());
    ASSERT_EQ("3", vector.at(0));
}

TEST(Test_JRVector, RangeEraseWhenEmpty) {
    JRVector<string> vector;
    ASSERT_THROW(vector.erase(0, 1), std::out_of_range);
}

TEST(Test_JRVector, RangeEraseOnInvalidRange) {
    JRVector<string> vector;
    ASSERT_THROW(vector.erase(1, 0), std::out_of_range);
}

TEST(Test_JRVector, RangeEraseOnOneElement) {
    JRVector<string> vector;
    vector.push_back("yare yare daze");
    ASSERT_NO_THROW(vector.erase(0, 1));
    ASSERT_EQ(0, vector.size());
}

TEST(Test_JRVector, RangeErase2Elements) {
    JRVector<char> vector;
    for(int i = 0; i < 10; i++) {
        vector.push_back(i);
    }
    ASSERT_NO_THROW(vector.erase(0, 2));
    ASSERT_EQ(8, vector.size());
    for(int i = 0; i < 8; i++) {
        ASSERT_EQ(i+2, vector.at(i));
    }
}

TEST(Test_JRVector, RangeEraseAllElements) {
    JRVector<char> vector;
    for(int i = 0; i < 10; i++) {
        vector.push_back(i);
    }
    ASSERT_NO_THROW(vector.erase(0, 20));
    ASSERT_EQ(0, vector.size());
}

TEST(Test_JRVector, RangeEraseAllElementsFromIndex3) {
    JRVector<char> vector;
    for(int i = 0; i < 10; i++) {
        vector.push_back(i);
    }
    ASSERT_NO_THROW(vector.erase(3, vector.size()));
    ASSERT_EQ(3, vector.size());
    for(int i = 0; i < 3; i++) {
        ASSERT_EQ(i, vector.at(i));
    }
}

TEST(Test_JRVector, RangeEraseMiddleRange) {
    JRVector<short> vector;
    for(int i = 0; i < 20; i++) {
        vector.push_back(i);
    }
    ASSERT_NO_THROW(vector.erase(5, 10));
    ASSERT_EQ(15, vector.size());
    for(int i = 0; i < 5; i++) {
        ASSERT_EQ(i, vector.at(i));
    }
    for(int i = 5; i < vector.size(); i++) {
        ASSERT_EQ(i+5, vector.at(i));
    }
}

TEST(Test_JRVector, RangeErase100Elements) {
    JRVector<short> vector;
    for(int i = 0; i < 101; i++) {
        vector.push_back(i);
    }
    ASSERT_NO_THROW(vector.erase(0, 100));
    ASSERT_EQ(1, vector.size());
    ASSERT_EQ(100, vector.at(0));
}