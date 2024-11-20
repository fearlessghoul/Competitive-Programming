#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    static bool funComparator(vector<int> x1, vector<int> x2){
        return x1[0] > x2[0];
    }

    string frequencySort(string s){
        int store[256] = {0}, size = 0, n = s.length();
        for (char i : s){
            if (store[i] == 0){
                size++;
            }
            store[i]++;
        }
        vector<vector<int>> mapped(size, vector<int>(2, 0));
        int k = 0;
        for (int j = 0; j < 256; j++){
            if (store[j] != 0){
                mapped[k][0] = store[j];
                mapped[k][1] = j;
                k++;
            }
        }
        sort(mapped.begin(), mapped.end(), funComparator);
        string sortedstr(n, ' ');
        k = 0;
        for (int j = 0; j < size; j++){
            for (int m = 0; m < mapped[j][0]; m++){
                sortedstr[k++] = mapped[j][1];
            }
        }
        return sortedstr;
    }
};
int main(){
    Solution a;
    string res = a.frequencySort("tree");
    cout << res << endl;
}