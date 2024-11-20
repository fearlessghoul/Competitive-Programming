#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateCombinations(const std::vector<int> &arr, std::vector<int> &combination, std::vector<vector<int>> &result, int target, int start){
    if (target < 0){
        return;
    }
    else if (target == 0 && !combination.empty()){
        result.push_back(combination);
        return;
    }
    else{
        for (int i = start; i < arr.size(); ++i){
            if (i > start && arr[i] == arr[i - 1]) {
                continue;
            }
            combination.push_back(arr[i]);
            generateCombinations(arr, combination, result, target - arr[i], i + 1);
            combination.pop_back();
        }
    }
}

int main(){

    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> subarr;
    generateCombinations(candidates, subarr, res, target, 0);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}