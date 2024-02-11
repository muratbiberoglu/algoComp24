#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Input: File name
    string fileName = "input00.txt";
    int total = 0;
    // Read from the file
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    // Input: Number of people (n) and number of transactions (m)
    int n, m;
    inputFile >> n >> m;

    // Initialize money vector with zeros
    vector<int> moneyVector(n, 0);

    // Process each transaction
    for (int i = 0; i < m; ++i) {
        int place, amount;
        inputFile >> place >> amount;
        total = total + amount;
        moneyVector[place - 1] += amount; // Adjust index to start from 0
    }

    total = total/n;
    // Close the file
    inputFile.close();

    // Print the updated money vector

    ofstream outputFile("output00.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening the file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        if(moneyVector[i]-total<0){
            outputFile << (i + 1) << " " << total-moneyVector[i] << " debtor"<<endl;
        }
        else if(moneyVector[i]-total == 0){
            outputFile << (i + 1) << " " << total-moneyVector[i] <<endl;
        }
        else{
            outputFile << (i + 1) << " " << moneyVector[i]-total << " payee"<<endl;

        }
        
    }

    return 0;
}
