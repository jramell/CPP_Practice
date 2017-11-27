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

int main(int argc, char* argv[])
{
    runTests(argc, argv);
}