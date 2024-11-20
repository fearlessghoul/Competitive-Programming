#include <iostream>
using namespace std;

int main(){
    int nums[] = {6, 7, 1, 2, 3, 4, 5};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 3, ans = -1;
    int left = 0, right = n - 1, mid;
    while (left <= right){
        mid = left + (right - left) / 2;
        if (nums[mid] == target){
            ans = mid;
            break;
        }
        if (nums[mid] >= nums[left]){
            if (nums[left] <= target && nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if (nums[mid] < target && nums[right] >= target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        cout<<left<<" "<<mid<<" "<<right<<endl;
    }
    cout<<ans<<endl;

    return 0;
}