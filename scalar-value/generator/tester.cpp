#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int it = 0; it < t; it++)
    {
        int n;
        cin >> n;
        unordered_map<int, int> in_degrees;
        unordered_map<int, int> out_degrees;

        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            in_degrees[v]++;
            out_degrees[u]++;
        }

        bool flag = true;

        for (auto in_degree : in_degrees)
        {
            int node = in_degree.first;
            int degree = in_degree.second;
            if (out_degrees[node] != degree)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            for (auto out_degree : out_degrees)
            {
                int node = out_degree.first;
                int degree = out_degree.second;
                if (in_degrees[node] != degree)
                {
                    flag = false;
                    break;
                }
            }
        }

        if (flag)
        {
            if (in_degrees[1] == 0 || out_degrees[1] == 0)
                flag = false;
        }

        if (flag)
            cout << "1" << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}