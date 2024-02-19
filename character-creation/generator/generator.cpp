#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

int main(int argc, char *argv[])
{
    srand(time(0));

    string test_case = argv[1];

    int n = atoi(argv[2]);
    int a = atoi(argv[3]);
    int d = atoi(argv[4]);
    int p = atoi(argv[5]);

    int attack_max = 5 * (d + p) / 4;
    int defense_max = 5 * (a + p) / 4;
    if (attack_max > MAX)
        attack_max = MAX;

    if (defense_max > MAX)
        defense_max = MAX;

    string file_name = "tests/input" + test_case + ".txt";

    ofstream file;
    file.open(file_name);

    file << n << " " << a << " " << d << " " << p << endl;

    for (int i = 0; i < n; i++)
    {
        int attack = rand() % attack_max + 1;
        int defense = rand() % defense_max + 1;

        file << attack << " " << defense << endl;
    }

    return 0;
}