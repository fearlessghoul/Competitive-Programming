#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool inbound(int i, int j, int m, int n)
    {
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }
    void mark(int i, int j, int m, int n, int **mat, int val)
    {
        mat[i][j] += val;
        if (inbound(i - 1, j + 2, m, n))
            mat[i - 1][j + 2] += val;
        if (inbound(i + 1, j + 2, m, n))
            mat[i + 1][j + 2] += val;
        if (inbound(i + 2, j + 1, m, n))
            mat[i + 2][j + 1] += val;
        if (inbound(i + 2, j - 1, m, n))
            mat[i + 2][j - 1] += val;
        if (inbound(i + 1, j - 2, m, n))
            mat[i + 1][j - 2] += val;
        if (inbound(i - 1, j - 2, m, n))
            mat[i - 1][j - 2] += val;
        if (inbound(i - 2, j - 1, m, n))
            mat[i - 2][j - 1] += val;
        if (inbound(i - 2, j + 1, m, n))
            mat[i - 2][j + 1] += val;
    }
    void printIT(vector<string> &result)
    {
        for (string &res : result)
        {
            cout << res << endl;
        }
    }
    void solve(vector<vector<string>> &result, vector<string> &sol, int i, int j, int m, int n, int **matrix, int knights)
    {
        if (knights == 0 || !inbound(i, j, m, n)) {
            result.push_back(sol);
            return;
        }
        for (int k = i; k < m; k++)
            for (int l = j; l < n; l++){
                if (!matrix[k][l])
                {
                    mark(k, l, m, n, matrix, 1);
                    cout<<knights<<":"<<k<<" "<<l<<endl;
                    sol[k][l] = 'K';
                    solve(result, sol, k, l, m, n, matrix, knights - 1);
                    sol[k][l] = '.';
                    mark(k, l, m, n, matrix, -1);
                }
                j=0;
            }
    };
    vector<vector<string>> solveNQueens(int m, int n, int k)
    {
        if (n == 1)
            return vector(1, vector(m, string(1, 'K')));
        if (m == 1)
            return vector(1, vector(1, string(n, 'K')));
        vector<string> sol(m, string(n, '.'));
        int **matrix = new int*[m];
        for (int i = 0; i < m; i++)
            matrix[i] = new int[n]{};
        vector<vector<string>> result;
        solve(result, sol, 0, 0, m, n, matrix, k);
        return result;
    }
};
int main()
{
    Solution a;
    int m = 3, n = 3, k = 5;
    vector<vector<string>> result = a.solveNQueens(m, n, k);
    for (auto &res : result)
    {
        a.printIT(res);
        cout << endl;
    }
    return 0;
}
