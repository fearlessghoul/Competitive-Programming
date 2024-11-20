#include <bits/stdc++.h>
using namespace std;
bool isValid(string s){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int len = s.length(), i = -1;
    string temp(len, ' ');
    for (char c : s){
        switch (c){
        case ')':
            if (i != -1 && temp[i] == '('){
                i--;
            }
            else{
                return false;
            }
            break;

        case '(':
            temp[++i] = c;
            break;

        case '}':
            if (i != -1 && temp[i] == '{'){
                i--;
            }
            else{
                return false;
            }
            break;

        case '{':
            temp[++i] = c;
            break;

        case ']':
            if (i != -1 && temp[i] == '['){
                i--;
            }
            else{
                return false;
            }
            break;

        case '[':
            temp[++i] = c;
            break;

        default:
            break;
        }
    }
    return i == -1 ? true : false;
}

int main(){
    cout << isValid("()[]{}") << endl;
}