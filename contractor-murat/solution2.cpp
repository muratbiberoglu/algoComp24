#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T>
using v = vector<T>;

inline ll lshift(ll pwr) {return 1ll << pwr;}

const ll MAX_N = 100;
const ll MAX_LOG_N = 6;
ll n, q;
ll rmq[MAX_N][MAX_N][MAX_LOG_N + 1][MAX_LOG_N + 1];
ll grid[MAX_N][MAX_N];

void preprocess() {
    // calculate the log value
    ll k = 63 - __builtin_clzll(n);

    // copy the initial values
    for (ll r = 0; r < n; r++)
        for (ll c = 0; c < n; c++)
            rmq[r][c][0][0] = grid[r][c];

    // merge rows
    for (ll i = 1; i <= k; i++) {
        ll pwr_i = lshift(i);
        ll pwr_i_1 = lshift(i - 1);
        for (ll r = 0; r + pwr_i - 1 < n; r++)
            for (ll c = 0; c < n; c++)
                rmq[r][c][i][0] = max(rmq[r][c][i - 1][0], rmq[r + pwr_i_1][c][i - 1][0]);
    }
    // merge columns
    for (ll i = 1; i <= k; i++) {
        ll pwr_i = lshift(i);
        ll pwr_i_1 = lshift(i - 1);
        for (ll r = 0; r < n; r++)
            for (ll c = 0; c + pwr_i - 1 < n; c++)
                rmq[r][c][0][i] = max(rmq[r][c][0][i - 1], rmq[r][c + pwr_i_1][0][i - 1]);
    }

    // merge rectangles
    for (ll i = 1; i <= k; i++) {
        ll pwr_i = lshift(i);
        ll pwr_i_1 = lshift(i - 1);
        for (ll j = 1; j <= k; j++) {
            ll pwr_j = lshift(j);
            ll pwr_j_1 = lshift(j - 1);
            for (ll r = 0; r + pwr_i - 1 < n; r++)
                for (ll c = 0; c + pwr_j - 1 < n; c++)
                    rmq[r][c][i][j] = max(
                        max(
                            rmq[r][c][i - 1][j - 1],
                            rmq[r + pwr_i_1][c][i - 1][j - 1]),
                        max(
                            rmq[r][c + pwr_j_1][i - 1][j - 1],
                            rmq[r + pwr_i_1][c + pwr_j_1][i - 1][j - 1]));
        }
    }
}

ll query(ll x1, ll y1, ll x2, ll y2) {
    ll dx = x2 - x1 + 1;
    ll dy = y2 - y1 + 1;
    ll i_max = 63 - __builtin_clzll(dx);
    ll j_max = 63 - __builtin_clzll(dy);

    // maximum query
    ll max_value = max(
        max(
            rmq[x1][y1][i_max][j_max],
            rmq[x2 - lshift(i_max) + 1][y1][i_max][j_max]
        ),
        max(
            rmq[x1][y2 - lshift(j_max) + 1][i_max][j_max],
            rmq[x2 - lshift(i_max) + 1][y2 - lshift(j_max) + 1][i_max][j_max]
        )
    );

    // sum query = O(1)
    ll sum = grid[x2][y2];
    if (x1) sum -= grid[x1 - 1][y2];
    if (y1) sum -= grid[x2][y1 - 1];
    if (x1 && y1) sum += grid[x1 - 1][y1 - 1];

    return dx * dy * max_value - sum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> grid[i][j];

    // preprocess the grid for rmq
    preprocess();

    // 2d prefix sum
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (i) grid[i][j] += grid[i - 1][j];
            if (j) grid[i][j] += grid[i][j - 1];
            if (i && j) grid[i][j] -= grid[i - 1][j - 1];
        }
    }

    // answer the queries
    while (q--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        cout << query(x1, y1, x2, y2) << "\n";
    }

    return 0;
}