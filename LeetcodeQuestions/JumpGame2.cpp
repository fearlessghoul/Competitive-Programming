#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int jump(const vector<int> &nums){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int minm;
        int n = nums.size();
        if (n == 1)
            return 0;
        int *dp = new int[n],limit;
        dp[n-1]=0;
        for (int i = n - 2; i >= 0; i--){
            minm = INT_MAX;
            limit=i + nums[i];
            for (int j = i + 1; j < n && j <= limit; j++){
                minm = min(minm, dp[j]);
            }
            dp[i] = 1 + minm;
        }
        return dp[0];
    }
};
int main(){
    Solution a;
    int res = a.jump({2, 3, 1, 1, 4});
    // cout << res << endl;
}