#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int getLucky(string s, int k){
        int res = 0, sum = 0;
        int c;
        for (char ch:s){
            c=ch-96;
            sum += c%10 + c/10;
        }
        res = sum;
        sum = 0;
        for (int i = 1; i < k; i++){
            while (res != 0){
                sum += res % 10;
                res /= 10;
            }
            res = sum;
            sum = 0;
        }
        return res;
    }
};
int main(){
    Solution a;
    int res = a.getLucky("leetcode", 2);
    cout << res << endl;
}