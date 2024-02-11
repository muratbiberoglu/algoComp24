#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>  // Common file

using namespace std;
using namespace __gnu_pbds;

#define MAX_P 1000000

typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> os_tree;

vector<vector<int>> table;
vector<os_tree> trees;
vector<set<int>> used;

pii find(int a, int b) {
    return *trees[a - 1].find_by_order(b - 1); // order is zero indexed
}

void update(int a, int b, int c, int d) {
    pii p = find(a, b);
    pii search_for = {table[p.second][c - 1], p.second};
    trees[c - 1].erase(search_for);
    used[c - 1].erase(search_for.first);
    search_for.first += d;
    table[search_for.second][c - 1] += d;
    trees[c - 1].insert(search_for);
    used[c - 1].insert(search_for.first);
}

int read(int a, int b, int c) {
    pii p = find(a, b);
    cout << table[p.second][c - 1] << "\n";
}

void generate() {
    int n, p, q;
    cin >> n >> p >> q;
    table.resize(n);
    trees.resize(p);
    used.resize(p);
    for (int i = 0; i < n; i++) {
        table[i].resize(p);
        for (int j = 0; j < p; j++) {
            cin >> table[i][j];
            trees[j].insert({table[i][j], i});
            used[j].insert(table[i][j]);
        }
    }

    // generate queries
    int type, a, b, c, d;
    type = 2;
    int last_updated_p = -1;
    while (q--) {
        type = 3 - type;

        a = rand() % p + 1;
        if (type == 2)    // search at last changed property
            a = last_updated_p;

        b = rand() % n + 1;
        c = rand() % p + 1;

        // determine appropiate d
        if (type == 1) {
            auto [value, index] = find(a, b);
            int to_be_updated_value = table[index][c - 1];
            int next_value = -1;
            while (true) {
                next_value = rand() % MAX_P + 1;
                if (used[c - 1].count(next_value) == 0) break;
            }
            d = next_value - to_be_updated_value;
            update(a, b, c, d);
            last_updated_p = c;
        }

        // print query
        cout << type << " " << a << " " << b << " " << c;
        if (type == 1) cout << " " << d;
        cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(atoi(argv[1]));
    generate();
    return 0;
}
