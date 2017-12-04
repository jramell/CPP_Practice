#include <iostream>
#include <random>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <forward_list>
#include <unordered_set>
#include <bitset>

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

#include "DataStructures/JRHashTable/HashTable.h"
#include "DataStructures/JRLinkedList/JRLinkedList.h"

struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) { }
    Point& operator++() {
        ++x;
        ++y;
        return *this;
    }
    Point operator++(int) {
        Point temp = *this;
        x++;
        y++;
        return temp;
    }
    bool operator==(const Point& p2) {
        return x == p2.x && y == p2.y;
    }
    Point operator+(const Point& p2) {
        return Point(x + p2.x, y + p2.y);
    }
    friend Point operator+(int number, const Point& point);
    friend Point operator+(const Point& p1, const Point& p2);
};

Point operator+ (const Point& p1, const Point& p2)  {
    return Point(p1.x + p2.x, p1.y + p2.y);
}
Point operator+(int number, const Point& point) {
    return Point(point.x + number, point.y + number);
}

void print(const Point& p) {
    cout << "(" << p.x << "," << p.y << ")" << endl;
}

int main(int argc, char* argv[])
{
/*    cout << "lol" << endl;
    Point a(10, 10);
    print(a++);
    print(++a);*/
/*    UniqueBucket<int, int> bucket;
    std::pair<int, int> justInserted(55, 100);
    auto result = bucket.insert(justInserted);
    std::pair<int, int>& insertedRef = result.first;
    int answer = bucket.at(55);
    cout << insertedRef.second << endl;
    cout << answer << endl;*/
   runTests(argc, argv);
}