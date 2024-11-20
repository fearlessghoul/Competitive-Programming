#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    void combinationgenerator(vector<int> &arr, vector<vector<int>> &res, std::vector<int> &subarr, int n, int target, int commutativesum, int start){
        if (commutativesum > target){
            return;
        }
        else if (subarr.size() != 0 && commutativesum == target){
            res.push_back(subarr);
        }
        else{
            for (int i = start; i < n; i++){
                subarr.push_back(arr[i]);
                combinationgenerator(arr, res, subarr, n, target, commutativesum + arr[i], i);
                subarr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target){
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> subarr;
        combinationgenerator(candidates, res, subarr, candidates.size(), target, 0, 0);
        return res;
    }
};
int main(){
    Solution a;
    vector<int> cand{2, 3, 6, 7};
    for (auto it : a.combinationSum(cand, 7)){
        for (int c : it){
            cout << c << " ";
        }
        cout << endl;
    }
}