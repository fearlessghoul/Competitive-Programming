#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(int &result, int j, int n, bool *rows, bool (*diag)[2]){
        if (j == n){
            result++;
            return;
        }

        for (int i = 0; i < n; ++i){
            int d2=i - j + n - 1;
            if (!rows[i] && !diag[i + j][0] &&
                !diag[d2][1]){
                rows[i] = diag[i + j][0] = diag[d2][1] = true;
                solve(result, j+1, n, rows, diag);
                rows[i] = diag[i + j][0] = diag[d2][1] = false;
            }
        }
    };
    int totalNQueens(int n){
        if (n == 1)
            return 1;
        if (n < 4)
            return {};
        int result;
        bool *rows = new bool[n]{};
        bool(*diag)[2] = new bool[2 * n][2]{};
        solve(result, 0, n, rows, diag);
        return result;
    }
};
int main(){
    Solution a;
    int n = 4;

    int result = a.solveNQueens(n);

    cout<<result<<endl;
    return 0;
}
