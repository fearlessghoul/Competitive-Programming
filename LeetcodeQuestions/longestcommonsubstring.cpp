#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestPalindromicSubstring(const string &s){
    int n = s.size();
    if (n == 0)
        return "";

    // Initialize a 2D DP table
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int start = 0;     // Start index of the longest palindrome
    int maxLength = 1; // Length of the longest palindrome

    // Every single character is a palindrome
    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    // Check for sub-strings of length 2
    for (int i = 0; i < n - 1; ++i){
        if (s[i] == s[i + 1]){
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2
    for (int length = 3; length <= n; ++length){
        for (int i = 0; i < n - length + 1; ++i){
            int j = i + length - 1; // Ending index of the current substring

            // Check if the current substring is a palindrome
            if (s[i] == s[j] && dp[i + 1][j - 1]){
                dp[i][j] = true;
                start = i;
                maxLength = length;
            }
        }
    }

    // Return the longest palindromic substring
    return s.substr(start, maxLength);
}

int main(){
    string s = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindromicSubstring(s) << endl;
    // Output can be "bab" or "aba"
    return 0;
}
