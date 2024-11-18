#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n+1]={1,1};
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            arr[i]+=arr[j]*arr[i-j-1];
        }
        cout<<arr[i]<< " ";
    }
    
    return 0;
}