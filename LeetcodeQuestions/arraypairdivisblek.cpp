#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool canArrange(vector<int> &arr, int k){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> memo(k, 0);
        for (int i = 0; i < arr.size(); i++)
            memo[(arr[i] % k + k) % k]++;
        for (int i = 1; i <= k / 2; i++){
            cout << memo[i] << " " << memo[k - i] << endl;

            if (memo[i] != memo[k - i])
                return false;
        }

        return true;
    }
};
int main(){
    Solution a;
    vector<int> arr{-1, -1, -1, -1, 2, 2, -2, -2};
    int res = a.canArrange(arr, 3);
    cout << res << endl;
}