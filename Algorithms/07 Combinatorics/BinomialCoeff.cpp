#include<iostream>
using namespace std;

int nCr(int n,int r){
    int res=1;
    for (int i = 0; i < r; i++)
    {
        res=(res*(n-i))/(i+1);
    }
    return res;
}

int main(){
    int n,r;
    cin>>n>>r;
    return 0;
}