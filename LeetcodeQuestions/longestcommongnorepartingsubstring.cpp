#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main(){
    string s = "pwwkew"; // abcabcbb
    if (s.length() == 0)
        return 0;
    int mapped[256];
    for (int k = 0; k < 256; k++)
        mapped[k] = -1;
    int left = 0, maxm = 1;
    mapped[s[0]] = 0;
    for (int right = 1; right < s.length(); right++){
        if (mapped[s[right]] > -1){
            for (int j = left; j < mapped[s[right]]; j++){
                mapped[s[j]] = -1;
            }
            left = mapped[s[right]] + 1;
        }
        mapped[s[right]] = right;
        maxm= max(maxm,right - left + 1);
    }
    cout << max << endl;
}