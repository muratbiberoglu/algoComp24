#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> parent;
vector<int> subtree_size;

void dfs(int node, int p = -1) {
    subtree_size[node] = 1;
    for (auto nextnode : graph[node]) {
        if (nextnode == p) continue;
        parent[nextnode] = node;
        dfs(nextnode, node);
        subtree_size[node] += subtree_size[nextnode];
    }
}

void reroot(int node) {
    if (parent[parent[node]] != -1) reroot(parent[node]);

    swap(subtree_size[node], subtree_size[parent[node]]);
    subtree_size[parent[node]] = subtree_size[node] - subtree_size[parent[node]];

    parent[parent[node]] = node;
    parent[node] = -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q, r;  // number of nodes, number of queries, root
    cin >> n >> q >> r;
    r--;

    graph.resize(n);
    parent.resize(n);
    subtree_size.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    parent[r] = -1;
    dfs(r);

    while (q--) {
        int type, node;
        cin >> type >> node;
        node--;
        switch (type) {
            case 1:  // re-root the tree
                if (r == node) break;
                reroot(node);
                r = node;
                break;
            case 2:
                cout << subtree_size[node] << "\n";
                break;
            default:
                break;
        }
        // printf("---------------\n");
        // for (int i = 0; i < n; i++) {
        //     printf("Node %i -> Parent: %i, Subtree Size: %i\n", i + 1, parent[i] == -1 ? -1 : parent[i] + 1, subtree_size[i]);
        // }
    }

    return 0;
}
