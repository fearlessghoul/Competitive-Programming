#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool validPalindrome(){
        string s = "cupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupucu";
        int l = 0, r = s.length() - 1, c = 0;
        if (r < 2)
            return true;
        while (l <= r){
            if (s[l] == s[r]){
                l++;
                r--;
            }
            else{
                return check(s, l, r - 1) || check(s, l + 1, r);
            }
        }
        return true;
    }
    bool check(string s, int l, int r){
        while (l <= r){
            if (s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
int main(){
    Solution a;
    cout << a.validPalindrome() << endl;
}