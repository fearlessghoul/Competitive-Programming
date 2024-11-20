#include<iostream>
using namespace std;

int main(){
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    int tar = 9;
    int res=-1,left=0,right=9,mid;
    while (left <= right){
        mid = left + (right-left)/2;
        if(arr[mid] < tar){
            left = mid+1;
        }else if(arr[mid] > tar){
            right= mid-1;
        }else{
            res = mid;
            break;
        }
    }
    cout<<res<<endl;

    return 0;
}