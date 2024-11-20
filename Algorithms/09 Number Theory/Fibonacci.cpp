#include <iostream>
#include <vector>
using namespace std;

// Function to compute the Pisano period for Fibonacci numbers modulo m
int pisanoPeriod(int m) {
    int previous = 0, current = 1;
    
    // Loop to find the period
    for (int i = 0; i < m * m; ++i) {
        int temp = (previous + current) % m;
        previous = current;
        current = temp;
        
        // If we have found the repetition of [0, 1], then return the length of the period
        if (previous == 0 && current == 1) {
            return i + 1;
        }
    }
    
    return -1;  // This shouldn't happen for valid m
}


// Function to multiply two 2x2 matrices
vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
    vector<vector<long long>> result(2, vector<long long>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Function to perform matrix exponentiation
vector<vector<long long>> matrixPower(vector<vector<long long>>& matrix, int n) {
    // Base case: return identity matrix if n = 0
    vector<vector<long long>> result = {{1, 0}, {0, 1}};
    while (n > 0) {
        if (n % 2 == 1) {
            result = multiply(result, matrix);
        }
        matrix = multiply(matrix, matrix);
        n /= 2;
    }
    return result;
}

// Function to calculate the nth Fibonacci number using matrix exponentiation
long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // The transformation matrix for Fibonacci
    vector<vector<long long>> matrix = {{1, 1}, {1, 0}};
    
    // Raise matrix to the power of (n-1)
    vector<vector<long long>> result = matrixPower(matrix, n - 1);
    
    // The Fibonacci number will be at result[0][0]
    return result[0][0];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << endl;

    return 0;
}
