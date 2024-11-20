#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    long long findMaximumScore(const vector<int> &nums){
        long long ans = 0;
        int mx=0;
        for (int i = 0; i + 1 < nums.size(); i++){
            mx = max(mx, nums[i]);
            ans += mx;
        }
        return ans;
    }
};
int main(){
    Solution a;
    int res = a.findMaximumScore({1, 3, 1, 5});
    cout << res << endl;
}