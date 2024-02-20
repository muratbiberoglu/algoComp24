#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    vector<int> tree;
    int n;
    SegmentTree(int n)
    {
        this->n = n;
        tree.assign(4 * n, 0);
    }

    int query(int l, int r)
    {
        return querySum(1, 0, n - 1, l, r);
    }

    int querySum(int node, int tl, int tr, int l, int r)
    {

        // If it lies out of range then
        // return 0
        if (r < tl or tr < l)
            return 0;

        // If the node contains the range then
        // return the node value
        if (l <= tl and tr <= r)
            return tree[node];

        // Tree middle
        int tm = (tl + tr) / 2;

        // Recursively traverse left and right
        // and find the node
        return querySum(2 * node, tl, tm, l, r) + querySum(2 * node + 1, tm + 1, tr, l, r);
    }

    void update(int pos, int val)
    {
        updateSum(1, 0, n - 1, pos, val);
    }

    void updateSum(int node, int L, int R, int idx, int val)
    {

        if (L == R)
            tree[node] += val;
        else
        {
            int mid = (L + R) / 2;

            if (L <= idx && idx <= mid)
                updateSum(2 * node, L, mid, idx, val);

            else
                updateSum(2 * node + 1, mid + 1, R, idx, val);

            // Store the information in parents
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
};

int main(int argc, char *argv[])
{
    string file_number = argv[1];

    int n = 0;
    int a = 0;
    int d = 0;
    int p = 0;

    string input_file = "tests/input" + file_number + ".txt";
    string output_file = "tests/output" + file_number + ".txt";

    ifstream inFile;
    inFile.open(input_file);

    assert(inFile.is_open());

    inFile >> n >> a >> d >> p;

    // cout << n << " " << a << " " << d << " " << p << endl;
    vector<pair<int, int>> monsters(n, {0, 0});

    for (int i = 0; i < n; i++)
    {
        inFile >> monsters[i].first >> monsters[i].second;
    }

    inFile.close();

    vector<pair<int, int>> filtered_monsters;

    // Depending on strictly snaller or equal to the treshold
    int monster_max_attack_treshold = max(d + p - 1, 0);
    int monster_max_defense_treshold = max(a + p - 1, 0);
    int monster_max_points_treshold = max(a + d + p - 2, 0);

    for (int i = 0; i < n; i++)
        if (monsters[i].first <= monster_max_attack_treshold &&
            monsters[i].second <= monster_max_defense_treshold &&
            monsters[i].first + monsters[i].second <= monster_max_points_treshold)
            filtered_monsters.push_back(monsters[i]);

    sort(filtered_monsters.begin(), filtered_monsters.end());

    SegmentTree st(a + p + 1);

    int max_total = 0;

    for (int i = 0; i < filtered_monsters.size(); i++)
    {
        int monster_attack = filtered_monsters[i].first;
        int monster_defense = filtered_monsters[i].second;

        // canavar 7 vursa bende 5 defans olsa, 7 - 4 = 3 lazım
        int required_for_defense = max(0, monster_attack - (d - 1));
        int available_points = p - required_for_defense;

        // canavar'ın 6 defansı var, benim 5 attack'im var, 6 - 4 = 2 lazım
        int required_for_attack = max(0, monster_defense - (a - 1));
        if (required_for_attack > available_points)
            continue;

        st.update(monster_defense, 1);
        int total_attack = a + available_points;
        int max_query = st.query(0, total_attack);
        max_total = max(max_total, max_query);
    }

    cout << max_total << endl;

    return 0;
}