#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int index, int& helper, int& minNUm, string s,bool **isPalindrome) {
        if (index >= s.size()) {
            minNUm=min(minNUm,helper);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome[index][i]) {
                helper++;
                solve(i + 1, helper, minNUm, s,isPalindrome);
                helper--;
            }
        }
    }

    int minCut(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = s.length();
        bool **isPalindrome = new bool *[n];
        for (int i = 0; i < n; ++i){
            isPalindrome[i] = new bool[n]{};
            isPalindrome[i][i] = true;
        }
        for (int i = 0; i < n - 1; ++i){
            if (s[i] == s[i + 1]){
                isPalindrome[i][i + 1] = true;
            }
        }
        for (int length = 3; length <= n; ++length){
            for (int i = 0; i < n - length + 1; ++i){
                int j = i + length - 1;
                if (s[i] == s[j] && isPalindrome[i + 1][j - 1]){
                    isPalindrome[i][j] = true;
                }
            }
        }
        int helper=0;
        int minNUm=INT_MAX;
        solve(0, helper, minNUm, s,isPalindrome);
        return minNUm-1;
    }
};
int main(){
    Solution a;
    int res = a.minCut("ab");
    cout<<res<<endl;
}