#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool canJump(const vector<int> &nums){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int fill = 1, n = nums.size();
        if (n == 1)
            return true;
        for (int i = 0; i < n; i++){
            fill--;
            if (nums[i] > fill){
                fill = nums[i];
            }
            if (fill == 0 && i < n - 1)
                return false;
        }
        return true;
    }
};
int main(){
    Solution a;
    bool res = a.canJump({2, 3, 1, 1, 4});
    cout << res << endl;
}