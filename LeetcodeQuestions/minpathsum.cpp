#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minPathSum(vector<vector<int>> &grid){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 1; i < n; i++){
            grid[0][i]+=grid[0][i-1];
        }
        for (int i = 1; i < m; i++){
            grid[i][0]+=grid[i-1][0];
        }
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
int main(){
    Solution a;
    vector<vector<int>> obstacleGrid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int res = a.minPathSum(obstacleGrid);
    cout << res << endl;
}