#include <iostream>
#include <vector>
using namespace std;
int main(){
    int rowIndex = 0;
    vector<int> ans(rowIndex+1,0);
    ans[0]=1;
    for (int i = 1; i <= rowIndex; i++){
        for (int j = i; j >=1; j--){
            ans[j]=ans[j]+ans[j-1];
        }
    }
    return 0;
}