#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(vector<vector<string>> &result, vector<string> &sol, int j, int n, bool *rows, bool (*diag)[2]){
        if (j == n){
            result.push_back(sol);
            return;
        }

        for (int i = 0; i < n; ++i){
            int d2=i - j + n - 1;
            if (!rows[i] && !diag[i + j][0] &&
                !diag[d2][1]){
                rows[i] = diag[i + j][0] = diag[d2][1] = true;
                sol[i][j]='Q';
                solve(result, sol, j+1, n, rows, diag);
                sol[i][j]='.';
                rows[i] = diag[i + j][0] = diag[d2][1] = false;
            }
        }
    };
    vector<vector<string>> solveNQueens(int n){
        if (n == 1)
            return {{"Q"}};
        if (n < 4)
            return {};
        vector<string> sol(n, string(n, '.'));
        vector<vector<string>> result;
        bool *rows = new bool[n]{};
        bool(*diag)[2] = new bool[2 * n][2]{};
        solve(result, sol, 0, n, rows, diag);
        return result;
    }
};
int main(){
    Solution a;
    int n = 4;

    vector<vector<string>> result = a.solveNQueens(n);

    for (auto &res : result){
        for (int i = 0; i < n; ++i){
            cout << res[i] << endl;
        }
        cout << endl;
    }
    return 0;
}
