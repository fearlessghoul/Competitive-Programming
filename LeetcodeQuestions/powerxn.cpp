#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    double myPow(double x,int n){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if (x == 1)
            return 1;
        int m = abs(n);
        double res = 1;
        while (m > 0){
            if (m & 1)
                res *= x;
            x *= x;
            m >>= 1;
        }
        if(n<0) return 1.0/res;
        
        return res;
    }
};
int main(){
    Solution a;
    double res = a.myPow(2, -2147483648);
    cout << res << endl;
}