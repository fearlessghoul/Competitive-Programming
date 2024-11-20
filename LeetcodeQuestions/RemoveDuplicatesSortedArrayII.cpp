#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        
        int k = 2;
        for (int j = 2; j < nums.size(); ++j) {
            if (nums[j] != nums[k - 2]) {
                nums[k++] = nums[j];
            }
        }
        return k;
    }
};
int main(){
    Solution a;
    vector<int> nums{1, 1};
    int res = a.removeDuplicates(nums);
    cout<<res<<endl;
    for (int i = 0; i < res; i++)
        cout << nums[i] << endl;
}