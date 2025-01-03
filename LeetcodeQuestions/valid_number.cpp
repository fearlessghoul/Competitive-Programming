#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        bool s1,s2,bd,ad,num,dot,exp;
        s1=s2=bd=ad=num=dot=exp=false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='+'|| s[i]=='-') {
                if(exp){
                    if(s2 || num)return false;
                    else s2=true;
                }else{
                    if(s1|| bd || dot||ad) return false;
                    else s1=true;
                }
            }
            else if(s[i]=='.'){
                if(exp || dot) return false;
                dot=true;
            }
            else if(s[i]=='e'||s[i]=='E'){
                if(exp) return false;
                else exp=true;
            }
            else if(isdigit(s[i])){
                while(i<s.length() && isdigit(s[i]))i++;
                i--;
                if(exp) num=true;
                else{
                    if(bd||dot) ad=true;
                    else bd=true;
                }
            }else return false;
        }
        return (bd|| dot&&ad)&&(!exp || exp&&num);
    }
};
int main(){
    Solution a;
    vector<string> test{"2", ".", "e", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
    for(string c:test) cout<<a.isNumber(c)<<endl;
    // cout<<a.isNumber(".")<<endl;
    return 0;
}