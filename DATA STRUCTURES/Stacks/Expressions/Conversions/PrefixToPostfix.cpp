#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string prefixToPostfix(const string &prefix){
    stack<string> s;

    for (int i = prefix.length() - 1; i >= 0; i--){
        char c = prefix[i];

        if (isalnum(c)){
            s.push({c});
        }
        else if (isOperator(c)){
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();
            s.push(operand1 + operand2 + c);
        }
    }
    return s.top();
}

int main(){
    string prefixExpr1 = "*+AB-CD";     // Postfix: AB+CD-*
    string prefixExpr2 = "*-A/BC-/AKL"; // Postfix: ABC/-AK/L-*

    cout << "Prefix Expression 1: " << prefixExpr1 << endl;
    cout << "Postfix Expression 1: " << prefixToPostfix(prefixExpr1) << endl;

    cout << "Prefix Expression 2: " << prefixExpr2 << endl;
    cout << "Postfix Expression 2: " << prefixToPostfix(prefixExpr2) << endl;

    return 0;
}
