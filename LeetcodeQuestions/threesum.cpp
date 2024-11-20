#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    int j,k,n=nums.size(),sum=0;    
    for (int i = 0; i < n; i++){
        
        if(i>0 && nums[i]== nums[i-1]) continue;
        j=i+1;
        k=n-1;
        while (j<k){
            sum= nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            }else if (sum>0){
                k--;
            }else{
                result.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while (nums[j]== nums[j-1]) j++;
                while (nums[k]== nums[k+1]) k--;
            }
        }
        
    }
    for (auto it: result){
        for (auto it2: it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}