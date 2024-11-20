#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int charToInt(char ch) {
        switch(ch) {
            case '0': return 0;
            case '1': return 1;
            case '2': return 2;
            case '3': return 3;
            case '4': return 4;
            case '5': return 5;
            case '6': return 6;
            case '7': return 7;
            case '8': return 8;
            case '9': return 9;
            default:
                return -1;
        }
    }
    bool valid(string& s, int a,int b){
        if(s[a] == '0') return false;
        if(a==b) return charToInt(s[a]) != -1;
        return (10*charToInt(s[a]) + charToInt(s[b]))  < 27;
    };

    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n=s.length();
        if(n==1) return s[0] != '0';
        int**dp = new int*[n]{};
        for(int i=0;i<n;i++) dp[i]=new int[n]{};
        dp[0][0]=valid(s,0,0);
        dp[0][1]=valid(s,0,1);
        dp[1][1]=valid(s,1,1) ? dp[0][0] : 0 ;
        if(n==2) return dp[1][1] + dp[0][1];
        dp[1][2]=valid(s,1,2) ? dp[0][0] : 0 ;
        for (int i = 2; i < n; i++){
            dp[i][i]=valid(s,i,i) ? dp[i-1][i-1] + dp[i-2][i-1] : 0;
            if(i+1<n){
                dp[i][i+1]=valid(s,i,i+1) ? dp[i][i] : 0;
            }
        }
        return dp[n-1][n-1] + dp[n-2][n-1];
    }
};
int main(){
    Solution a;
    int res = a.numDecodings("10");
    cout << res << endl;
}