#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

vector<pair<int, int>> generateEulerianCircuit(int nodeCount, int edgeCount)
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

int main()
{
    srand(time(NULL));
    int n = 6;
    int e = 18;
    vector<pair<int, int>> edges = generateEulerianCircuit(n, e);

    for (auto edge : edges)
    {
        cout << edge.first << " " << edge.second << endl;
    }
}