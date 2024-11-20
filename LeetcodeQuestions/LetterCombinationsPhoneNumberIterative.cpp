#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int mapper(char c){
        switch (c){
        case '2':
            return 0;
        case '3':
            return 1;
        case '4':
            return 2;
        case '5':
            return 3;
        case '6':
            return 4;
        case '7':
            return 5;
        case '8':
            return 6;
        case '9':
            return 7;
        }
        return 0;
    }
    vector<string> letterCombinations(string digits){
        long total=1;
        int n=digits.size();
        if (n == 0)
            return {};
        vector<string> mapps = {"abc", "def", "ghi", "jkl",
                                    "mno", "pqrs", "tuv", "wxyz"};
        int *sizes= new int[n];
        for(int i=0;i<n;i++){
            sizes[i] = mapps[mapper(digits[i])].length();
            total*=sizes[i];
        }
        vector<string> res(total,string(n,' '));
        int iterat=1;
        for (int i = n-1; i>=0; i--){
            total/=sizes[i];
            int k=0;
            for (int j = 0; j < total; j++){
                for (int l = 0; l < sizes[i]; l++){
                    for (int m = 0; m < iterat; m++){
                        res[k++][i]=mapps[mapper(digits[i])][l];
                    }
                }
            }
            iterat*=sizes[i];
        }
        return res;
    }
};
int main(){
    Solution a;
    vector<string> res = a.letterCombinations("3");
    for (auto it : res){
        cout << it << endl;
    }
}