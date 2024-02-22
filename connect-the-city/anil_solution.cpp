#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;  // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

vector<pair<int, int>> bridges;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges.push_back({v, to});
            }
        }
    }
}

void dfs2(int v) {
    visited[v] = true;
    for (int to : adj[v]) {
        if (!visited[to]) {
            dfs2(to);
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    visited = vector<bool>(n, false);
    tin = vector<int>(n, -1);
    low = vector<int>(n, -1);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_bridges(n);

    for (auto bridge : bridges) {
        int u = bridge.first;
        int v = bridge.second;
        for (int i = 0; i < adj[u].size(); i++) {
            if (adj[u][i] == v) {
                adj[u].erase(adj[u].begin() + i);
                break;
            }
        }
        for (int i = 0; i < adj[v].size(); i++) {
            if (adj[v][i] == u) {
                adj[v].erase(adj[v].begin() + i);
                break;
            }
        }
    }

    int count = 0;
    visited = vector<bool>(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            dfs2(i);
        }
    }

    cout << count;

    return 0;
}