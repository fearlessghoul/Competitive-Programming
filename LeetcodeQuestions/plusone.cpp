#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool c=1;
        int r=digits.size()-1;
        while(r>=0 && c==1){
            digits[r]++;
            if(digits[r] <= 9){
                return digits;
            }else{
                digits[r]=0;
                r--;
            }
        }
        if(c==1){
            vector<int> result(digits.size()+1);
            result[0]=1;
            for(int i=0;i<digits.size();i++) result[i+1]=digits[i];
            return result;
        }
        return digits;
    }
};
int main(){
    Solution a;
    vector<int> sol{8,9,9,9};
    vector<int> res = a.plusOne(sol);
    for(int it:res)
        cout << it << " ";
    cout<<endl;
}