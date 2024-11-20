#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minsizesubsum(int target, vector<int> &nums){
    int n = nums.size(), l = 0, r = 0, currlen = 0, ans = __INT_MAX__, sum = 0;
    while (l < n && l<=r){
        if(sum<target){
            if(l==0 && r==n) return 0;
            if(r==n) break;
            sum+=nums[r];
            r++;
        }else{
            sum-=nums[l];
            l++;
            ans = min(r-l+1,ans);
        }
    }
    return ans;
}

int main(){
    int target = 4;
    vector<int> nums = {1, 4, 4};
    cout << minsizesubsum(target, nums) << endl;
    return 0;
}
