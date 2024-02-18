#include <bits/stdc++.h>
using namespace std;

#define MOD 1234567891

int A[1 << 10];
long long C[1 << 11][1 << 11];
long long R[2][1 << 7][1 << 11];

long long power(long long a, long long b) {
    long long i;
    long long res = 1;
    for (i = 1; i <= b; i <<= 1) {
        if ((b & i) != 0)
            res = res * a % MOD;

        a = a * a % MOD;
    }
    return res;
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < K; ++i)
        cin >> A[i];
    sort(A, A + K);
    reverse(A, A + K);
    long long z = 1;
    int prev = 0;
    for (int i = 1; i <= K; ++i)
        if (i == K || A[i] != A[prev]) {
            for (int j = 0; j < i - prev; ++j)
                z = z * (j + 1) % MOD;
            prev = i;
        }
    for (int i = 0; i < (1 << 11); ++i)
        C[i][i] = C[i][0] = 1;
    for (int i = 0; i < (1 << 11); ++i)
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    R[0][0][0] = 1;
    for (int i = 0; i < K; ++i) {
        int prev = i & 1;
        int next = prev ^ 1;
        memset(R[next], 0, sizeof(R[next]));
        for (int j = 0; j <= i; ++j)
            for (int k = 0; k <= N; ++k)
                if (R[prev][j][k] != 0) {
                    R[next][j + 1][k + A[i] + A[i] + 1] += (j + 1) * R[prev][j][k];
                    R[next][j + 1][k + A[i] + A[i] + 1] %= MOD;
                    R[next][j][k + A[i] + 1] += (j + j) * R[prev][j][k];
                    R[next][j][k + A[i] + 1] %= MOD;
                    if (j > 1) {
                        R[next][j - 1][k + 1] += (j - 1) * R[prev][j][k];
                        R[next][j - 1][k + 1] %= MOD;
                    }
                }
    }
    long long res = 0;
    for (int i = 0; i <= N; ++i) {
        long long r = R[K & 1][1][i];
        if (r == 0)
            continue;
        long long n = K + 1;
        long long k = N - i;
        r *= C[n + k - 1][k];
        r %= MOD;
        res += r;
    }
    res %= MOD;
    res *= power(z, MOD - 2);
    res %= MOD;
    cout << res << endl;
    return 0;
}
