#include <iostream>
#include <vector>
using namespace std;

// Function to compute the smallest prime factor (SPF) for each number from 1 to n
vector<int> smallestPrimeFactors(int n) {
    vector<int> spf(n + 1);

    // Initialize spf[i] = i for all i
    for (int i = 1; i <= n; ++i) {
        spf[i] = i;
    }

    // Apply sieve to find smallest prime factor for each number
    for (int i = 2; i * i <= n; ++i) {
        // If spf[i] is i, it means i is a prime number
        if (spf[i] == i) {
            // Mark all multiples of i with i as the smallest prime factor
            for (int j = i * i; j <= n; j += i) {
                // Update spf[j] only if it hasn't been updated before (i.e., it's still j)
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> spf = smallestPrimeFactors(n);

    cout << "Smallest prime factors from 1 to " << n << " are:\n";
    for (int i = 1; i <= n; ++i) {
        cout << "SPF(" << i << ") = " << spf[i] << "\n";
    }

    return 0;
}
