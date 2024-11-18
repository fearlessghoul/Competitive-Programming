#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c){
    return (c == '+' || c == '^'|| c == '-' || c == '*' || c == '/');
}

bool isPrefix(const std::string &expression){
    std::stack<char> s;
    int operandCount = 0, operatorCount = 0;
    for (auto token = expression.rbegin(); token != expression.rend(); ++token){
        if (isOperator(*token)){
            if (s.size() < 2)
                return false;
            s.pop();
            operatorCount++;
        }
        else{
            s.push(*token);
            operandCount++;
        }
    }
    return operandCount == operatorCount + 1;
}

int main(){
    string expr = "-+A*BCD";
    cout << (isPrefix(expr) ? "Valid Prefix" : "Invalid Prefix") << endl;
    return 0;
}
