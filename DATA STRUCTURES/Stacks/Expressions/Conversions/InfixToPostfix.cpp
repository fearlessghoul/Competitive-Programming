#include <bits/stdc++.h>
using namespace std;
int precedence(char op){
    if (op == '^')
        return 6;
    if (op == '*' || op == '/' || op == '%')
        return 5;
    if (op == '+' || op == '-')
        return 4;
    if (op == '&') // AND
        return 3;
    if (op == 'x') // xor
        return 2;
    if (op == '|') // or
        return 1;
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
            if (!s.empty()){
                s.pop();
            }
        }
        else{
            while (!s.empty() && (precedence(s.top()) > precedence(c) || associativity(c) && precedence(s.top()) == precedence(c))){
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

int main(){
    string exp = "(1+(4+5+2)-3)+(6+8)";
    try{
        cout << "Postfix: " << infixToPostfix(exp) << endl;
    }
    catch (const exception &ex){
        cerr << "Error: " << ex.what() << endl;
    }
    return 0;
}
