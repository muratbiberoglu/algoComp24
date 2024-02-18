#include <bits/stdc++.h>

using namespace std;

#define MAX_HEIGHT 1000000

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(atoi(argv[1]));

    int n = atoi(argv[2]);
    int q = atoi(argv[3]);

    cout << n << " " << q << "\n";
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (c) cout << " ";
            cout << rand() % MAX_HEIGHT + 1;
        }
        cout << "\n";
    }
    while (q--) {
        int x1 = rand() % n + 1;
        int x2 = rand() % n + 1;
        int y1 = rand() % n + 1;
        int y2 = rand() % n + 1;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    }

    return 0;
}
