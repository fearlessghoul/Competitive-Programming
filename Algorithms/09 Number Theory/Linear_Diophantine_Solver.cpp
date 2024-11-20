#include <iostream>
#include <vector>
using namespace std;

// Function to solve ax + by = c using the matrix method
bool solveDiophantineMatrixMethod(int a, int b, int c, int &x, int &y, int &gcd) {
    vector<vector<int>> matrix = {{1, 0}, {0, 1}}; // Initial matrix
    int r1 = a, r2 = b;                            // Remainders
    int q;                                         // Quotient

    // Perform the Euclidean algorithm while updating the matrix
    while (r2 != 0) {
        q = r1 / r2;

        // Update the remainders
        int tempR = r1 - q * r2;
        r1 = r2;
        r2 = tempR;

        // Update the transformation matrix
        int tempX = matrix[0][0] - q * matrix[1][0];
        int tempY = matrix[0][1] - q * matrix[1][1];

        matrix[0][0] = matrix[1][0];
        matrix[0][1] = matrix[1][1];
        matrix[1][0] = tempX;
        matrix[1][1] = tempY;
    }

    gcd = r1;

    // Check if the equation has a solution
    if (c % gcd != 0) {
        return false; // No solution exists
    }

    // Scale the coefficients to match c
    x = matrix[0][0] * (c / gcd);
    y = matrix[0][1] * (c / gcd);

    return true;
}

// Function to compute gcd and coefficients x, y (Bézout coefficients)
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; // Coefficient for 'a'
        y = 0; // Coefficient for 'b'
        return a; // GCD of a and b
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);

    // Update x and y using results from recursion
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// Function to solve ax + by = c
bool solveDiophantine(int a, int b, int c, int &x, int &y, int &gcd) {
    gcd = extendedGCD(a, b, x, y);

    // Check if c is divisible by gcd(a, b)
    if (c % gcd != 0) {
        return false; // No solution
    }

    // Scale the solution to the specific value of c
    x *= c / gcd;
    y *= c / gcd;
    return true; // Solution exists
}

int main() {
    int a, b, c;
    cout << "Enter coefficients a, b, and constant c for the equation ax + by = c: ";
    cin >> a >> b >> c;

    int x, y, gcd;
    if (solveDiophantine(a, b, c, x, y, gcd)) {
        cout << "Solution exists:\n";
        cout << "x = " << x << ", y = " << y << "\n";
        cout << "General solution: x = " << x << " + " << b / gcd << "k, y = " << y << " - " << a / gcd << "k\n";
    } else {
        cout << "No solution exists for the given equation.\n";
    }

    return 0;
}
