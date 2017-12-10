#include "SumBinaryTree.h"

using jr::sum_binary_tree::TreeNode;

using std::stack;
using std::unordered_set;

bool jr::sum_binary_tree::canReachK (unordered_set<long>& hashSet, TreeNode* root, long K) {
    if (hashSet.find(K - root->val) != hashSet.end()) {
        return true;
    }
    hashSet.insert(root->val);
    if(root->left && canReachK(hashSet, root->left, K)) {
        return true;
    }
    if(root->right && canReachK(hashSet, root->right, K)) {
        return true;
    }
    return false;
}

int jr::sum_binary_tree::sumBinaryTreeWithNSpace(TreeNode* root, int K) {
    unordered_set<long> hashSet;
    return canReachK(hashSet, root, K);
}

//Solution 2 ---------------------------------------------------------------------------

void jr::sum_binary_tree::addLeftsOf(std::stack <TreeNode*>& stack, TreeNode* root) {
    TreeNode* current = root;
    while(current->left) {
        stack.push(current->left);
        current = current->left;
    }
}

void jr::sum_binary_tree::addRightsOf(std::stack<TreeNode*>& stack, TreeNode* root) {
    TreeNode* current = root;
    while(current->right) {
        stack.push(current->right);
        current = current->right;
    }
}

int jr::sum_binary_tree::sumBinaryTreeWithHeightSpace(TreeNode* root, int K) {
    stack <TreeNode*> smallStack;
    stack <TreeNode*> bigStack;
    smallStack.push(root);
    addLeftsOf(smallStack, root);
    bigStack.push(root);
    addRightsOf(bigStack, root);

    TreeNode* currentLeft = smallStack.top();
    TreeNode* currentRight = bigStack.top();
    while(currentLeft && currentRight && currentLeft->val != currentRight->val) {
        int currentSum = currentLeft->val + currentRight->val;
        if(currentSum == K) {
            return true;
        }
        if(currentSum < K) {
            smallStack.pop();
            if(currentLeft->right) {
                smallStack.push(currentLeft->right);
                addLeftsOf(smallStack, currentLeft->right);
            }
        }
        if(currentSum > K) {
            bigStack.pop();
            if(currentRight->left) {
                bigStack.push(currentRight->left);
                addRightsOf(bigStack, currentRight->left);
            }
        }
        currentLeft = smallStack.top();
        currentRight = bigStack.top();
    }
    return false;
}

