#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int lengthOfLastWord(string s){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int i = s.length() - 1, k = 0;
        while (s[i] == ' ' && i >= 0)
            i--;
        while (s[i] != ' ' && i >= 0){
            k++;
            i--;
        }
        return k;
    }
};
int main(){
    Solution a;
    int res = a.lengthOfLastWord("a");
    cout << res << endl;
}