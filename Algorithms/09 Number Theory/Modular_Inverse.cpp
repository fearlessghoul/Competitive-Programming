#include <iostream>
using namespace std;

// Function to compute gcd and Bézout coefficients x, y
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a; // gcd(a, b)
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);

    // Update x and y using results from recursion
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// Function to find modular inverse of a under modulo m
bool modularInverse(int a, int m, int &inverse) {
    int x, y; // Bézout coefficients
    int gcd = extendedGCD(a, m, x, y);

    // Modular inverse exists only if gcd(a, m) = 1
    if (gcd != 1) {
        return false; // Modular inverse does not exist
    }

    // Modular inverse is x mod m (ensuring it's positive)
    inverse = (x % m + m) % m;
    return true;
}

int main() {
    int a, m;
    cout << "Enter number and modulo to find modular inverse (a, m): ";
    cin >> a >> m;

    int inverse;
    if (modularInverse(a, m, inverse)) {
        cout << "Modular inverse of " << a << " under modulo " << m << " is " << inverse << ".\n";
    } else {
        cout << "Modular inverse does not exist for " << a << " under modulo " << m << ".\n";
    }

    return 0;
}
