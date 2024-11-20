#include <bits/stdc++.h>
#include <vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> nums{4,5,0,-2,-3,1};
    int k=5;
    int*umap= new int[k]{0};
    int cumSum=0;
    umap[0]=0;
    for (int i = 0; i < nums.size(); i++){
        cumSum+=nums[i];
        umap[((cumSum % k) + k) % k]+=1;
    }
    int result=0;
    for (int i=0;i<k;i++){
        if(umap[i]>1){
            result+= (umap[i])*(umap[i]-1)/2;
        }
    }
    result+=umap[0];
    cout<<result<<endl;
    return 0;
}
