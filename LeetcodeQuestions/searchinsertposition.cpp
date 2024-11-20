#include <iostream>
using namespace std;

int searchinsertion(int *nums, int target, int right){
    int left = 0,mid;
    int ans = right+1;

    while (left <= right){
        mid = (right + left) / 2;
        if (nums[mid] == target){
            ans= mid;
            break;
        }
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return ans;
}

int main(){
    int arr[] = {1,3,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << searchinsertion(arr, 5, 3);
    return 0;
}
