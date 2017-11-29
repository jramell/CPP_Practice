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
        x++;
        y++;
    }
    bool operator==(const Point& p2) {
        return x == p2.x && y == p2.y;
    }
    Point operator+(const Point& p2) {
        return Point(x + p2.x, y + p2.y);
    }
    friend Point operator+(int number, const Point& point);
    friend Point operator+(const Point& p1, const Point& p2);
    friend void print(const Point& point);
};

Point operator+ (const Point& p1, const Point& p2)  {
    return Point(p1.x + p2.x, p1.y + p2.y);
}
Point operator+(int number, const Point& point) {
    return Point(point.x + number, point.y + number);
}

void print(const Point& point) {
    cout << "(" << point.x << "," << point.y << ")" << endl;
}

int main(int argc, char* argv[])
{
    Point a(10, 10);
    Point b(5, 7);
    Point c = a+b;
    print(c);
    //runTests(argc, argv);
}