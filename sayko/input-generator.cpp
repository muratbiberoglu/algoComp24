#include <bits/stdc++.h>

using namespace std;

int main() {
    srand(0);

    for (int i = 1; i <= 15; i++) {
        stringstream ss;
        ss << "tests/input/input" << setw(2) << setfill('0') << i << ".txt";
        string filename = ss.str();
        cout << "Processing file: " << filename << endl;
        ofstream input_file;
        input_file.open(filename);
        if (!input_file.is_open()) {
            cerr << "Error: Unable to open file " << filename << endl;
            return EXIT_FAILURE;
        }

        string alphabet;

        for (int i = 0; i < 26; i++) {
            alphabet.push_back(i + 'a');
        }
        random_shuffle(alphabet.begin(), alphabet.end());

        string s;
        int n;
        switch (i % 3)
        {
        case 0:
        {
            /* 1 <= n <= 5 * 10^2 */
            n = rand() % 500 + 1;
            break;
        }
        case 1:
        {
            /* 5 * 10^2 < n <= 10^4 */
            n = (rand() % 10000 + 501) % 10000;
            break;
        }
        case 2:
        {
            /* 10^4 < n <= 2 * 10^5 */
            n = (rand() % 200000 + 10001) % 200000;
            break;
        }
        }

        for (int i=0; i<n; i++) {
            s.push_back('a' + (rand() % 26));
        }

        int q = rand() % n + 1;

        input_file << s << "\n" << alphabet << "\n" << q << "\n";

        while (q--) {
            int i = rand() % n;
            input_file << i << "\n";
        }
        
        input_file.close();
    }

    return 0;
}
