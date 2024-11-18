#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c){
    return (c == '+' || c == '^' || c == '-' || c == '*' || c == '/');
}

bool isPostfix(const string &expression){
    stack<char> s;
    int operandCount = 0, operatorCount = 0;
    for (char token : expression){
        if (isOperator(token)){
            if (s.size() < 2)
                return false;
            s.pop();
            operatorCount++;
        }
        else{
            s.push(token);
            operandCount++;
        }
    }
    return operandCount == operatorCount + 1;
}

int main(){
    string expr;
    cout << "Enter Postfix Expression: ";
    cin >> expr;
    cout << (isPostfix(expr) ? "Valid Postfix" : "Invalid Postfix") << endl;
    return 0;
}
