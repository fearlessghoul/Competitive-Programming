#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int getVal(char c){
        switch (c){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
        }
    }
    int romanToInt(string s){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int max = INT_MIN;
        int num = 0, temp;
        for (int i = s.length() - 1; i >= 0; i--){
            temp = getVal(s[i]);
            if (temp < max){
                num -= temp;
            }
            else{
                max = temp;
                num += max;
            }
        }
        return num;
    }
};
int main(){
    Solution a;
    cout << a.romanToInt("DCXXI") << endl;
}