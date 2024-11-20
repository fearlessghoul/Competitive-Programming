#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,m=haystack.length(),n=needle.length();
        while(i < m){
            while(i< m && haystack[i]!=needle[0])i++;
            if(i+n > m) return -1;
            bool found=true;
            for(int j=0;j < n;j++){
                if(needle[j] !=haystack[i+j]){
                    found=false;
                }
            }
            if(found) return i;
            i++;
        }
        return -1;
    }
};
int main(){
    Solution a;
    cout << a.strStr("leetcode","leeto") << endl;
}