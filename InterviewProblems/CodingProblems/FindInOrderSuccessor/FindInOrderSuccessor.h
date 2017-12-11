/**
 * Solution to problem whose original statement is at: https://www.pramp.com/challenge/MW75pP53wAtzNPVLPG2b
 *
 * In a Binary Search Tree (BST), an Inorder Successor of a node is defined as the node with the smallest key greater than the key of the input node (see examples below). Given a node inputNode in a BST, you’re asked to write a function findInOrderSuccessor that returns the Inorder Successor of inputNode. If inputNode has no Inorder Successor, return null.
   Explain your solution and analyze its time and space complexities.

    https://www.pramp.com/img/content/img_02.png
    In this diagram, the inorder successor of 9 is 11 and the inorder successor of 14 is 20.

    Example:

    In the diagram above, for inputNode whose key = 11

    Your function would return:

    The Inorder Successor node whose key = 12

    Constraints:

    [time limit] 5000ms
    [input] Node inputNode
    [output] Node
 */
#ifndef SERGIOTEST_FINDINORDERSUCCESSOR_H
#define SERGIOTEST_FINDINORDERSUCCESSOR_H

namespace jr {
    class FindInOrderSuccessor {
        struct Node {
            int key;
            Node* left;
            Node* right;
            Node* parent;
        };

        Node* findInOrderSuccessor(Node* inputNode) {
            Node* answer = nullptr;
            if(inputNode->right) { //if input has right, successor is leftmost node is right subtree
                answer = inputNode->right;
                while(answer->left) {
                    answer = answer->left;
                }
                return answer;
            }
            //else, go up until you're at the left of an ancestor. If you're already
            //the left of an ancestor, your successor is your parent.
            answer = inputNode->parent;
            Node* child = inputNode;
            while(answer && answer->left != child) {
                child = answer;
                answer = answer->parent;
            }
            return answer;
        }
    };

    //test main() that can be run on Pramp
/*    int main() {
        Node* root = insert(nullptr, 20);
        insert(root, 9);
        insert(root, 25);
        insert(root, 5);
        insert(root, 12);
        insert(root, 11);
        insert(root, 14);
        Node* ans = findInOrderSuccessor( getNodeByKey(root, 9) );
        if(ans) {
            cout << ans->key << endl;
        } else {
            cout << "nullptr" << endl;
        }
        return 0;
    }*/
}
#endif //SERGIOTEST_FINDINORDERSUCCESSOR_H
