#include <bits/stdc++.h>
using namespace std;

#define MOD (int(1e9 + 7))

int add(int a, int b) {
    return a + b < MOD ? a + b : a + b - MOD;
}

int mult(int a, int b) {
    return 1LL * a * b % MOD;
}

struct matrix {
    int a[6][6];
    matrix() {
        memset(a, 0, sizeof(a));
    }
    matrix(int idx, int inv) {
        memset(a, 0, sizeof(a));
        if (idx != 5)
            for (int j = 0; j < 6; ++j)
                a[idx][j] = (inv ? (MOD - 1) : 1);
        for (int i = 0; i < 6; ++i)
            a[i][i] = 1;
    }
    vector<int> multV(const vector<int>& b) {
        assert(b.size() == 6);
        vector<int> res(6, 0);
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 6; ++j)
                res[i] = add(res[i], mult(a[i][j], b[j]));
        return res;
    }
    matrix multM(const matrix& b) {
        matrix res;
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 6; ++j)
                for (int k = 0; k < 6; ++k)
                    res.a[i][j] = add(res.a[i][j], mult(a[i][k], b.a[k][j]));
        return res;
    }
};

string s;
vector<matrix> A, B;
const string OK = "lucky";

int main() {
    int n, m;
    cin >> n >> m >> s;
    A.resize(n + 1);
    B.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        int idx = 5;
        for (int j = 0; j < 5; ++j)
            if (s[i] == OK[j])
                idx = j;
        A[i + 1] = matrix(idx, 0);
        B[i + 1] = matrix(idx, 1);
    }
    A[0] = B[0] = matrix(5, 0);
    for (int i = 0; i < n; ++i) {
        B[i + 1] = B[i].multM(B[i + 1]);
        A[i + 1] = A[i + 1].multM(A[i]);
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--;
        vector<int> x(6, 0);
        x[5] = 1;
        x = B[l].multV(x);
        x = A[r].multV(x);
        int ans = 0;
        for (int i = 0; i < 5; ++i)
            ans = add(ans, x[i]);
        cout << ans << endl;
    }
    return 0;
}