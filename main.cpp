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



template <typename T>
void printVector(const vector<T>& arr) {
    for(T s : arr) {
        cout << s << " ";
    }
}

#include <unordered_map>

void groupAnagrams(vector<string>& words) {
    std::unordered_map<string, vector<string>> hashMap;
    for(const string& word : words) {
        string sortedWord = word;
        std::sort(sortedWord.begin(), sortedWord.end());
        auto iter = hashMap.find(sortedWord);
        if(iter != hashMap.end()) {
            iter->second.push_back(word);
        } else {
            vector<string> anagramGroup { word };
            hashMap.emplace(sortedWord, anagramGroup);
        }
    }
    vector<string> answer;
    for(auto pair : hashMap) {
        for(string word : pair.second) {
            answer.push_back(word);
        }
    }
    words = answer;
}


int main(int argc, char* argv[])
{
/*    Point a(10, 10);
    Point b(5, 7);
    Point c = a+b;
    print(c);*/
    vector<string> words {"aba", "aab", "lol"};
    groupAnagrams(words);
    printVector(words);
    cout << "------------------------" << endl;
    words = {"aba", "lol", "oll", "aab", "baa"};
    groupAnagrams(words);
    printVector(words);
    cout << "------------------------" << endl;
    words = {"aba", "lol", "oll", "aab", "baa", "llo", "kakaka", "akakak", "rip", "aaakkk", "pir", "aba", "pri", "kaakak"};
    groupAnagrams(words);
    printVector(words);
    //runTests(argc, argv);
}