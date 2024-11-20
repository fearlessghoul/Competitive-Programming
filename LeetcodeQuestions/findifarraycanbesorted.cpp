#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool swappable(int a, int b){
        int r1 = a&1, r2 = b&1;
        while (a >>= 1)if(a&1)r1++;
        while (b >>= 1)if(b&1) r2++;
        return r1 == r2;
    }
    bool canSortArray(vector<int> &nums){
        int right = nums.size() - 1;
        bool isSorted = false;
        while (!isSorted){
            isSorted = true;
            for (int j = 0; j < right; j++){
                if (nums[j] > nums[j + 1]){
                    isSorted = false;
                    if (!swappable(nums[j], nums[j + 1])){
                        return false;
                    }
                    else{
                        swap(nums[j], nums[j + 1]);
                    }
                }
            }
        }
        return true;
    }
};
int main(){
    Solution a;
    vector<int> sol{1,2,3,4,5};
    bool res = a.canSortArray(sol);
    cout << res << endl;
}