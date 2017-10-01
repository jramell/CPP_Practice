#include <iostream>
#include "cracking_code_interview/solutions1.h"
#include "DataStructures/JRLinkedList/JRLinkedList.h"
#include "DataStructures/JRStack/Stack.h"
#include "DataStructures/JRDoublyLinkedList/DoublyLinkedList.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <forward_list>
using std::forward_list;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

void runTests(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
}


struct BinaryTreeNode {
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    int data;
    BinaryTreeNode(int data) : data(data), left(nullptr), right(nullptr) { }
};

void addToLevelList(const BinaryTreeNode& node, int level,
                    vector<forward_list<BinaryTreeNode>>& nodesByLevel) {
}

vector<forward_list<BinaryTreeNode>> nodesByLevel(BinaryTreeNode root)
{
    vector< forward_list<BinaryTreeNode> > nodesByLevel;
    addToLevelList(root, 0, nodesByLevel);
    return nodesByLevel;
}

int main(int argc, char* argv[])
{
    runTests(argc, argv);
}