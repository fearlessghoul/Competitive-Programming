#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums1{3,4,5, 0, 0, 0}, nums2{0,1,2};
    int m = 3, n = 3;

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    for (auto it : nums1){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}