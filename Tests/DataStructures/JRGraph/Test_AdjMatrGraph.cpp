#include "gtest/gtest.h"

#include "../../../DataStructures/JRGraph/AdjacencyMatrix/AdjMatrGraph.h"

using std::string;

//test graph: https://computersciencesource.files.wordpress.com/2010/05/dfs_1.png
AdjMatrGraph testGraph1() {
    AdjMatrGraph test(5);
    test.addEdge(0, 1, 1);
    test.addEdge(0, 2, 1);
    test.addEdge(0, 4, 1);
    test.addEdge(1, 3, 1);
    test.addEdge(1, 4, 1);
    return test;
}
TEST(Test_AdjMatrGraph, EmptyGraph) {
    AdjMatrGraph empty(0);
    ASSERT_EQ(false, empty.connected(1, 1));
    ASSERT_NO_THROW(empty.addEdge(1, 1, 10));
    ASSERT_EQ(false, empty.connected(1, 1));
}

TEST(Test_AdjMatrGraph, OneSizedGraph) {
    AdjMatrGraph test(1);
    ASSERT_EQ(false, test.connected(0, 0));
    ASSERT_NO_THROW(test.addEdge(0, 0, 10));
    ASSERT_EQ(true, test.connected(0, 0));
}

TEST(Test_AdjMatrGraph, InitializeTestGraph) {
    //test graph: https://computersciencesource.files.wordpress.com/2010/05/dfs_1.png
    AdjMatrGraph test(5);
    ASSERT_NO_THROW(test.addEdge(0, 1, 1));
    ASSERT_EQ(true, test.connected(0, 1));
    ASSERT_EQ(true, test.connected(1, 0));
    ASSERT_NO_THROW(test.addEdge(0, 2, 1));
    ASSERT_EQ(true, test.connected(0, 2));
    ASSERT_EQ(true, test.connected(2, 0));
    ASSERT_NO_THROW(test.addEdge(0, 4, 1));
    ASSERT_EQ(true, test.connected(0, 4));
    ASSERT_EQ(true, test.connected(4, 0));

    ASSERT_NO_THROW(test.addEdge(1, 3, 1));
    ASSERT_EQ(true, test.connected(1, 3));
    ASSERT_EQ(true, test.connected(3, 1));
    ASSERT_NO_THROW(test.addEdge(1, 4, 1));
    ASSERT_EQ(true, test.connected(1, 4));
    ASSERT_EQ(true, test.connected(4, 1));
}

TEST(Test_AdjMatrGraph, BFS_TestGraph1) {
    std::vector<int> bfs(testGraph1().BFS());
    ASSERT_EQ(5, bfs.size());
    for(int i = 0; i < 3; i++) {
        ASSERT_EQ(i, bfs.at(i));
    }
    ASSERT_EQ(4, bfs.at(3));
    ASSERT_EQ(3, bfs.at(4));
}