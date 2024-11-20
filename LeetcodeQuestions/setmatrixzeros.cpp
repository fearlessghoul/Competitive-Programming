#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool C0=false,C1=false;
        int m=matrix.size(),n=matrix[0].size();
        if(matrix[0][0] != 0){
            for(int i=0;i<m;i++)
                if(matrix[i][0]==0){
                    C0=true;
                    break;
                }
            for(int i=0;i<n;i++)
                if(matrix[0][i]==0){
                    C1=true;
                    break;
                }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<n;j++)matrix[i][j]=0;
            }
        }
        for(int i=1;i<n;i++){
            if(matrix[0][i]==0){
                for(int j=1;j<m;j++)matrix[j][i]=0;
            }
        }
        if((matrix[0][0] == 0) | (C0 && C1)){
            for(int i=0;i<m;i++)matrix[i][0]=0;
            for(int i=0;i<n;i++)matrix[0][i]=0;
            return;
        }
        if(C0){
            for(int i=0;i<m;i++)matrix[i][0]=0;
        }
        if(C1){
            for(int i=0;i<n;i++)matrix[0][i]=0;
        }
    }
};
int main(){
    Solution a;
    vector<vector<int>> obstacleGrid{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    a.setZeroes(obstacleGrid);
    for(auto it: obstacleGrid){
        for(auto it2: it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}