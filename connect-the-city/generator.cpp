#include <stdio.h>
#include <time.h>

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;
vector<pair<int, int>> edge_list;

void generate(int n, int m) {
    vector<unordered_set<int>> edge_ref(n);
    int cur_edge_count = 0;
    while (cur_edge_count < m) {
        int u = rand() % n;
        int v = rand() % n;
        if (u == v) continue;
        if (edge_ref[u].count(v) != 0)
            continue;
        edge_list.push_back({u, v});
        edge_ref[u].insert(v);
        edge_ref[v].insert(u);
        cur_edge_count++;
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(atoi(argv[1]));

    int n = atoi(argv[2]);
    int m = atoi(argv[3]);

    generate(n, m);

    assert(edge_list.size() == m);

    cout << n << " " << m << "\n";
    for (auto [u, v]: edge_list) {
        cout << u + 1 << " " << v + 1 << "\n";
    }

    return 0;
}
