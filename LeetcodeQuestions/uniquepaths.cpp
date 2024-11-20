#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int numIdenticalPairs(const vector<int> &nums){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                count += (nums[i] == nums[j]);
            }
        }
        return count;
    }
};
int main(){
    Solution a;
    int res = a.numIdenticalPairs({1, 2, 3, 1, 1, 3});
    cout << res << endl;
}