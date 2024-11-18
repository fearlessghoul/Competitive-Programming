#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int performOperation(char operation, int a, int b){
    switch (operation){
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

int evalPostfix(const string &expression){
    stack<int> s;
    stringstream ss(expression);
    string token;

    int operandCount = 0, operatorCount = 0;
    while (ss >> token){
        if (isOperator(token[0])){
            if (s.size() < 2)
                throw invalid_argument("Invalid Expression");
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            s.push(performOperation(token[0], a, b));
            operatorCount++;
        }
        else{
            s.push(stoi(token));
            operandCount++;
        }
    }
    return operandCount == operatorCount + 1 ? s.top() : throw invalid_argument("Invalid Expression");
}

int main(){
    string expr = "5 3 + 8 * 6";
    try{
        cout << "Evaluated: " << evalPostfix(expr) << endl;
    }
    catch (const exception &ex){
        cerr << "Error: " << ex.what() << endl;
    }
    return 0;
}
