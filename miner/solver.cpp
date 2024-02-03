#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
int mod = 1e9 + 7; // 998244353
 
const int N = 2e5 + 5;
const int K = 5e2 + 5;
vector<array<int, 2>> g[N];
int val[N];
int dp[N][K];
 
void dfs(int cur, int par) {
    for (auto & pair : g[cur]) {
        int nxt = pair[0], cost = pair[1];
        
        if (nxt == par)
            continue;
        dfs(nxt, cur);
        for (int cur_cost = K - 1; cur_cost >= 0; cur_cost--) {
            for (int nxt_cost = 0; nxt_cost + cur_cost + cost < K; nxt_cost++) {
                int new_cost = nxt_cost + cur_cost + cost;
                dp[cur][new_cost] = max(dp[cur][new_cost], dp[nxt][nxt_cost] + dp[cur][cur_cost]);
            }
        }
    }
    for (int i = 0; i < K; i++) {
        dp[cur][i] += val[cur];
    }
}
 
int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input_file_name = argv[1];
    string output_file_name = argv[2];

    ifstream input_file(input_file_name);
    ofstream output_file(output_file_name);
    
    int n, k;
    // get input from input file
    input_file >> n >> k;
    for (int i = 1; i <= n; i++)
        input_file >> val[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        input_file >> a >> b >> c;
        g[a].pb({b, c}), g[b].pb({a, c});
    }


    dfs(1, 0);
    
    cout << dp[1][k] << "\n";


    // write output to output file
    output_file << dp[1][k] << "\n";
    
    // close input and output file
    input_file.close();
    output_file.close();
    return 0;

}