#include <bits/stdc++.h>
using namespace std;
int precedence(char op){
    if (op == '^')
        return 3;
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
int associativity(char op){
    if (op == '^')
        return 0;
    return 1;
}
string infixToPostfix(const string &expression){
    stack<char> s;
    string result;

    for (char c : expression){
        if (isspace(c))
            continue;
        else if (isalnum(c))
            result += c;
        else if (c == '(')
            s.push(c);
        else if (c == ')'){
            while (!s.empty() && s.top() != '('){
                result += s.top();
                s.pop();
            }
            if (!s.empty()) {
                s.pop();
            }
        }
        else{
            while (!s.empty() && (precedence(s.top()) > precedence(c) || !associativity(c) && precedence(s.top()) == precedence(c))){
                result += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()){
        result += s.top();
        s.pop();
    }

    return result;
}
string reverseAndSwapParentheses(string reversed){
    reverse(reversed.begin(), reversed.end());

    for (size_t i = 0; i < reversed.size(); i++){
        if (reversed[i] == '('){
            reversed[i] = ')';
        }
        else if (reversed[i] == ')'){
            reversed[i] = '(';
        }
    }
    return reversed;
}
string infixToPrefix(const string &expression){
    string reversedExpression = reverseAndSwapParentheses(expression);
    string postfixExpression = infixToPostfix(reversedExpression);
    reverse(postfixExpression.begin(), postfixExpression.end());
    return postfixExpression;
}

int main(){
    string infixExpr1 = "2^3^4";
    string infixExpr2 = "A + B * C - D / E";

    cout << "Infix Expression 1: " << infixExpr1 << endl;
    cout << "Prefix Expression 1: " << infixToPrefix(infixExpr1) << endl;

    cout << "Infix Expression 2: " << infixExpr2 << endl;
    cout << "Prefix Expression 2: " << infixToPrefix(infixExpr2) << endl;

    return 0;
}