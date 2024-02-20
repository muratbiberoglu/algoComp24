#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    srand(time(0));

    int n = atoi(argv[1]);
    int lower_limit_char = atoi(argv[2]);
    int upper_limit_char = atoi(argv[3]);
    int lower_limit_monster = atoi(argv[4]);
    int upper_limit_monster = atoi(argv[5]);

    int a = rand() % (upper_limit_char - lower_limit_char + 1) + lower_limit_char;
    int d = rand() % (upper_limit_char - lower_limit_char + 1) + lower_limit_char;
    int p = rand() % (min(upper_limit_char, upper_limit_monster) - max(lower_limit_char, lower_limit_monster) + 1) + max(lower_limit_char, lower_limit_monster);

    cout << n << " " << a << " " << d << " " << p << endl;

    for (int i = 0; i < n; i++)
    {
        int attack = rand() % (upper_limit_monster - lower_limit_monster + 1) + lower_limit_monster;
        int defense = rand() % (upper_limit_monster - lower_limit_monster + 1) + lower_limit_monster;
        cout << attack << " " << defense << endl;
    }

    return 0;
}