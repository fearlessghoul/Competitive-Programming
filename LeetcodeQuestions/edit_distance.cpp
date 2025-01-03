#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minDistance(string word1, string word2) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int m=word1.length(),n=word2.length();
        int** dp= new int*[m+1];
        for(int i=0;i<=m;i++) dp[i]=new int[n+1]{};
        for (int i = 0; i <=m; i++)
            for (int j = 0; j <=n; j++)
                if(i==0)dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
                else if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1 + min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
        return dp[m][n];
    }
};
int main(){
    Solution a;
    int res = a.minDistance("geek","geesk");
    cout << res << endl;
}