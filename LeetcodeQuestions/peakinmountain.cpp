#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums{2,1};

    int ans, mid;
    int left = 0, right = nums.size() - 1;
    if(right==0)return 0;
    while (left <= right){
        mid = left + (right - left) / 2;
        cout<<mid<<endl;
        if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1]){
            ans = mid + 1;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
