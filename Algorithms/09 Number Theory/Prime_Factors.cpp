#include <iostream>
#include <vector>
using namespace std;

// Function to calculate all prime factors of n
vector<int> primeFactors(int n) {
    vector<int> factors;

    // Extract all factors of 2
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Extract all factors of 3
    while (n % 3 == 0) {
        factors.push_back(3);
        n /= 3;
    }

    // Extract all prime factors
    for (int i = 5,j = 7; i * i <= n; i += 6,j += 6) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
        while (n % j == 0) {
            factors.push_back(j);
            n /= j;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}

int main() {
    int n;
    cout << "Enter a number to find its prime factors: ";
    cin >> n;

    vector<int> factors = primeFactors(n);
    cout << "Prime factors of " << n << " are: ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}
