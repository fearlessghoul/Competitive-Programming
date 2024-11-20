#include <iostream>
#include <vector>
using namespace std;

void subsetsgen(vector<int> &nums, int index, vector<int> &subarr, vector<vector<int>> &res){
    res.push_back(subarr);
    for (int i = index; i < nums.size(); i++){
        subarr.push_back(nums[i]);
        subsetsgen(nums, i + 1, subarr, res);
        subarr.pop_back();
    }
}
int main(){
    vector<int> nums{1, 2, 3, 4, 5, 7, 9, 10, 11, 13};
    vector<int> subarr;
    vector<vector<int>> res;
    subsetsgen(nums, 0, subarr, res);
    return 0;
}