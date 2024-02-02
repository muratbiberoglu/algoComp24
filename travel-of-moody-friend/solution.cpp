#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int n, m, k;
vector<int> coefficients;
vector<vector<pll>> graph;

void generate() {
    vector<vector<ll>> distances(n, vector<ll>(k, LLONG_MAX));
    distances[0][k - 1] = 0;

    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
    pq.push({0, {0, k - 1}});   // dist, node, state
    while (!pq.empty()) {
        ll cur_dist = pq.top().first;
        ll cur_node = pq.top().second.first;
        ll cur_state = pq.top().second.second;
        pq.pop();

        ll next_state = (cur_state + 1) % k;
        for (auto [next_node, edge_weight]: graph[cur_node]) {
            ll next_dist = (edge_weight * coefficients[next_state]) + cur_dist;
            if (next_dist < distances[next_node][next_state]) {
                distances[next_node][next_state] = next_dist;
                pq.push({next_dist, {next_node, next_state}});
            }
        }
    }

    ll ans = LLONG_MAX;
    for (auto d: distances[n - 1]) ans = min(ans, d);
    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    coefficients.resize(k);
    graph.resize(n);

    for (int i = 0; i < k; i++)
        cin >> coefficients[i];

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    generate();

    return 0;
}
