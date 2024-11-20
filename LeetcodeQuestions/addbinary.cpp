#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int toInt(char c){
        return c=='0'?0:1;
    }
    string addBinary(string a, string b){
        int i=a.length()-1,j=b.length()-1,s,c=0;
        int maxlength=max(a.length(),b.length());
        char* ans= new char[max(a.length(),b.length())+2]{};
        while(i>=0 && j>=0){
            s=toInt(a[i])^toInt(b[j])^c;
            c=toInt(a[i])&toInt(b[j])|c&(s^c);
            ans[maxlength--]=s +'0';
            i--;
            j--;
        }
        while(i>=0 && c){
            s=toInt(a[i])^c;
            c=toInt(a[i])&c;
            ans[maxlength--]= s +'0';
            i--;
        }
        while(j>=0 && c){
            s=toInt(b[j])^c;
            c=toInt(b[j])&c;
            ans[maxlength--]= s +'0';
            j--;
        }
        if(!c){
            while(i>=0){
                ans[maxlength--]= a[i--];
            }
            while(j>=0){
                ans[maxlength--]= b[j--];
            }
            return ans+1;
        }
        ans[maxlength--]='1';
        return ans;
    }
};
int main(){
    Solution a;
    string res = a.addBinary("100","110010");
    cout << res << endl;
}