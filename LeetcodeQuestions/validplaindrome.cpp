#include <bits/stdc++.h>
using namespace std;
bool tocheck(){
    string s = ".,"; // abcabcbb
    int l = 0, r = s.length() - 1;
    while (l < r){
        while (!isalnum(s[l]) && l < r)
            l++;
        while (!isalnum(s[r]) && l < r)
            r--;
        if(l>=r){
            return true;
        }
        if (tolower(s[l]) != tolower(s[r])){
            return false;
        }
        else{
            l++;
            r--;
        }
    }
    return true;
}

int main(){
    cout << tocheck() << endl;
}