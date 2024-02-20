#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
int mod = 1e9 + 7; // 998244353

const int N = 2e5 + 5;
string s;
int next_of[N];
const int INF = 1e9;
vvi min_dist(N, vi(26, INF));
bool vis_before[N]; // Already visited in previous DFSs
bool vis_now[N];    // Not visited in previous DFSs, visited in the current DFS
bool in_cycle[N];   // Is in a cycle

void update_node_using_next(int node) {
    for (int letter = 0; letter < 26; letter++)
        min_dist[node][letter] = min(min_dist[node][letter], min_dist[next_of[node]][letter] + 1);
    min_dist[node][s[next_of[node]] - 'a'] = 1;
}
void handle_cycle(int cycle_start) {
    int cur = cycle_start;
    vector<int> nodes_in_cycle; // (in order)
    while (1) {
        in_cycle[cur] = 1;
        nodes_in_cycle.pb(cur);
        cur = next_of[cur];
        if (cur == cycle_start)
            break;
    }
    int cycle_size = nodes_in_cycle.size();
    /*
        Iterate from right to left to compute min_dist correctly.
        Do this twice as it's a cycle!
    */
    // The first loop can ignore the last node
    for (int i = cycle_size - 2; i >= 0; i--) {
        update_node_using_next(nodes_in_cycle[i]);
    }
    // However, the second loop must start from the last node
    for (int i = cycle_size - 1; i >= 0; i--) {
        update_node_using_next(nodes_in_cycle[i]);
    }
}
void dfs(int cur) {
    // Definitely no cycle, just discovered another branch that is connected to an already-computed component
    if (vis_before[cur]) {
        // Nothing to do here actually, just return
        return;
    }
    // Definitely found a cycle :D
    else if (vis_now[cur]) {
        // Update min_dist and in_cycle for this cycle
        handle_cycle(cur);
        return;
    }
    vis_now[cur] = 1;
    dfs(next_of[cur]);
    vis_before[cur] = 1;
    // Cycles are handled separately, don't touch 'em again
    // Actually, it wouldn't hurt to update again 🤔
    if (in_cycle[cur])
        return;
    // The next node has definitely been handled, time to compute the current
    update_node_using_next(cur);
}

int main() {

    for (int i = 1; i <= 15; i++) {
        stringstream ss_in;
        ss_in << "tests/input/input" << setw(2) << setfill('0') << i << ".txt";
        string infile = ss_in.str();
        cout << "Processing file: " << infile << endl;
        ifstream input_file;
        input_file.open(infile);
        if (!input_file.is_open()) {
            cerr << "Error opening input file: " << infile << endl;
            return 1; // Exit with an error code
        }

        stringstream ss_out;
        ss_out << "output/output" << setw(2) << setfill('0') << i << ".txt";
        string outfile = ss_out.str();
        cout << "Processing file: " << outfile << endl;
        ofstream output_file;
        output_file.open(outfile);

        string alphabet;
        input_file >> s >> alphabet;
        int n = s.size();
        int dist[26];
        for (int i = 0; i < alphabet.size(); i++) {
            dist[alphabet[i] - 'a'] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            next_of[i] = (i + dist[s[i] - 'a']) % n;
        }
        for (int i = 0; i < n; i++)
            dfs(i);
        int q;
        input_file >> q;
        while (q--) {
            int i;
            input_file >> i;
            output_file << (min_dist[i][s[i] - 'a'] >= INF ? -1 : min_dist[i][s[i] - 'a']) << "\n";
        }
        
        input_file.close();
        output_file.close();
    }
    return 0;
}