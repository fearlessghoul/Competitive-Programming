#include <iostream>
#include <vector>
using namespace std;

// Function to implement the Sieve of Eratosthenes
void sieveOfEratosthenes(int n) {
    // Create a boolean array "isPrime[0..n]" and initialize all entries as true
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes

    // Sieve of Eratosthenes
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            // Mark all multiples of i as non-prime
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Print all prime numbers
    cout << "Prime numbers up to " << n << " are: ";
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a number n to find all primes up to n: ";
    cin >> n;

    sieveOfEratosthenes(n);

    return 0;
}
