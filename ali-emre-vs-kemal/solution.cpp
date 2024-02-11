#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ll = long long;
using pll = pair<ll, ll>;
using plll = pair<ll, pll>;

#define BISHOP 0
#define ROOK 1

ll n, tr, tc;

const vector<pll> knightDirections{{2, 1}, {1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, -1}, {-1, -2}};
const vector<pll> bishopDirections{{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const vector<pll> rookDirections{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool inGrid(ll r, ll c) {
    return 0 <= r && r < n && 0 <= c && c < n;
}

void printGrid(vector<vector<ll>>& grid) {
    for (ll r = 0; r < n; r++) {
        for (ll c = 0; c < n; c++) {
            if (c)
                printf(",");
            printf("%lli", grid[r][c] == LLONG_MAX ? -1 : grid[r][c]);
        }
        printf("\n");
    }
}

void fill(vector<vector<ll>>& grid, vector<pll>& pieces, const vector<pll>& directions) {
    priority_queue<plll, vector<plll>, greater<plll>> pq;
    for (const auto [r, c] : pieces) {
        grid[r][c] = 0;
        pq.push({0, {r, c}});
    }

    while (!pq.empty()) {
        auto curDist = pq.top().first;
        auto r = pq.top().second.first;
        auto c = pq.top().second.second;
        pq.pop();

        if (curDist > grid[r][c])
            continue;

        for (const auto [dr, dc] : directions) {
            ll i = 1;
            while (true) {
                auto newR = r + dr * i;
                auto newC = c + dc * i;
                if (!inGrid(newR, newC))
                    break;
                if (grid[newR][newC] == -1)
                    break;
                i++;
                auto newDist = curDist + 1;
                if (newDist < grid[newR][newC]) {
                    grid[newR][newC] = newDist;
                    pq.push({newDist, {newR, newC}});
                }
            }
        }
    }
}

int solve() {
    cin >> n >> tr >> tc;
    tr--;
    tc--;

    vector<vector<ll>> grid(n, vector<ll>(n, LLONG_MAX));
    vector<pll> rooks;
    vector<pll> bishops;
    ll kr, kc;
    for (ll r = 0; r < n; r++) {
        string s;
        cin >> s;
        for (ll c = 0; c < n; c++) {
            char ch = s[c];
            if (ch == 'P') {
                grid[r][c] = -1;
            } else if (ch == 'R') {
                rooks.push_back({r, c});
            } else if (ch == 'B') {
                bishops.push_back({r, c});
            } else if (ch == 'K') {
                kr = r;
                kc = c;
            }
        }
    }

    auto gridBishops = grid;
    auto gridRooks = grid;

    fill(gridBishops, bishops, bishopDirections);
    fill(gridRooks, rooks, rookDirections);

#ifdef DEBUG
    printGrid(gridBishops);
    printf("-----------------------------\n");
    printGrid(gridRooks);
#endif

    // merge solutions
    for (ll r = 0; r < n; r++) {
        for (ll c = 0; c < n; c++) {
            if (grid[r][c] == -1) continue;
            if (gridBishops[r][c] != -1) {
                grid[r][c] = min(grid[r][c], gridBishops[r][c]);
            }
            if (gridRooks[r][c] != -1) {
                grid[r][c] = min(grid[r][c], gridRooks[r][c]);
            }
        }
    }

#ifdef DEBUG
    printf("-----------------------------\n");
    printGrid(grid);
#endif

    auto old = grid[tr][tc];

    // move knight
    vector<pll> knights{{kr, kc}};
    fill(grid, knights, knightDirections);

#ifdef DEBUG
    printf("-----------------------------\n");
    printGrid(grid);
#endif

    cout << (grid[tr][tc] < old ? "YES" : "NO") << "\n";

    return 0;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--)
        solve();

    return EXIT_SUCCESS;
}
