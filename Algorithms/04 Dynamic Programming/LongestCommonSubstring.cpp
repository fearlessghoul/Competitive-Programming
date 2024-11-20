#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<int, string> longestCommonSubstring(string X, string Y) {
    int m = X.size();
    int n = Y.size();

    // DP table to store lengths of common substrings
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxLength = 0; // Maximum length of common substring
    int endIndex = 0;  // Ending index of the common substring in X

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i; // Update the ending index of the substring in X
                }
            } else {
                dp[i][j] = 0; // Reset if characters don't match
            }
        }
    }

    // Extract the longest common substring
    string lcs = X.substr(endIndex - maxLength, maxLength);

    return {maxLength, lcs};
}

int main() {
    string X = "ABABC";
    string Y = "BABCAC";

    auto result = longestCommonSubstring(X, Y);

    cout << "Length of Longest Common Substring: " << result.first << endl;
    cout << "Longest Common Substring: " << result.second << endl;

    return 0;
}
