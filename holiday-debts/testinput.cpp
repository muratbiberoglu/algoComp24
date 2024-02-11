#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    // Seed the random number generator
    random_device rd;
    mt19937 gen(rd());

    // Input: Number of random numbers to generate
    int m;
    cout << "Enter the number of random numbers (m): ";
    cin >> m;

    // Input: Modulus value (n)
    int n;
    cout << "Enter the modulus value (n): ";
    cin >> n;

    // Generate m random numbers between 0 and 2000
    vector<int> randomNumbers(m);
    for (int i = 0; i < m; ++i) {
        randomNumbers[i] = uniform_int_distribution<>(0, 2000)(gen);
    }

    // Calculate the total sum and adjust numbers to satisfy the condition
    int totalSum = accumulate(randomNumbers.begin(), randomNumbers.end(), 0);
    int adjustment = (n - (totalSum % n)) % n;

    // Apply the adjustment to ensure the sum is congruent to 0 (mod n)
    randomNumbers[0] += adjustment;

    // Write the generated random numbers to a file
    ofstream outputFile("input16.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening the file for writing." << endl;
        return 1;
    }
    outputFile << n << endl;
    outputFile << m << endl;

    for (int num : randomNumbers) {
        int person = uniform_int_distribution<>(1, n)(gen);
        outputFile << person <<" "<<num << endl;
    }

    outputFile.close();
    return 0;
}
