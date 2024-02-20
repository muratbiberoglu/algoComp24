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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int number_of_enemies = 0;
    int player_attack = 0;
    int player_defense = 0;
    int banked_points = 0;

    cin >> number_of_enemies >> player_attack >> player_defense >> banked_points;

    vector<pair<int, int>> monsters;

    int monster_max_attack_treshold = player_defense + banked_points;
    int monster_max_defense_treshold = player_attack + banked_points;
    int monster_max_total_treshold = player_attack + player_defense + banked_points;

    for (int i = 0; i < number_of_enemies; i++)
    {
        int monster_attack = 0;
        int monster_defense = 0;
        cin >> monster_attack >> monster_defense;
        int monster_total = monster_attack + monster_defense;
        if (monster_attack <= monster_max_attack_treshold && monster_defense <= monster_max_defense_treshold && monster_total <= monster_max_total_treshold)
        {
            monsters.push_back({monster_attack, monster_defense});
        }
    }

    // Sort the monsters by their attack
    sort(monsters.begin(), monsters.end());

    SegmentTree st(player_attack + banked_points + 1);

    int max_total = 0;

    for (int i = 0; i < monsters.size(); i++)
    {
        int monster_attack = monsters[i].first;
        int monster_defense = monsters[i].second;

        int required_points_for_defense = max(0, monster_attack - player_defense);

        // If the monster attack is greater than the player defense + required points for defense
        if (monster_attack > player_defense + required_points_for_defense)
            continue;

        int remaining_points_for_attack = max(0, banked_points - required_points_for_defense);
        int player_max_attack = player_attack + remaining_points_for_attack;

        // If the monster defense is greater than the player max attack
        if (monster_defense > player_max_attack)
            continue;

        // Segment tree operations
        st.update(monster_defense, 1);
        max_total = max(max_total, st.query(0, player_max_attack));
    }

    cout << max_total << endl;

    return 0;
}