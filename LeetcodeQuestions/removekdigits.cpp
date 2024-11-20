#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;
class Solution{
public:
    string removeKdigits(string num, int k){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = num.length();
        if (k == n)
            return "0";
    }
};
int main(){
    Solution a;
    string res = a.removeKdigits("1432219", 3);
    cout << res << endl;
}