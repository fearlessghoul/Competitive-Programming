#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> matrix{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    int row = matrix.size();
    for (int i = 0; i < row; i++){
        for (int j = 0; j <= i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < row; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
    for (int i = 0; i < row; i++){
        for (int j = 0; j < row; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
