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
    void generator(int i, int n, vector<string> &res, int &k, string &digits, vector<string> &mapps,int*& sizes,int Tsize){
        if (i == n){
            k++;
            return;
        }
        int size=Tsize/sizes[i];
        for (int j = 0; j < sizes[i]; j++){
            for(int l=0;l < size;l++){
                res[k+l][i] = mapps[mapper(digits[i])][j];
            }
            generator(i + 1, n, res, k, digits, mapps,sizes,Tsize/sizes[i]);
        }
    }
    vector<string> letterCombinations(string digits){
        int n = digits.length();
        if (n == 0)
            return {};
        vector<string> mapps = {"abc", "def", "ghi", "jkl",
                                "mno", "pqrs", "tuv", "wxyz"};
        int size = 1;
        int *sizes= new int[n];
        for(int i=0;i<n;i++){
            sizes[i] = mapps[mapper(digits[i])].length();
            size*=sizes[i];
        }
        int k = 0;
        vector<string> res(size, string(n, ' '));
        generator(0, n, res, k, digits, mapps,sizes,size);
        return res;
    }
};
int main(){
    Solution a;
    vector<string> res = a.letterCombinations("234");
    for (auto it : res){
        cout << it << endl;
    }
}