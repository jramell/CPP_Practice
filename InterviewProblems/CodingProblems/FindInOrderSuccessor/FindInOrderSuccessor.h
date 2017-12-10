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
