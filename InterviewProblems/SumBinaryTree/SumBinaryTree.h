#ifndef SERGIOTEST_SUMBINARYTREE_H
#define SERGIOTEST_SUMBINARYTREE_H

#include <stack>
#include <unordered_set>

namespace jr {
    /**
     * Contains two solutions to: https://www.interviewbit.com/problems/2sum-binary-tree
     *
     * Given a binary search tree T, where each node contains a positive integer, and an integer K, you
     * have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.
     *
     * Return 1 to denote that two such nodes exist. Return 0, otherwise.
     *
     * Notes
     *      Your solution should run in linear time and not take memory more than O(height of T)
     *      Assume all values in BST are distinct.
     *
     *  Examples: Input 1:

                T :       10
                         / \
                        9   20

                K = 19

                Return: 1

                Input 2:

                T:        10
                         / \
                        9   20

                K = 40

                Return: 0
     */

    namespace sum_binary_tree {

        struct TreeNode {
            int val;
            TreeNode* left;
            TreeNode* right;

            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        };

        //First solution by remembering numbers seen so far through a HashSet.
        //Time Complexity = O(n), Space complexity = O(n).

        bool canReachK (std::unordered_set<long>& hashSet, TreeNode* root, long K);

        int sumBinaryTreeWithNSpace(TreeNode* root, int K);

        //---------------------------------------------------------------------------
        //Second solution by traversing the tree as if it was a sorted array. Equivalent to
        //first solution in this case, but superior if the BST was a balanced BST.
        //Time complexity = O(n), Space complexity = O(treeHeight), in this case O(n), in a balanced
        //BST O(log n).

        void addLeftsOf(std::stack<TreeNode*>& stack, TreeNode* root);

        void addRightsOf(std::stack<TreeNode*>& stack, TreeNode* root);

        int sumBinaryTreeWithHeightSpace(TreeNode* root, int K);
    }
}

#endif //SERGIOTEST_SUMBINARYTREE_H
