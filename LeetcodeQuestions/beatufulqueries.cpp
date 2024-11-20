#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bs(vector<vector<int>>& items,int target,int n) {
        int low = 0;
        int high = n - 1;
        int result = -1;
        while(low <= high) {
            int mid = low + (high -low) / 2;
            if(items[mid][0] <= target) {
                result = mid;
                low = mid+1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end(),[](const vector<int>&a,const vector<int>&b)->bool{
            return a[0]==b[0] ? a[1] < b[1]: a[0] < b[0];
        });
        int j=1,k,maxVal=items[0][1];
        for(int i=1; i < items.size();i++){
            maxVal= max(maxVal,items[i][1]);
            while(i < items.size() - 1 && items[i][0]==items[i+1][0]){
                maxVal= max(maxVal,items[++i][1]);
            }
            items[j][0]=items[i][0];
            items[j][1]=maxVal;
            j++;
        }
        for(int& query:queries){
            k = bs(items,query,j);
            query=(k==-1?0:items[k][1]);
        }
        return queries;
    }
};
int main(){
    Solution a;
    vector<vector<int>> item={{1,2},{3,2},{2,4},{5,6},{3,5}};
    vector<int> quer={1,2,3,4,5,6};
    vector<int> item2=a.maximumBeauty(item,quer);
    for(int f:item2)cout<<f<<" ";
}