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

int main()
{
    int t;
    cin >> t;
    for (int it = 0; it < t; it++)
    {
        int n;
        cin >> n;
        unordered_map<int, int> in_degrees;
        unordered_map<int, int> out_degrees;
        unordered_map<int, vector<int>> adj_list;
        unordered_map<int, bool> visited;

        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            visited[u] = false;
            visited[v] = false;
            in_degrees[v]++;
            out_degrees[u]++;
        }

        bool flag = true;

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
            cout << "1" << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}