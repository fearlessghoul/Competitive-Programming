#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans;
    if (strs.empty()){
        return ans;
    }
    unordered_map<string, vector<string>> umap;
    for (int i = 0; i < strs.size(); i++){
        string word = strs[i];
        sort(word.begin(), word.end());
        umap[word].push_back(strs[i]);
    }
    for (auto it : umap){
        ans.push_back(it.second);
    }
    return ans;

    return true;
}