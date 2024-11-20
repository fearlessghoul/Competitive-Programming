#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool almostequal(int a, int b){
        int aa = -1, bb = -1;
        while (a > 0 || b > 0){
            if (a % 10 == b % 10){
                a /= 10;
                b /= 10;
            }
            else if (aa == -1){
                aa = a % 10;
                bb = b % 10;
                a /= 10;
                b /= 10;
            }
            else if (aa != -2){
                if (aa == b % 10 && bb == a % 10){
                    aa = -2;
                    bb = -2;
                    a /= 10;
                    b /= 10;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return aa < 0;
    }
    int countPairs(vector<int> &nums){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int size = nums.size(), count = 0;
        for (int i = 0; i < size; i++){
            for (int j = i + 1; j < size; j++){
                count += almostequal(nums[i], nums[j]);
            }
        }
        return count;
    }
};
int main(){
    Solution a;
    vector<int> nums{1, 1, 1, 1, 1};
    cout << a.countPairs(nums) << endl;
}