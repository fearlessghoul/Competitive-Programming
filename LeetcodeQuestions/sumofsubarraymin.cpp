#include <bits/stdc++.h>
using namespace std;
class Solution{
    vector<int> prev_smaller_idx(vector<int> &arr, int n){
        vector<int> ans(n,-1);
        int j;
        for (int i = 1; i < n; i++){
            for(j=i-1;j >=0;j--){
                if(arr[j] < arr[i]){
                    ans[i]=j;
                    break;
                }
            }
        }
        return ans;
    }
    vector<int> next_smaller_idx(vector<int> &arr, int n){
        vector<int> ans(n,n);
        int j;
        for (int i = 0; i< n-1; i++){
            for(j=i+1;j < n;j++){
                if(arr[j] <= arr[i]){
                    ans[i]=j;
                    break;
                }
            }
        }
        return ans;
    }

public:
    int sumSubarrayMins(vector<int> &arr){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> prev(n);
        vector<int> next(n);
        prev = prev_smaller_idx(arr, n);
        next = next_smaller_idx(arr, n);
        long long sum = 0;
        for (int i = 0; i < n; i++){
            long long left = (i - prev[i]);
            long long right = (next[i] - i);
            sum = (sum + (left * right * arr[i]) % mod) % mod;
        }
        return sum;
    }
};
int main(){
    Solution a;
    vector<int> arr{3,1,2,4};
    int res = a.sumSubarrayMins(arr);
    cout << res << endl;
}