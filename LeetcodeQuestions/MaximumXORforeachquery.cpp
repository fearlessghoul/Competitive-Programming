#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int> ans(n,0);
        for(int i=1;i<n;i++){
            ans[n-i]=nums[i];
            nums[i]=nums[i-1]^nums[i];
        }
        ans[0]=nums[n-1]^((1<<maximumBit)-1);
        for(int i=1;i<n;i++){
            ans[i]^=ans[i-1];
        }
        return ans;
    }
};
int main(){
    Solution a;
    vector<int> wordDict{2,3,4,7};
    vector<int> ans=a.getMaximumXor(wordDict,3);
    for(int c:ans){
        cout<<c<<" ";
    }
    cout<<endl;

}