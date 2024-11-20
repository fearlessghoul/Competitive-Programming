#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    void getSolutions(string &s, vector<string> &segments, vector<string> &wordDict, vector<string> &res, bool **dp, int start){
        if (start == s.length()){
            if (segments.size() == 0)
                return;
            string ip = segments[0];
            for (int i = 1; i < segments.size(); ++i){
                ip += " " + segments[i];
            }
            res.push_back(ip);
            return;
        }
        for (int i = 0; i <= s.length(); i++){
            if (dp[start][i]){
                segments.push_back(s.substr(start, i - start));
                getSolutions(s, segments, wordDict, res, dp, i);
                segments.pop_back();
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string> &wordDict){
        bool **dp = new bool *[s.length() + 1];
        for (int i = 0; i <= s.length(); i++)
            dp[i] = new bool[s.length() + 1]{};
        bool *dp2 = new bool[s.length() + 1];
        dp2[0]=true;
        for (int i = 1; i <= s.length(); i++){
            for (const string &w : wordDict){
                int start = i - w.length();
                if (start >= 0 && dp2[start] && s.substr(start, w.length()) == w){
                    dp2[i] = true;
                    dp[start][i] = true;
                }
            }
        }
        vector<string> res;
        vector<string> segments;
        getSolutions(s, segments, wordDict, res, dp, 0);
        return res;
    }
};
int main(){
    Solution a;
    vector<string> wordDict{"cat","cats","and","sand","dog"};
    for (auto it : a.wordBreak("catsanddog", wordDict)){
        cout << it << endl;
    }
}