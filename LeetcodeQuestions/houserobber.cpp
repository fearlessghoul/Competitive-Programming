#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int recursive(const vector<int> &nums, int i, const int &n,vector<int>& memo){
        if (i >= n){
            return 0;
        }
        if(memo[i] == -1){
            memo[i] = nums[i] + max(recursive(nums, i + 2, n, memo),recursive(nums, i + 3, n, memo));
        }
        return memo[i];
    }
    int rob(const vector<int> &nums){
        vector<int> memo(nums.size(),-1);
        return max(recursive(nums, 0, nums.size(),memo),recursive(nums, 1, nums.size(),memo));
    }
};
int main(){
    Solution a;
    int res = a.rob({2,7,9,3,1,2,7,9,3,1});
    cout << res << endl;
}