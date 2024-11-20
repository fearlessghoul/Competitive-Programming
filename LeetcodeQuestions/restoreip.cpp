#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool valid(const string& segment) {
        int m = segment.length();
        if (m > 3) return false;
        if (segment[0] == '0') {
            return m == 1;
        }
        return stoi(segment) <= 255;
    }
    void backtrack(int prevDot, int dots,int n, string& s,vector<string>& segments,vector<string> & result) {
        int maxPos = min(n - 1, prevDot + 4);
        for (int currDot = prevDot + 1; currDot < maxPos; ++currDot) {
            segments[3-dots] = s.substr(prevDot + 1, currDot - prevDot);
            if (valid(segments[3-dots])) {
                cout<<"valid string"<<dots<<endl;
                if (dots == 1){

                    segments[3] = s.substr(currDot + 1, n - currDot - 1);
                    if (valid(segments[3])) {
                        string ip = segments[0];
                        for (size_t i = 1; i < segments.size(); ++i) {
                            ip += "." + segments[i];
                        }
                        result.push_back(ip);
                    }
                }
                else{
                    backtrack(currDot, dots - 1,n,s,segments,result);
                }
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        int n=s.length();
        vector<string> result;
        vector<string> segments(4,"");
        backtrack(-1, 3,n,s,segments,result);
        return result;
    }
};
int main(){
    Solution a;
    for(string st:a.restoreIpAddresses("255255255255"))
        cout<<st<<endl;
    
}