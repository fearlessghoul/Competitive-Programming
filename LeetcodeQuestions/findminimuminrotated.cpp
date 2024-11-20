#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    vector<int> nums{5, 1, 2, 3, 4};

    if (nums.size() == 1){
        return nums[0];
    }
    else if (nums.size() == 2){
        return min(nums[0], nums[1]);
    }
    else{
        int min, mid;
        int left = 0, right = nums.size() - 1;
        while (left <= right){
            mid = left + (right - left) / 2;
            bool flag = true;
            if ((mid - 1 >= 0 && nums[mid - 1] < nums[mid]))
                flag = false;
            if (mid + 1 < nums.size() && nums[mid + 1] < nums[mid])
                flag = false;
            if (flag) break;

            if (nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        cout << nums[mid] << endl;
        return nums[mid];
    }
    return 0;
}
