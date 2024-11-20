#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchWord(vector<vector<char>>& board,string& word,int i, int j,int m,int n,int k){
        if(k == word.size()){
            cout<<word.size()<<":"<<k<<" ";
            return true;
        }
        if(i>=0 && i < m && j>=0 && j < n){
            if(board[i][j] == word[k]){
                char c=board[i][j];
                board[i][j]='-';
                if(searchWord(board,word,i+1,j,m,n,k+1)|searchWord(board,word,i-1,j,m,n,k+1)|searchWord(board,word,i,j-1,m,n,k+1)|searchWord(board,word,i,j+1,m,n,k+1)){
                    board[i][j]=c;
                    return true;
                };
                board[i][j]=c;
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m=board.size(),n=board[0].size();
        set<string> res;

        for(int k=0;k < words.size();k++){
            for(int i=0;i<m;i++){
                bool tobreak=false;
                for (int j = 0; j < n; j++){
                    if(board[i][j] == words[k][0] && searchWord(board,words[k],i,j,m,n,0)){
                        res.insert(words[k]);
                        tobreak=true;
                        break;
                    }
                }
                if(tobreak)break;
            }
        }
        return vector(res.begin(),res.end());
    }
};
int main(){
    Solution a;
    vector<vector<char>> obstacleGrid{{'o','a','b','n'},{'o','t','a','e'},{'a','h','k','r'},{'a','f','l','v'}};
    vector<string> words{"oa","oaa"};
    for(string b:a.findWords(obstacleGrid,words)){
        // cout<<b<<endl;
    }
    
}