#include <iostream>
using namespace std;

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) return false;  // 0 and 1 are not prime numbers
    if (n <= 3) return true;   // 2 and 3 are prime numbers

    if (n % 2 == 0 || n % 3 == 0)  // Exclude multiples of 2 and 3
        return false;

    // Check divisibility starting from 5, skipping even numbers
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)  // Check divisibility by i and i+2
            return false;
    }

    return true;  // If no factors found, n is prime
}

int main() {
    int n;
    cout << "Enter a number to check if it's prime: ";
    cin >> n;

    if (is_prime(n)) {
        cout << n << " is a prime number.\n";
    } else {
        cout << n << " is not a prime number.\n";
    }

    return 0;
}
