#include <bits/stdc++.h>

using namespace std;
#define MAX_P 1000000

template <typename T>
void print_vec(vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << "\n";
}

template <typename T>
void shuffle_vec(vector<T>& v) {
    int n = v.size();
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(v[i], v[j]);
    }
}

void generate(int n, int p) {
    vector<int> all_numbers(MAX_P);
    iota(all_numbers.begin(), all_numbers.end(), 1);
    vector<vector<int>> table(n, vector<int>(p));
    for (int i = 0; i < p; i++) {
        shuffle_vec(all_numbers);
        for (int j = 0; j < n; j++)
            table[j][i] = all_numbers[j];
    }
    for (int i = 0; i < n; i++) {
        print_vec(table[i]);
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(atoi(argv[1]));

    int n = atoi(argv[2]);
    int p = atoi(argv[3]);
    int q = atoi(argv[4]);
    cout << n << " " << p << " " << q << "\n";
    generate(n, p);

    return 0;
}
