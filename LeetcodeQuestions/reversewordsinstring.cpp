#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    string reverseWords(string s){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> mapped;
        int i = 0, n = s.length(), l;
        int size = 0;
        while (i < n){
            while (i < n && s[i] == ' ')
                i++;
            l = i;
            while (i < n && s[i] != ' ')
                i++;
            if (l != i){
                size += (i - l);
                mapped.push_back({l, i});
            }
        }
        int mapsize = mapped.size();
        size += mapsize - 1;
        string res(size, ' ');
        l = 0;
        for (int i = mapsize - 1; i >= 0; i--){
            for (int j = mapped[i][0]; j < mapped[i][1]; j++){
                res[l++] = s[j];
            }
            if (i != 0)
                l++;
        }
        return res;
    }
};
int main(){
    Solution a;
    string res = a.reverseWords("  hello world  ");
    cout << res << endl;
}