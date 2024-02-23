#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 1e2 + 5;
#define int long long int
int seg[4*N][4*N];

void upd2(int c1, int c2, int l2, int r2, int ty, int v) {
    if (!(l2 <= ty && ty <= r2))
        return;
    if (l2 == r2) {
        seg[c1][c2] = max(seg[c1][c2], v);
        return;
    }
    int mid = (l2 + r2) / 2;
    upd2(c1, 2 * c2, l2, mid, ty, v);
    upd2(c1, 2 * c2 + 1, mid + 1, r2, ty, v);
    seg[c1][c2] = max(seg[c1][2 * c2], seg[c1][2 * c2 + 1]);
}

void upd(int c1, int l1, int r1, int tx, int ty, int v) {
    if (!(l1 <= tx && tx <= r1))
        return;
    upd2(c1, 1, 0, N - 1, ty, v);
    if (l1 == r1) {
        return;
    }
    int mid = (l1 + r1) / 2;
    upd(2 * c1, l1, mid, tx, ty, v);
    upd(2 * c1 + 1, mid + 1, r1, tx, ty, v);
}

int get(int c1, int c2, int l2, int r2, int y1, int y2) {
    if (l2 > y2 || r2 < y1)
        return 0;
    if (y1 <= l2 && r2 <= y2)
        return seg[c1][c2];
    int mid = (l2 + r2) / 2;
    return max(get(c1, 2 * c2, l2, mid, y1, y2), get(c1, 2 * c2 + 1, mid + 1, r2, y1, y2));
}

int get(int c1, int l1, int r1, int c2, int l2, int r2, int x1, int y1, int x2, int y2) {
    if (l1 > x2 || r1 < x1)
        return 0;
    if (x1 <= l1 && r1 <= x2)
        return get(c1, c2, l2, r2, y1, y2);
    int mid = (l1 + r1) / 2;
    return max(get(2 * c1, l1, mid, c2, l2, r2, x1, y1, x2, y2),
               get(2 * c1 + 1, mid + 1, r1, c2, l2, r2, x1, y1, x2, y2));
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    ll pre[n + 1][n + 1] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            upd(1, 0, N - 1, i, j, x);
            pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + x;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << get(1, 0, N - 1, 1, 0, N - 1, i, j, i, j) << " ";
    //     }
    //     cout << "\n";
    // }

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        int mx = get(1, 0, N - 1, 1, 0, N - 1, x1, y1, x2, y2);
        int area = (x2 - x1 + 1) * (y2 - y1 + 1);
        ll sum = pre[x2 + 1][y2 + 1] - pre[x1][y2 + 1] - pre[x2 + 1][y1] + pre[x1][y1];
        cout << (ll)area * mx - sum << "\n";
    }
}