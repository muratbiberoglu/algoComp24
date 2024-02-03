#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read input values
    int n, m;
    cin >> n >> m;

    // Initialize vectors to store total expenses and individual balances
    vector<long long> individualBalances(n + 1, 0);

    long long averageExpense = 0;
    // Process each receipt
    for (int i = 0; i < m; ++i) {
        int person, amount;
        cin >> person >> amount;
        // Update total expenses and individual balances
        averageExpense += amount;
        individualBalances[person] += amount;
    }

    // Calculate average expense per person
    averageExpense /= n;

    // Calculate and print individual balances
    for (int i = 1; i <= n; ++i) {
        long long balance = averageExpense - individualBalances[i];
        string status = (balance > 0) ? "debtor" : ((balance < 0) ? "payee" : "");
        cout << i << " " << abs(balance) << " " << status << endl;
    }

    return 0;
}
