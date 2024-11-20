#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int countConsistentStrings(string allowed, vector<string> words){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        bool arr[256];
        for (char all : allowed)
            arr[all] = true;
        int count = 0;
        for (string word : words){
            count++;
            for (char letter : word){
                if (!arr[letter]){
                    count--;
                    break;
                }
            }
        }
        return count;
    }
};
int main(){
    Solution a;
    int res = a.countConsistentStrings("ab", {"ad", "bd", "aaab", "baa", "badab"});
    cout << res << endl;
}