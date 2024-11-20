#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
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
    int evalRPN(vector<string> &tokens){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = tokens.size();
        int *HelperArray = new int[n];
        int j = -1;
        for (int i = 0; i < n; i++){
            if (tokens[i].length() == 1 && isOperator(tokens[i][0])){
                int b = HelperArray[j--];
                HelperArray[j] = performOperation(tokens[i][0], HelperArray[j], b);
                cout << j << " : " << HelperArray[j] << endl;
            }
            else{
                HelperArray[++j] = stoi(tokens[i]);
                cout << j << ": " << HelperArray[j] << endl;
            }
        }
        return HelperArray[0];
    }
};
int main(){
    Solution a;
    vector<string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int res = a.evalRPN(tokens);
    cout << res << endl;
}