#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums{6, 7, 1, 2, 3, 4, 5, 3};
    int target = 3;
    vector<int> ans(2, -1);
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right){
        mid = left + (right - left) / 2;

        if (nums[mid] > target){
            right = mid - 1;
        }
        else if (nums[mid] < target){
            left = mid + 1;
        }else{
            ans[0]=mid;
            right= mid-1;
        }
    }
    left = 0, right = nums.size() - 1;
    while (left <= right){
        mid = left + (right - left) / 2;

        if (nums[mid] > target){
            right = mid - 1;
        }
        else if (nums[mid] < target){
            left = mid + 1;
        }else{
            ans[1]=mid;
            left= mid+1;
        }
    }
    return 0;
}