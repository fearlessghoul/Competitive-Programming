#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0) return false;
        for(int i=1;i<k;i++){
            if(nums[i]==nums[i-1]){
                return true;
            }
        }
        for(int i=0;i+k<nums.size();i++){
            if(nums[i]==nums[i+k]){
                return true;
            }
        }
        return false;
    }
};
int main(){
    Solution a;
    vector<int> obstacleGrid{0,1,2,3,2,5};
    cout<<a.containsNearbyDuplicate(obstacleGrid,3)<<endl;
}