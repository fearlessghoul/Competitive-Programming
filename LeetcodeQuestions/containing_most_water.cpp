#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> height{1, 1}; // 49   ----  8,7
    int i = 0, j = height.size() - 1;
    int temp = 0;

    while (i < j){
        temp = max((j - i) * min(height[i], height[j]), temp);
        if (height[i] < height[j]){
            i++;
        }
        else{
            j--;
        }
    }
    cout << temp << endl;
    return 0;
}