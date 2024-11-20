#include <bits/stdc++.h>
using namespace std;

int main(){
    int number;
    cin >> number;
    int left = 0, right = number, mid, ans;
    while (left <= right){
        mid = left + (right - left) / 2;
        if (mid * mid == number){
            ans = mid;
            break;
        }
        if (mid * mid < number){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << ans << endl;
}