#include <bits/stdc++.h>

using namespace std;

using edge = pair<int, bool&>;

vector<vector<edge>> graph;
vector<int> low, tin;
vector<bool> visited;
int bridge_count = 0, timer = 0;

void dfs(int node, int parent = -1) {
    visited[node] = true;
    low[node] = tin[node] = timer++;

    for (auto& [nextnode, is_bridge]: graph[node]) {
        if (nextnode == parent) continue;
        if (visited[nextnode]) {
            low[node] = min(low[node], tin[nextnode]);
        } else {
            dfs(nextnode, node);
            low[node] = min(low[node], low[nextnode]);
            if (low[nextnode] > tin[node]) {
                is_bridge = true;
                bridge_count++;
            }
        }
    }
}

void dfs2(int node) {
    visited[node] = true;
    for (auto [nextnode, is_bridge]: graph[node]) {
        if (is_bridge || visited[nextnode]) continue;
        dfs2(nextnode);
    }
}

void find_bridges(int n) {
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    graph.resize(n);
    tin = vector<int>(n, -1);
    low = vector<int>(n, -1);
    visited = vector<bool>(n, false);
    bool bridge[m] = {false};
    int u, v;
    while (m--) {
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back({v, bridge[m]});
        graph[v].push_back({u, bridge[m]});
    }

    // mark bridges with Tarjan's Back Edge Algorithm
    find_bridges(n);

    // count the number of components on the bridge tree
    int component_counter = 0;
    visited = vector<bool>(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            component_counter++;
            dfs2(i);
        }
    }
    cout << component_counter << "\n";

    return 0;
}
