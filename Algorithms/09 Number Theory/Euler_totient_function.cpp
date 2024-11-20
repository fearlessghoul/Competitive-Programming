#include <iostream>
using namespace std;

// Function to compute Euler's Totient Function using the product formula
int eulerTotient(int n) {
    int result = n; // Initialize result as n

    // Check for all prime factors of n
    for (int p = 2; p * p <= n; ++p) {
        // Check if p is a prime factor
        if (n % p == 0) {
            // Subtract multiples of p from the result
            result -= result / p;

            // Remove all factors of p from n
            while (n % p == 0) {
                n /= p;
            }
        }
    }

    // If n is a prime number greater than 1
    if (n > 1) {
        result -= result / n;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter a number to calculate its Euler's Totient Function: ";
    cin >> n;

    cout << "Euler's Totient Function φ(" << n << ") = " << eulerTotient(n) << endl;

    return 0;
}
