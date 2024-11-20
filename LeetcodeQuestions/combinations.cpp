#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    void combinationgenerator(vector<vector<int>> &res, vector<int> &subarr, int n, int k, int i, int layer, int &resind){
        if (layer > k){
            res[resind++] = subarr;
        }
        else{
            for (int j = i; j <= n; j++){
                subarr[layer - 1] = j;
                combinationgenerator(res, subarr, n, k, j + 1, layer + 1, resind);
            }
        }
    }
    long nCr(int n, int k){
        long result = 1;
        for (int i = 0; i < k; i++){
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> res(nCr(n, k));
        vector<int> subarr(k, 0);
        int resind = 0;
        combinationgenerator(res, subarr, n, k, 1, 1, resind);
        return res;
    }
};
int main(){
    Solution a;
    for (auto it : a.combine(5, 2)){
        for (int c : it){
            cout << c << " ";
        }
        cout << endl;
    }
}