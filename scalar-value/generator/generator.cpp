#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

void check_connected(int node, unordered_map<int, vector<int>> &adj_list, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    for (auto neighbour : adj_list[node])
    {
        if (visited[neighbour] == false)
            check_connected(neighbour, adj_list, visited);
    }
}

vector<pair<int, int>> generatePossibleEulerianCircuit(int nodeCount, int edgeCount)
{
    map<int, int> in_degrees;
    map<int, int> out_degrees;

    for (int i = 0; i < nodeCount; i++)
    {
        in_degrees[i + 1] = 0;
        out_degrees[i + 1] = 0;
    }

    for (int i = 0; i < edgeCount; i++)
    {
        int u = (rand() % nodeCount) + 1;
        out_degrees[u]++;
        in_degrees[u]++;
    }

    vector<int> erase_in_degrees;

    for (auto in_degree : in_degrees)
    {
        int node = in_degree.first;
        int degree = in_degree.second;
        if (degree == 0)
            erase_in_degrees.push_back(node);
    }

    for (auto node : erase_in_degrees)
        in_degrees.erase(node);

    vector<int> erase_out_degrees;

    for (auto out_degree : out_degrees)
    {
        int node = out_degree.first;
        int degree = out_degree.second;
        if (degree == 0)
            erase_out_degrees.push_back(node);
    }

    for (auto node : erase_out_degrees)
        out_degrees.erase(node);

    vector<pair<int, int>> edges;

    for (int i = 0; i < edgeCount; i++)
    {
        int u_idx = rand() % out_degrees.size();
        auto u_itr = out_degrees.begin();
        advance(u_itr, u_idx);
        int u = u_itr->first;
        out_degrees[u]--;
        if (out_degrees[u] == 0)
            out_degrees.erase(u);

        int v_idx = rand() % in_degrees.size();
        auto v_itr = in_degrees.begin();
        advance(v_itr, v_idx);
        int v = v_itr->first;
        in_degrees[v]--;
        if (in_degrees[v] == 0)
            in_degrees.erase(v);

        edges.push_back({u, v});
    }

    return edges;
}

vector<pair<int, int>> generateRandomGraph(int nodeCount, int edgeCount)
{
    vector<pair<int, int>> edges;

    for (int i = 0; i < edgeCount; i++)
    {
        int u = (rand() % nodeCount) + 1;
        int v = (rand() % nodeCount) + 1;
        edges.push_back({u, v});
    }

    return edges;
}

template <typename T>
void shuffle(vector<T> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int idx = rand() % n;
        swap(v[i], v[idx]);
    }
}

string testGenerated(vector<pair<int, int>> edges)
{
    bool flag = true;
    unordered_map<int, int> in_degrees;
    unordered_map<int, int> out_degrees;
    unordered_map<int, vector<int>> adj_list;
    unordered_map<int, bool> visited;

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adj_list[u].push_back(v);
        visited[u] = false;
        visited[v] = false;
        in_degrees[v]++;
        out_degrees[u]++;
    }

    for (auto in_degree : in_degrees)
    {
        int node = in_degree.first;
        int degree = in_degree.second;
        if (out_degrees[node] != degree)
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        for (auto out_degree : out_degrees)
        {
            int node = out_degree.first;
            int degree = out_degree.second;
            if (in_degrees[node] != degree)
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
    {
        if (in_degrees[1] == 0 || out_degrees[1] == 0)
            flag = false;
    }

    // The graph might be disconnected
    if (flag)
    {
        check_connected(1, adj_list, visited);
        for (auto node : visited)
        {
            if (node.second == false)
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
        return "1";

    return "-1";
}

int main(int argc, char **argv)
{
    // Arg 1 -> rand seed
    // Arg 2 -> min_dimensions
    // Arg 3 -> max_dimensions
    // Arg 4 -> num_edges min
    // Arg 5 -> num_edges max
    // Arg 6 -> test count

    int rand_seed = stoi(argv[1]);
    srand(rand_seed);

    int min_dimensions = stoi(argv[2]);
    int max_dimensions = stoi(argv[3]);
    int num_edges_min = stoi(argv[4]);
    int num_edges_max = stoi(argv[5]);
    int test_count = stoi(argv[6]);

    cout << test_count << endl;

    for (int i = 0; i < test_count; i++)
    {
        int nodeCount = (rand() % (max_dimensions - min_dimensions + 1)) + min_dimensions;
        int edgeCount = (rand() % (num_edges_max - num_edges_min + 1)) + num_edges_min;

        vector<pair<int, int>> edges;

        if (rand() % 2 == 0)
            edges = generatePossibleEulerianCircuit(nodeCount, edgeCount);
        else
            edges = generateRandomGraph(nodeCount, edgeCount);

        shuffle(edges);

        cout << edges.size() << endl;

        for (auto edge : edges)
            cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}