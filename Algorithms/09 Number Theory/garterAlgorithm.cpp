#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Function to compute the modular inverse of a number a under modulo m
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    
    if (m == 1) return 0;

    while (a > 1) {
        // q is quotient
        q = a / m;
        
        // t is remainder
        t = m;
        
        // m is remainder now, process same as Euclid's algorithm
        m = a % m;
        a = t;
        
        t = x0;
        
        // Update x0 and x1
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

// Function to apply Garner's algorithm for solving the system of congruences
int garterAlgorithm(const vector<int>& a, const vector<int>& m) {
    int k = a.size();
    
    // Step 1: Compute the product of all moduli (M_i)
    vector<int> M(k, 1);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (i != j) {
                M[i] *= m[j];
            }
        }
    }

    // Step 2: Compute the result iteratively
    int x = 0;
    for (int i = 0; i < k; ++i) {
        // Compute the modular inverse of M_i mod m_i
        int inv = modInverse(M[i], m[i]);
        
        // Step 3: Add to the solution
        x = (x + a[i] * M[i] * inv) % M[k-1]; // Use M[k-1] as the final modulus, the product of all m_i
    }

    return x;
}

int main() {
    // System of congruences: x ≡ a_i (mod m_i)
    vector<int> a = {2, 3, 1};  // The remainders a_i
    vector<int> m = {3, 5, 7};  // The moduli m_i

    int result = garterAlgorithm(a, m);
    
    cout << "The solution to the system of congruences is: " << result << endl;

    return 0;
}
