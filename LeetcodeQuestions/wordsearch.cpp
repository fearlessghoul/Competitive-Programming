#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchWord(vector<vector<char>>& board,string& word,int i, int j,int m,int n,int k){
        if(k == word.size()){
            return true;
        }
        if(i>=0 && i < m && j>=0 && j < n){
            if(board[i][j] == word[k]){
                char c=board[i][j];
                board[i][j]='-';
                if(searchWord(board,word,i+1,j,m,n,k+1)|searchWord(board,word,i-1,j,m,n,k+1)|searchWord(board,word,i,j-1,m,n,k+1)|searchWord(board,word,i,j+1,m,n,k+1)){
                    return true;
                };
                board[i][j]=c;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for (int j = 0; j < n; j++){
                if(board[i][j] == word[0] && searchWord(board,word,i,j,m,n,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    Solution a;
    vector<vector<char>> obstacleGrid{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout<<a.exist(obstacleGrid,"SEE")<<endl;
    
}