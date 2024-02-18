#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>  // Common file

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> os_tree;

vector<vector<int>> table;
vector<os_tree> trees;

pii find(int a, int b) {
    return *trees[a - 1].find_by_order(b - 1); // order is zero indexed
}

void update(int a, int b, int c, int d) {
    pii p = find(a, b);
    pii search_for = {table[p.second][c - 1], p.second};
    trees[c - 1].erase(search_for);
    search_for.first += d;
    table[p.second][c - 1] += d;
    trees[c - 1].insert(search_for);
}

void read(int a, int b, int c) {
    pii p = find(a, b);
    cout << table[p.second][c - 1] << "\n";
}

void solve() {
    int n, p, q;
    cin >> n >> p >> q;
    table = vector<vector<int>>(n, vector<int>(p));
    trees = vector<os_tree>(p);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> table[i][j];
            trees[j].insert({table[i][j], i});
        }
    }
    int type, a, b, c, d;
    while (q--) {
        cin >> type >> a >> b >> c;
        if (type == 1) {
            cin >> d;
            update(a, b, c, d);
        } else if (type == 2) {
            read(a, b, c);
        } else {
            throw runtime_error("Type has another value other than 1 or 2");
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}