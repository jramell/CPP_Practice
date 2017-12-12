#include "AdjMatrGraph.h"
#include <queue>

using std::queue;

bool AdjMatrGraph::validVertex(long vertex) {
    return vertex >= 0 && vertex < adjMatrix.size();
}
AdjMatrGraph::AdjMatrGraph(long numberOfVertices) {
    std::vector<long> emptyRow = std::vector<long>(numberOfVertices, INFINITY);
    adjMatrix = std::vector<std::vector<long>>(numberOfVertices, emptyRow);
}

void AdjMatrGraph::addEdge(long vertex1, long vertex2, unsigned int weight) {
    if(!validVertex(vertex1) || !validVertex(vertex2)) {
        return;
    }
    adjMatrix.at(vertex1).at(vertex2) = weight;
    adjMatrix.at(vertex2).at(vertex1) = weight;
}

void AdjMatrGraph::removeEdge(long vertex1, long vertex2) {
    if(!validVertex(vertex1) || !validVertex(vertex2)) {
        return;
    }
    adjMatrix.at(vertex1).at(vertex2) = INFINITY;
    adjMatrix.at(vertex2).at(vertex1) = INFINITY;
}

bool AdjMatrGraph::connected(long vertex1, long vertex2) {
    if(!validVertex(vertex1) || !validVertex(vertex2)) {
        return false;
    }
    return adjMatrix.at(vertex1).at(vertex2) != INFINITY;
}

std::vector<int> AdjMatrGraph::BFS() {
    std::vector<int> DFSTraversal;
    if(adjMatrix.empty()) {
        return DFSTraversal;
    }
    std::vector<bool> traversed(adjMatrix.size(), false);
    queue<int> traverseQueue;
    traverseQueue.push(0);
    traversed.at(0) = true;
    while(!traverseQueue.empty()) {
        int current = traverseQueue.front();
        traverseQueue.pop();
        for(int i = 0; i < adjMatrix.size(); i++) {
            if(connected(current, i) && !traversed.at(i)) {
                traverseQueue.push(i);
                traversed.at(i) = true;
            }
        }
        DFSTraversal.push_back(current);
    }
    return DFSTraversal;
}