#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string countAndSay(int n){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if (n == 1)
            return "1";
        string ans = "1";
        int len;
        int m;
        for (int i = 1; i < n; i++){
            len = ans.length();
            string rela(len, ' ');
            string mapper(len, '0');
            rela[0] = ans[0];
            mapper[0]++;
            m = 0;
            for (int j = 1; j < len; j++){
                if (ans[j] != ans[j - 1]){
                    rela[++m] = ans[j];
                }
                mapper[m]++;
            }
            string res(2 * (m + 1), ' ');
            for (int j = 0; j <= m; j++){
                res[2 * j] = mapper[j];
                res[2 * j + 1] = rela[j];
            }
            ans = res;
        }
        return ans;
    }
};
int main(){
    Solution a;
    cout << a.countAndSay(29).length() << endl;
}