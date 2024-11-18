#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string postfixToInfix(const string &postfix){
    stack<string> s;

    for (size_t i = 0; i < postfix.length(); i++){
        char c = postfix[i];

        if (isalnum(c)){
            s.push({c});
        }
        else if (isOperator(c)){
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            s.push("(" + operand1 + c + operand2 + ")");
        }
    }
    return s.top();
}

int main(){
    string postfixExpr1 = "AB+C*";       // Infix: (A + B) * C
    string postfixExpr2 = "ABC/-AK/L-*"; // Infix: ((A - (B / C)) * (A / (K - L)))

    cout << "Postfix Expression 1: " << postfixExpr1 << endl;
    cout << "Infix Expression 1: " << postfixToInfix(postfixExpr1) << endl;

    cout << "Postfix Expression 2: " << postfixExpr2 << endl;
    cout << "Infix Expression 2: " << postfixToInfix(postfixExpr2) << endl;

    return 0;
}
