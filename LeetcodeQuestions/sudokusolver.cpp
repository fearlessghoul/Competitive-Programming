#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int charToInt(char ch){
        switch (ch){
        case '.':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        }
        return -1;
    }
    bool solve(vector<vector<char>> &board, bool (*rows)[10], bool (*cols)[10], bool (*submatrix)[10], int i, int j){
        if (i == 9){
            return true;
        }
        if (charToInt(board[i][j]) != 0){
            if (j < 8){
                return solve(board, rows, cols, submatrix, i, j + 1);
            }
            else if (j == 8){
                return solve(board, rows, cols, submatrix, i + 1, 0);
            }
        }
        for (int l = 1; l < 10; l++){
            if (!rows[i][l] && !cols[j][l] && !submatrix[i / 3 * 3 + j / 3][l]){
                board[i][j] = l+'0';
                rows[i][l] = cols[j][l] = submatrix[i / 3 * 3 + j / 3][l] = true;
                if (j < 8 ? solve(board, rows, cols, submatrix, i, j + 1) : solve(board, rows, cols, submatrix, i + 1, 0)){
                    return true;
                }
                board[i][j] = '.';
                rows[i][l] = cols[j][l] = submatrix[i / 3 * 3 + j / 3][l] = false;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board){
        bool(*rows)[10] = new bool[10][10]{};
        bool(*cols)[10] = new bool[10][10]{};
        bool(*submatrix)[10] = new bool[10][10]{};
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (charToInt(board[i][j]) != 0){
                    rows[i][charToInt(board[i][j])] = true;
                    cols[j][charToInt(board[i][j])] = true;
                    submatrix[i / 3 * 3 + j / 3][charToInt(board[i][j])] = true;
                }
            }
        }
        solve(board, rows, cols, submatrix, 0, 0);
    }
};
int main(){
    Solution a;
    vector<vector<char>> obstacleGrid{{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    a.solveSudoku(obstacleGrid);
    for (auto &res : obstacleGrid){
        for (auto it : res){
            cout << it << " ";
        }
        cout << endl;
    }
}