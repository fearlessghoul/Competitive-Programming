#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minEnd(int n, int x) {
        long long ex=x+1;
        n--;
        while(n){
            if((ex&x) == x){
                n--;
            }
            ex++;
        }
        return ex-1;
    }
};
int main(){
    Solution a;
    long long ans=a.minEnd(6715154,7193485);
    cout<<ans<<endl;
}