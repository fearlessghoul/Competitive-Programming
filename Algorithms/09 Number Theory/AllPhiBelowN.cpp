#include <iostream>
#include <vector>
using namespace std;

// Function to compute all phi(r) from 1 to n
vector<int> computeTotients(int n) {
    vector<int> phi(n + 1);

    // Initialize phi[i] to i
    for (int i = 0; i <= n; ++i) {
        phi[i] = i;
    }

    // Apply the sieve algorithm to compute phi values
    for (int p = 2; p <= n; ++p) {
        if (phi[p] == p) { // p is a prime number
            for (int k = p; k <= n; k += p) {
                phi[k] = phi[k] / p * (p - 1); // Update multiples of p
            }
        }
    }

    return phi;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> phi = computeTotients(n);

    cout << "Euler's Totient Function values from 1 to " << n << " are:\n";
    for (int i = 1; i <= n; ++i) {
        cout << "φ(" << i << ") = " << phi[i] << "\n";
    }

    return 0;
}
