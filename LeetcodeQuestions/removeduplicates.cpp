#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> nums{1,2,3,3,4,4,4,5,6,7,8,9,10};
    int k=1;
    for (int i = 1; i < nums.size(); i++){
        if(nums[i]==nums[i-1]){
            nums[k++]=nums[i];
        }
    }
    
    return 0;
}