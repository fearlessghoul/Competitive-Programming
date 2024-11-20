#include <iostream>
using namespace std;

int next(int *arr, int target, int end){
    int start = 0;

    int ans = -1;
    while (start <= end){
        int mid = start+(end-start) / 2;

        if (arr[mid] <= target)
            start = mid + 1;
        else{
            ans = mid;
            end = mid - 1;
        }
        
    }

    return ans;
}

int main(){
    int arr[] = {1, 2, 3, 5, 8, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << next(arr, 7, n - 1);
    return 0;
}
