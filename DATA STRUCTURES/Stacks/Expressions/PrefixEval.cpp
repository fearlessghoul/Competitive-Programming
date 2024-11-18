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
int evalPrefix(const string &expression){
    stack<int> s;
    stringstream ss(expression);
    string token;
    vector<string> tokens;
    int operandCount = 0, operatorCount = 0;
    while (ss >> token){
        tokens.push_back(token);
    }
    for (auto token = tokens.rbegin(); token != tokens.rend(); ++token){
        if (isOperator((*token)[0])){
            if (s.size() < 2)
                return false;
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(performOperation((*token)[0], a, b));
            operatorCount++;
        }
        else{
            s.push(stoi(*token));
            operandCount++;
        }
    }
    return operandCount == operatorCount + 1 ? s.top() : throw invalid_argument("Invalid Expression");
}

int main(){
    string expr = "- * + 5 3 8 6";
    try{
        cout << "Evaluated: " << evalPrefix(expr) << endl;
    }
    catch (const exception &ex){
        cerr << "Error: " << ex.what() << endl;
    }
    return 0;
}
