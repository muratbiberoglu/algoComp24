#include <bits/stdc++.h>

using namespace std;

inline int lchild(int i) {return 2 * i + 1;}
inline int rchild(int i) {return 2 * i + 2;}

int n, p, q;
int qt, a, b, c, d;
const int max_value = 1000001;

class OSTree {
   public:
    OSTree() {
        st = vector<int>(4 * max_value, 0);
        n = max_value;
    }

    void update(int index, int value) {
        update(0, 0, n - 1, index, value);
    }

    int get_by_order(int order) {
        return get_by_order(0, 0, n - 1, order);
    }

   private:
    vector<int> st;
    int n;

    void update(int si, int sl, int sr, int i, int value) {
        if (i < sl || sr < i || sl > sr) return;
        if (sl == sr) {
            st[si] = value;
            return;
        }
        int mid = (sl + sr) >> 1;
        update(lchild(si), sl, mid, i, value);
        update(rchild(si), mid + 1, sr, i, value);
        st[si] = st[lchild(si)] + st[rchild(si)];
    }

    int get_by_order(int si, int sl, int sr, int order) {
        if (sl == sr) return sl;

        int mid = (sl + sr) >> 1;
        if (order <= st[lchild(si)]) {   // go left
            return get_by_order(lchild(si), sl, mid, order);
        } else {
            return get_by_order(rchild(si), mid + 1, sr, order - st[lchild(si)]);
        }
    }
};

void solve() {
    cin >> n >> p >> q;
    vector<vector<int>> videos(n, vector<int>(p));
    for (auto& video : videos)
        for (auto& video_property : video)
            cin >> video_property;

    // Build the OS Trees
    vector<OSTree> ostrees(p);
    vector<unordered_map<int, int>> maps(p);

    for (int id = 0; id < n; id++) {
        for (int i = 0; i < p; i++) {
            ostrees[i].update(videos[id][i], 1);
            maps[i][videos[id][i]] = id;
        }
    }

    // Answer the queries
    while (q--) {
        cin >> qt >> a >> b >> c;
        a--;
        c--;

        // get video id of the b'th smallest according to a'th property
        int value = ostrees[a].get_by_order(b);
        int id = maps[a][value];
        if (qt == 1) {
            cin >> d;
            // update the c'th property of the video with adding d on it
            ostrees[c].update(videos[id][c], 0);
            maps[c].erase(videos[id][c]);
            videos[id][c] += d;
            ostrees[c].update(videos[id][c], 1);
            maps[c].insert({videos[id][c], id});
        } else {
            // print the value of c'th property
            cout << videos[id][c] << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
