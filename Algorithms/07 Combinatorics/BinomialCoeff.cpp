#include <iostream>
#include <vector>
using namespace std;

int nCrDP(int n, int r) {
    if (r > n) return 0; // nCr is undefined for r > n
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, r); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1; // Base case
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][r];
}

long long nCr(int n, int r) {
    if (r > n) return 0;
    if (r > n - r) r = n - r; // Use smaller r to reduce computations

    long long res = 1; // Initialize result
    for (int i = 0; i < r; i++) {
        res = res * (n - i);  // Multiply by (n - i)
        res /= (i + 1);       // Divide by (i + 1)
    }
    return res;
}

int main() {
    int n = 5, r = 2;
    cout << "nCr(" << n << ", " << r << ") = " << nCr(n, r) << endl;
    return 0;
}
