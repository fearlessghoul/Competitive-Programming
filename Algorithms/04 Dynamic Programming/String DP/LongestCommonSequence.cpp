#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the LCS length and subsequence
pair<int, string> longestCommonSubsequence(string X, string Y) {
    int m = X.size();
    int n = Y.size();

    // DP table to store LCS lengths
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to find the LCS subsequence
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs += X[i - 1]; // Add matching character to LCS
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Reverse the LCS since we backtracked
    reverse(lcs.begin(), lcs.end());

    return {dp[m][n], lcs};
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    auto result = longestCommonSubsequence(X, Y);

    cout << "Length of LCS: " << result.first << endl;
    cout << "LCS: " << result.second << endl;

    return 0;
}
