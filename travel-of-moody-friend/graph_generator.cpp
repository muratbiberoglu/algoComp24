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
    vector<int> choosed_nodes, unchoosed_nodes;

    for (int i = 0; i < n; i++) {
        unchoosed_nodes.push_back(i);
    }

    random_shuffle(unchoosed_nodes.begin(), unchoosed_nodes.end());

    choosed_nodes.push_back(unchoosed_nodes.back());
    unchoosed_nodes.pop_back();

    while (!unchoosed_nodes.empty()) {
        int last_element = unchoosed_nodes.back();

        int rand_choosed_index = rand() % choosed_nodes.size();
        int rand_choosed_element = choosed_nodes[rand_choosed_index];

        edge_list.push_back({last_element, rand_choosed_element});
        choosed_nodes.push_back(last_element);
        unchoosed_nodes.pop_back();
    }
    /////////////////
    vector<vector<int>> adj_list(n);
    vector<unordered_set<int>> edge_ref(n);
    assert(edge_list.size() == n - 1);
    for (auto e : edge_list) {
        adj_list[e.first].push_back(e.second);
        adj_list[e.second].push_back(e.first);

        edge_ref[e.first].insert(e.second);
        edge_ref[e.second].insert(e.first);
    }

    int cur_edge_count = n - 1;
    while (cur_edge_count < m) {
        int u = rand() % n;
        int v = rand() % n;
        if (u == v) continue;
        if (edge_ref[u].count(v) != 0)
            continue;
        edge_list.push_back({u, v});
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        edge_ref[u].insert(v);
        edge_ref[v].insert(u);
        cur_edge_count++;
    }
}

bool calc_prob(int a, int b) {
    if (rand() % a < b)
        return true;
    return false;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(atoi(argv[1]));

    int n = atoi(argv[2]);
    int m = atoi(argv[3]);
    int maxWeight = atoi(argv[4]);
    generate(n, m);

    assert(edge_list.size() == m);

    int k = rand() % 5 + 1;
    vector<int> nums(k);
    for (int i = 0; i < k; i++) nums[i] = 1 + i;
    random_shuffle(nums.begin(), nums.end());

    // print n m k
    cout << n << " " << m << " " << k << "\n";
    // print coefficients
    for (int i = 0; i < k; i++) {
        if (i) cout << " ";
        cout << nums[i];
    }
    cout << "\n";

    // print adj list
    for (pair<int, int> edge : edge_list) {
        int w = rand() % maxWeight + 1;
        cout << edge.first + 1 << " " << edge.second + 1 << " " << w << "\n";
    }

    return 0;
}
