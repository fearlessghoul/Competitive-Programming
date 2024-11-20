#include <iostream>
#include <vector>
using namespace std;
int main(){
    int numRows = 5;
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; i++){
        vector<int> row;
        for (int j = 0; j <= i; j++){
            if (j == 0 || j == i){
                row.push_back(1);
            }else{
                row.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
        }
        ans.push_back(row);
    }
    return 0;
}