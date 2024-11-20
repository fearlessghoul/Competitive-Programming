#include <iostream>
#include <vector>
using namespace std;

// Function to calculate Catalan numbers using DP
long long catalanUsingDP(int n) {
    vector<long long> catalan(n + 1, 0);
    catalan[0] = 1; // Base case
    catalan[1] = 1; // Base case

    // Fill the table using the recursive relation
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    return catalan[n];
}

// Function to calculate factorial
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate the nth Catalan number using the formula
long long catalanUsingFormula(int n) {
    long long numerator = factorial(2 * n);        // (2n)!
    long long denominator = factorial(n + 1) * factorial(n); // (n+1)! * n!
    return numerator / denominator;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "The " << n << "th Catalan number is: " << catalanUsingFormula(n) << endl;

    return 0;
}
