#include <bits/stdc++.h>
#include <vector>
using namespace std;
bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*');
}
// void genrateprans(int n, int left, int right, string &current, vector<int> &result)
// {
//     if (right == n)
//     {
//         result.push_back(current);
//         return;
//     }
//     else
//     {
//         if (left < n)
//         {
//             current.push_back('(');
//             genrateprans(n, left + 1, right, current, result);
//             current.pop_back();
//         }
//         if (left > right)
//         {
//             current.push_back(')');
//             genrateprans(n, left, right + 1, current, result);
//             current.pop_back();
//         }
//     }
// }
int charToInt(char ch){
    switch (ch){
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    default:
        return -1;
    }
}
int main(){
    string current = "2*3-4*5";
    string ans(current.length(), 0);
    string ans2(current.length(), 0);
    int a = 0, b = 0, i = 0;
    while (i < current.length()){
        int value = 0;
        while (i < current.length() && !isOperator(current[i])){
            value = value*10 + charToInt(current[i++]);
        }
        current[a++] = value;
        ans[b++] = current[i++];
    }
    // vector<int> result;
    // genrateprans(3, 0, 0, current, result);
    // for(int in:result) cout<<in<<" ";
    return 0;
}
