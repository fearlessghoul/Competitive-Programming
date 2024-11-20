#include <iostream>
#include <string>
using namespace std;

int main(){
    std::string s = "ABC";
    int numRows = 3;
    if (numRows == 1){
        return 0;
    }
    int diff = 2 * (numRows - 1), size = s.size(),temp,l=0;
    string res(s.size(),' ');
    for (int i = 0; i < numRows; i++){
        for (int j = i; j < size; j += diff){
            res[l++] = s[j];
            if(i==0 || i== numRows-1){
                continue;
            }
            temp= (j + diff - 2 * i);
            if (temp < size){
                res[l++] = s[temp];
            }
        }
    }
    cout << res << endl;
    return 0;
}