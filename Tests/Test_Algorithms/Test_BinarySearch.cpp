#include "gtest/gtest.h"
#include "../../Algorithms/Search.h"

class classWithInvertedComparison { //the lower the data in the object, the "higher" it is
    int data;
public:
    classWithInvertedComparison(int data) : data(data) { }
    void setData(int newData) {
        data = newData;
    }
    friend bool operator> (const classWithInvertedComparison& c1, const classWithInvertedComparison& c2);
    friend bool operator< (const classWithInvertedComparison& c1, const classWithInvertedComparison& c2);
};

bool operator> (const classWithInvertedComparison& c1, const classWithInvertedComparison& c2) {
    return c2.data > c1.data;
}
bool operator< (const classWithInvertedComparison& c1, const classWithInvertedComparison& c2) {
    return c2.data < c1.data;
}

void setupVector(std::vector<int>& vector) {
    vector.push_back(12);
    vector.push_back(14);
    vector.push_back(21);
    vector.push_back(22);
    vector.push_back(30);
}

TEST(Test_BinarySearch, EmptyVector) {
    std::vector<int> emptyVector;
    EXPECT_EQ(0, Search::BinarySearch(10, emptyVector));
}

TEST(Test_BinarySearch, InsertBeforeOneElementVector) {
    std::vector<int> sizeOneVector;
    sizeOneVector.push_back(12);
    EXPECT_EQ(0, Search::BinarySearch(10, sizeOneVector));
}

TEST(Test_BinarySearch, InsertAfterOneElementVector) {
    std::vector<int> sizeOneVector;
    sizeOneVector.push_back(12);
    EXPECT_EQ(1, Search::BinarySearch(15, sizeOneVector));
}

TEST(Test_BinarySearch, ExistingElement) {
    std::vector<int> vector;
    setupVector(vector);
    EXPECT_EQ(2, Search::BinarySearch(21, vector));
}

TEST(Test_BinarySearch, OtherClassExistingElement) {
    std::vector<const char*> vector;
    vector.push_back("Aa");
    vector.push_back("B");
    vector.push_back("Z");
    EXPECT_EQ(1, Search::BinarySearch("B", vector));
}

TEST(Test_BinarySearch, InsertLast) {
    std::vector<const char*> vector;
    vector.push_back("Aa");
    vector.push_back("Bb");
    vector.push_back("Cc");
    vector.push_back("Ee");
    EXPECT_EQ(4, Search::BinarySearch("W", vector));
}

TEST(Test_BinarySearch, InsertMiddle) {
    std::vector<float> vector;
    vector.push_back(1.5f);
    vector.push_back(2.5f);
    vector.push_back(3.5f);
    vector.push_back(5.9f);
    EXPECT_EQ(3, Search::BinarySearch(5.7f, vector));
}



TEST(Test_BinarySearch, InsertFirst) {
    std::vector<classWithInvertedComparison> vector;
    classWithInvertedComparison object(20);
    vector.push_back(object);
    object.setData(14);
    vector.push_back(object);
    object.setData(11);
    vector.push_back(object);
    object.setData(9);
    vector.push_back(object);
    object.setData(50);
    EXPECT_EQ(0, Search::BinarySearch(object, vector));
}