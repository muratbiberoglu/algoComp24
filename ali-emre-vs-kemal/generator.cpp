#include <bits/stdc++.h>

using namespace std;

pair<int, int> decompose(int index, int n) {
    return {index / n, index % n};
}

void set_positions_bulk(vector<vector<char>>& grid, vector<int>& nums, int n, int count, char c) {
    for (int i = 0; i < count; i++) {
        auto pos = decompose(nums.back(), n);
        nums.pop_back();
        grid[pos.first][pos.second] = c;
    }
}

void generate_grid(int n, int p, int r, int b) {
    vector<vector<char>> grid(n, vector<char>(n, '_'));
    vector<int> nums(n * n);
    iota(nums.begin(), nums.end(), 0);
    random_shuffle(nums.begin(), nums.end());

    // get knight
    auto knight = decompose(nums.back(), n);
    nums.pop_back();
    grid[knight.first][knight.second] = 'K';

    set_positions_bulk(grid, nums, n, r, 'R');
    set_positions_bulk(grid, nums, n, b, 'B');
    set_positions_bulk(grid, nums, n, p, 'P');

    auto target = decompose(nums.back(), n);

    // print test case
    cout << n << " " << target.first + 1 << " " << target.second + 1 << "\n";
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            cout << grid[r][c];
        cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // srand(atoi(argv[1]));
    srand(time(nullptr));

    int t = atoi(argv[2]);
    int n = atoi(argv[3]);
    int p = atoi(argv[4]);
    int r = atoi(argv[5]);
    int b = atoi(argv[6]);

    cout << t << "\n";
    while (t--)
        generate_grid(n, p, r, b);

    return 0;
}
