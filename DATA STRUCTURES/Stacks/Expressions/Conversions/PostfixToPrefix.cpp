#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/'|| c=='^');
}

string postfixToPrefix(const string& postfix) {
    stack<string> s;

    for (size_t i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isalnum(c)) {
            s.push({c});
        }
        else if (isOperator(c)) {
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            s.push(c + operand1 + operand2);
        }
    }
    return s.top();
}

int main() {
    string postfixExpr1 = "234^^";  // Prefix: *+ABC
    string postfixExpr2 = "ABC/-AK/L-*";  // Prefix: *-A/BC-/AKL

    cout << "Postfix Expression 1: " << postfixExpr1 << endl;
    cout << "Prefix Expression 1: " << postfixToPrefix(postfixExpr1) << endl;

    cout << "Postfix Expression 2: " << postfixExpr2 << endl;
    cout << "Prefix Expression 2: " << postfixToPrefix(postfixExpr2) << endl;

    return 0;
}
