#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>> queries) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int* ballMap=new int[limit+1]{};
        unordered_map<int,int> color;
        int count=0,i=0;
        vector<int> ans(queries.size());
        for(auto&it:queries){
            if(ballMap[it[0]]!=0 && --color[ballMap[it[0]]]==0)count--;
            ballMap[it[0]]=it[1];
            if(color[it[1]]==0) count++;
            color[it[1]]++;
            ans[i++]=count;
        }
        return ans;    
    }
};
int main(){
    Solution a;
    
    // bool,string,int
    // cout<<a.fname()<<endl;

    // array
    for(auto& it:a.queryResults(4,{{1,4},{2,5},{1,3},{3,4}})) cout<<it<<" ";
    cout<<endl;

    // matrix
    // for(auto& it:a.fname3()) {
    //     for(auto& it2:it) cout<<it2<<" ";
    //     cout<<endl;
    // }
}