#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T>
using v = vector<T>;

inline ll lshift(ll pwr) {return 1ll << pwr;}

ll n, q;
v<v<ll>> grid;
v<v<v<v<ll>>>> rsmq;    // range sum minimum query
v<v<v<v<ll>>>> rmmq;    // range maximum minimum query

void preprocess() {
    // calculate the log value
    ll k = 63 - __builtin_clzll(n);

    rsmq = v<v<v<v<ll>>>>(n, v<v<v<ll>>>(n, v<v<ll>>(k + 1, v<ll>(k + 1, 0))));
    rmmq = v<v<v<v<ll>>>>(n, v<v<v<ll>>>(n, v<v<ll>>(k + 1, v<ll>(k + 1, 0))));

    // copy the initial values
    for (ll r = 0; r < n; r++)
        for (ll c = 0; c < n; c++)
            rsmq[r][c][0][0] = rmmq[r][c][0][0] = grid[r][c];

    // merge rows
    for (ll i = 1; i <= k; i++)
        for (ll r = 0; r + lshift(i) - 1 < n; r++)
            for (ll c = 0; c < n; c++) {
                rsmq[r][c][i][0] = rsmq[r][c][i - 1][0] + rsmq[r + lshift(i - 1)][c][i - 1][0];
                rmmq[r][c][i][0] = max(rmmq[r][c][i - 1][0], rmmq[r + lshift(i - 1)][c][i - 1][0]);
            }

    // merge columns
    for (ll i = 1; i <= k; i++)
        for (ll r = 0; r < n; r++)
            for (ll c = 0; c + lshift(i) - 1 < n; c++) {
                rsmq[r][c][0][i] = rsmq[r][c][0][i - 1] + rsmq[r][c + lshift(i - 1)][0][i - 1];
                rmmq[r][c][0][i] = max(rmmq[r][c][0][i - 1], rmmq[r][c + lshift(i - 1)][0][i - 1]);
            }

    // merge rectangles
    for (ll i = 1; i <= k; i++)
        for (ll j = 1; j <= k; j++)
            for (ll r = 0; r + lshift(i) - 1 < n; r++)
                for (ll c = 0; c + lshift(j) - 1 < n; c++) {
                    rsmq[r][c][i][j] = rsmq[r][c][i - 1][j - 1]
                                     + rsmq[r + lshift(i - 1)][c][i - 1][j - 1]
                                     + rsmq[r][c + lshift(j - 1)][i - 1][j - 1]
                                     + rsmq[r + lshift(i - 1)][c + lshift(j - 1)][i - 1][j - 1];

                    rmmq[r][c][i][j] = max(
                        max(
                            rmmq[r][c][i - 1][j - 1],
                            rmmq[r + lshift(i - 1)][c][i - 1][j - 1]
                        ),
                        max(
                            rmmq[r][c + lshift(j - 1)][i - 1][j - 1],
                            rmmq[r + lshift(i - 1)][c + lshift(j - 1)][i - 1][j - 1]
                        )
                    );
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
            rmmq[x1][y1][i_max][j_max],
            rmmq[x2 - lshift(i_max) + 1][y1][i_max][j_max]
        ),
        max(
            rmmq[x1][y2 - lshift(j_max) + 1][i_max][j_max],
            rmmq[x2 - lshift(i_max) + 1][y2 - lshift(j_max) + 1][i_max][j_max]
        )
    );

    // sum query ~= O(log n * log n)
    ll sum = 0;
    ll l = x1;
    for (int i = i_max; i >= 0; i--) {
        if (!(lshift(i) & dx)) continue;
        ll u = y1;
        for (int j = j_max; j >= 0; j--) {
            if (!(lshift(j) & dy)) continue;
            sum += rsmq[l][u][i][j];
            u += lshift(j);
        }
        l += lshift(i);
    }

    return dx * dy * max_value - sum;
}

ll brute_force(ll x1, ll y1, ll x2, ll y2) {
    ll sum = 0;
    ll max_value = 0;
    for (ll r = x1; r <= x2; r++)
        for (ll c = y1; c <= y2; c++) {
            sum += grid[r][c];
            max_value = max(max_value, grid[r][c]);
        }
    return (x2 - x1 + 1) * (y2 - y1 + 1) * max_value - sum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    srand(time(nullptr));

    n = 50;
    grid = v<v<ll>>(n, v<ll>(n));

    for (auto& r: grid)
        for (auto& c: r)
            c = rand() % 1000000;

    // preprocess the grid for rmq
    preprocess();

    // check for every possible sub-rectangle
    for (ll x1 = 0; x1 < n; x1++)
        for (ll y1 = 0; y1 < n; y1++)
            for (ll x2 = x1; x2 < n; x2++)
                for (ll y2 = y1; y2 < n; y2++)
                    assert(brute_force(x1, y1, x2, y2) == query(x1, y1, x2, y2));

    return 0;
}
