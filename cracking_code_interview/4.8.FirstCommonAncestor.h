
#ifndef SERGIOTEST_4_6_FIRSTCOMMONANCESTOR_H
#define SERGIOTEST_4_6_FIRSTCOMMONANCESTOR_H

/*#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

namespace firstCommonAncestor {
    struct Node {
        Node *left;
        Node *right;
        int id;
        Node(int id) : id(id), left(nullptr), right(nullptr) {}
    };
}

using firstCommonAncestor::Node;

vector<Node> pathVectorTo(Node* target, Node* origin) {
    vector<Node> path;
    if (origin) {
        if (origin->id == target->id) {
            path.push_back(*origin);
        } else {
            path = pathVectorTo(target, origin->left);
            if (path.empty()) {
                path = pathVectorTo(target, origin->right);
            }
            if (!path.empty()) {
                path.push_back(*origin);
            }
        }
    }
    return path;
}

unordered_set<Node> pathHashSetTo(Node* target, Node* origin) {
    unordered_set<Node> pathHashSet;
    vector<Node> pathVector = pathVectorTo(target, origin);
    for (int i = 0; i < pathVector.size(); i++) {
        Node& node = pathVector.at(i);
        pathHashSet.insert(node);
    }
    return pathHashSet;
}

Node* firstCommonAncestorOf(Node* firstNode, Node* secondNode, Node* root) {
    vector<Node> pathToFirstNode;
    unordered_set<Node> pathToSecondNode;
    pathToFirstNode = pathVectorTo(firstNode, root);
    if (pathToFirstNode.empty()) {
        return nullptr;
    }
    pathToSecondNode = pathHashSetTo(secondNode, root);
    if (pathToSecondNode.empty()) {
        return nullptr;
    }
    for (int i = 0; i < pathToFirstNode.size(); i++) {
        Node node = pathToFirstNode.at(i);
        if (pathToSecondNode.find(node) != pathToSecondNode.end()) {
            Node* answerPointer = &node;
            return answerPointer;
        }
    }
}*/

#endif //SERGIOTEST_4_6_FIRSTCOMMONANCESTOR_H
