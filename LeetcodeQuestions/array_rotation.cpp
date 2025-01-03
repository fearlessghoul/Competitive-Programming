#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void leftRotate(int arr[], int d, int n){
    d = d % n;
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++) {
        for (int j = 1; j <= n/g_c_d; j++){
            swap(arr[i],arr[(i+j*d)%n]);
        }
        
    }
}
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
int main(){
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    leftRotate(arr, 2, n);
    printArray(arr, n);

    return 0;
}
