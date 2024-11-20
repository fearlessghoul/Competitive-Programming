#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetsgen(vector<int> &nums, int index, vector<int> &subarr, vector<vector<int>> &res){
    res.push_back(subarr);
    for (int i = index; i < nums.size(); i++){
        if (i > index && nums[i] == nums[i - 1]){
            continue;
        }
        subarr.push_back(nums[i]);
        subsetsgen(nums, i + 1, subarr, res);
        subarr.pop_back();
    }
}
int main(){
    vector<int> nums{1, 2, 2};

    sort(nums.begin(), nums.end());
    vector<int> subarr;
    vector<vector<int>> res;
    subsetsgen(nums, 0, subarr, res);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}