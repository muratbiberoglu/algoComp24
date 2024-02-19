#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

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

    sort(monsters.begin(), monsters.end());

    /*
    for (int i = 0; i < n; i++)
    {
        cout << monsters[i].first << " " << monsters[i].second << endl;
    }
    */

    int total_max = 0;

    return 0;
}