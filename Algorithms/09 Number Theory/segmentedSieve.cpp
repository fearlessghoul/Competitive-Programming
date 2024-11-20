#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to perform Sieve of Eratosthenes and find primes up to sqrt(n)
vector<int> sieveOfEratosthenes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Function to perform Segmented Sieve
void segmentedSieve(int L, int R) {
    int limit = sqrt(R);
    vector<int> primes = sieveOfEratosthenes(limit);  // Step 1: Find all primes up to sqrt(R)
    
    // Create a boolean array for the current range [L, R]
    vector<bool> isPrime(R - L + 1, true);
    
    // Step 2: Use small primes to mark non-primes in the range [L, R]
    for (int i = 0; i < primes.size(); i++) {
        int prime = primes[i];
        
        // Find the first number in the range [L, R] that is a multiple of prime
        int start = max(prime * prime, (L + prime - 1) / prime * prime);
        
        // Mark all multiples of prime in the range as non-prime
        for (int j = start; j <= R; j += prime) {
            isPrime[j - L] = false;
        }
    }
    
    // Step 3: Print all primes in the range [L, R]
    for (int i = 0; i <= R - L; i++) {
        if (isPrime[i]) {
            cout << (i + L) << " ";
        }
    }
    cout << endl;
}

int main() {
    int L, R;
    cout << "Enter the range [L, R] to find primes: ";
    cin >> L >> R;

    segmentedSieve(L, R);

    return 0;
}
