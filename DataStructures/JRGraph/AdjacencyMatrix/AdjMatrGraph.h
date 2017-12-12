#ifndef SERGIOTEST_ADJMATRGRAPH_H
#define SERGIOTEST_ADJMATRGRAPH_H

#include <vector>
#include <climits>

class AdjMatrGraph {
    const int INFINITY = -1;
    std::vector<std::vector<long>> adjMatrix;

    bool validVertex(long vertex);
public:
    AdjMatrGraph(long numberOfVertices);

    /**
     * Adds undirected connection with weight "weight" between vertices with the passed indices.
     * If any of the vertices are invalid, does nothing.
     * @param vertex1 one vertex in the connection
     * @param vertex2 other vertex in the connection
     * @param weight weight of the connection
     */
    void addEdge(long vertex1, long vertex2, unsigned int weight);

    /**
     * Removes undirected connection with weight "weight" between vertices with the passed indices.
     * If any of the vertices are invalid, does nothing.
     * @param vertex1 one vertex in the connection
     * @param vertex2 other vertex in the connection
     * @param weight weight of the connection
     */
    void removeEdge(long vertex1, long vertex2);
    bool connected(long vertex1, long vertex2);

    /**
     * Performs a BFS on the graph and returns a list with the nodes in
     * breadth first order.
     */
    std::vector<int> BFS();

    /**
     * Performs a DFS on the graph and returns a list with the nodes in
     * depth first order
     */
    std::vector<int> DFS();
};


#endif //SERGIOTEST_ADJMATRGRAPH_H
