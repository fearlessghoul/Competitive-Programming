#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributed(vector<int>& quantities,int k){
        int shops=0;
        for(int val:quantities){
            shops+= (val/k) + (val%k!=0);
        }
        return shops;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        auto maxm=max_element(quantities.begin(),quantities.end());
        int i=1,j=*maxm,mid;
        while(i<=j){
            mid=i+(j-i)/2;
            int val=distributed(quantities,mid);
            if(val <= n){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return j+1;
    }
};
int main(){
    Solution a;
    int n=1;
    vector<int> quant{100000};
    cout<<a.minimizedMaximum(n,quant)<<endl;
}