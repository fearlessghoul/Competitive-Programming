#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, const vector<string>& words) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> result;
        unordered_map<string, unsigned int> map;
        unsigned int length = words[0].size();
        map.clear();
        for (const string& word : words) map[word]++;
        for (unsigned int offset = 0; offset < length; ++offset) {
            unsigned int size = 0;
            unordered_map<string, unsigned int> seen;
            for (unsigned int i = offset; i + length <= s.size(); i += length) {
                string sub = s.substr(i, length);
                auto itr = map.find(sub);
                if (itr == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                ++seen[sub];
                ++size;
                while (seen[sub] > itr->second) {
                    std::string first = s.substr(i - (size - 1) * length, length);
                    --seen[first];
                    --size;
                }
                
                if (size == words.size())
                    result.push_back(i - (size - 1) * length);
            }
        }

        return result;
    }
};
int main(){
    Solution a;
    vector<int> res=a.findSubstring("barfoothefoobarman",{"foo","bar"});
    for(int a:res){
        cout<<a<<" ";
    }
    cout<<endl;
}