// Question Writer: Fatih Baskın
// Question Tester(s): Kemal Tahir Bıllıcıoğlu

#include <bits/stdc++.h>
using namespace std;

/**
 * Before staring the editorial, I must explain the logic behind this question.
 *
 * Instead of determining the result using iterative ways, we must construct a graph, representing the multiplicity of the matrices.
 * We will use this graph to find out whether given matrices yield a scalar value.
 *
 * But we will go one more step further, since we want to get a scalar value, our result must be 1x1 matrix.
 * We can imagine that we are starting from 1x1 identity matrix, which is just the value of 1.
 * Since a sequence of matrices that yield a scalar value always starts with 1xA matrix,
 * it is possible to add the identity matrix to left of this sequence
 *
 * An example would be:
 * 1x3 3x5 5x2 2x1 -> I 1x3 3x5 5x2 2x1
 * Where I represents 1x1 identity matrix.
 *
 * With each matrix, we modify the last dimension of the I matrix, if we go step by step:
 * I -> 1x1
 * I 1x3 -> 1x3
 * I 1x3 3x5 -> 1x5
 * I 1x3 3x5 5x2 -> 1x2
 * I 1x3 3x5 5x2 2x1 -> 1x1
 *
 * So, if you have noticed already, a AxB matrix represents the change of the number of columns from A to B.
 * A 3x5 matrix will turn 1x3 matrix into 1x5 matrix.
 * With this logic, we can think matrices as a transform operation, and since we want to use all these matrices,
 * we need to use all of them in our graph.
 *
 * So, what will our multiplicity graph represent then?
 * The nodes will represent the number of columns of 1xA matrix.
 * A matrix AxB represents a directed edge from 1xA to 1xB where A and B are the nodes.
 * We will look for a "circuit" in our graph which visits all the edges.
 * Circuit means a path starts from a particular node and ends on the same node.
 *
 * These kinds of circuits are called "Eulerian circuit"s.
 * We need to find out the existance of such a circuit.
 *
 * For detailed explaination, you can watch these two videos:
 * Existence of Eulerian Paths and Circuits: https://www.youtube.com/watch?v=xR4sGgwtR2I
 * Eulerian Path/Circuit algorithm (Hierholzer's algorithm): https://www.youtube.com/watch?v=8MpoO2zA2l4
 *
 * To basically explain, there exists a eulerian circuit if all the nodes have same number of in_degrees and out_degrees, in a directed graph.
 * We need to check the existance of such a circuit.
 * Also, we need to check whether the given graph is connected.
 *
 */

// It is a DFS function to check whether the graph is connected.
void checkConnectedDFS(int node, unordered_map<int, vector<int>> &adj_list, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    for (auto neighbour : adj_list[node])
    {
        if (visited[neighbour] == false)
            checkConnectedDFS(neighbour, adj_list, visited);
    }
}

bool isScalar(unordered_map<int, int> &in_degrees, unordered_map<int, int> &out_degrees, unordered_map<int, vector<int>> &adj_list)
{
    // First, we need to check whether there exists an edge coming to or leaving from the dimension of 1
    if (in_degrees[1] == 0 || out_degrees[1] == 0)
        return false;

    // We need to check in-degrees and out-degrees
    for (auto in_degree : in_degrees)
    {
        int node = in_degree.first;
        int degree = in_degree.second;
        // If in_degrees and out_degrees are not equal, return false
        if (out_degrees[node] != degree)
            return false;
    }

    /**
     * There is no need to check this actually, if in_degree != out_degree in the previous one, any imbalance will cause a negative result
     * Imbalance example: Nodes are: 3x1 5x1 7x1
     * Here, in_degrees map will have only 1 as an entry and its value will be 3, when we ask out_degree, its value will be 0.
     * Because of it, it will yield false.

    for (auto out_degree : out_degrees)
    {
        int node = out_degree.first;
        int degree = out_degree.second;
        if (in_degrees[node] != degree)
            return false;
    }
    */

    // The graph might be disconnected, we need to initialize visited map with the edges
    unordered_map<int, bool> visited;
    for (auto node_degree_pair : in_degrees)
    {
        int node = node_degree_pair.first;
        visited[node] = false;
    }

    // With using a DFS, we check whether the directed graph is connected and we are able to traverse every node.
    checkConnectedDFS(1, adj_list, visited);
    // From the map of "visited", check all the nodes.
    for (auto node : visited)
        if (node.second == false)
            // If a node is not visited, graph is not connected and it is impossible to use all the matrices
            return false;

    // After all these checks, if we didn't get a false result, we can say that there exists an eulerian circuit.
    return true;
}

int main()
{
    // There are t times this operation will be done, so we take input t times.
    int t;
    cin >> t;
    for (int it = 0; it < t; it++)
    {
        // Number of matrices
        int n;
        cin >> n;

        // Constructing the adjacency list and in-out degrees map.
        unordered_map<int, int> in_degrees;
        unordered_map<int, int> out_degrees;
        unordered_map<int, vector<int>> adj_list;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            in_degrees[v]++;
            out_degrees[u]++;
        }

        // Using the isScalar function, we print the output.
        if (isScalar(in_degrees, out_degrees, adj_list))
            cout << "1" << endl;
        else
            cout << "-1" << endl;
    }

    return 0;
}