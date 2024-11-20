#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    void generateParams(int n, int left, int right, string &current, vector<string> &result,int i,int& j){
        if (right == n){
            result[j++]=current;
            return;
        }
        if (left < n){
            current[i]='(';
            generateParams(n, left + 1, right, current, result,i+1,j);
        }
        if (left > right){
            current[i]=')';
            generateParams(n, left, right + 1, current, result,i+1,j);
        }
    }
    unsigned long validparams(int n){
        unsigned long catalan[n + 1]{};
        catalan[0] = catalan[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++)
                catalan[i] += catalan[j] * catalan[i - j - 1];
        }
        return catalan[n];
    }
    vector<string> generateParenthesis(int n) {
        string current(2*n,' ');
        int num=0;
        vector<string> ans(validparams(n));
        generateParams(n, 0, 0, current, ans,0,num);
        return ans;
    }
};

int main(){
    Solution a;
    vector<string> ans=a.generateParenthesis(3);
    for(string str:ans) cout<<str<<" ";
    return 0;
}
