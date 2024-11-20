#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string prefixToInfix(const string& prefix) {
    stack<string> s;
    
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)){
            s.push({c});
        }
        else if (isOperator(c)){
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();
            s.push("(" + operand1 + c + operand2 + ")");
        }
    }
    return s.top();
}

int main() {
    string prefixExpr1 = "*+AB-CD";  // Infix: ((A+B)*(C-D))
    string prefixExpr2 = "*-A/BC-/AKL";  // Infix: ((A - (B / C)) * ((A / K) - L))

    cout << "Prefix Expression 1: " << prefixExpr1 << endl;
    cout << "Infix Expression 1: " << prefixToInfix(prefixExpr1) << endl;

    cout << "Prefix Expression 2: " << prefixExpr2 << endl;
    cout << "Infix Expression 2: " << prefixToInfix(prefixExpr2) << endl;

    return 0;
}
