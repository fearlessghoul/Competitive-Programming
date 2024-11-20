#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> stk(heights.size());
        int m=0;
        int res = 0;

        for (int i = 0; i < heights.size(); i++){
            int start = i;
            while (m>0 && stk[m-1].second > heights[i]){
                int idx = stk[m-1].first;
                int width = i - idx;
                int height = stk[m-1].second;
                m--;
                res = max(res, height * width);
                start = idx;
            }
            stk[m++]={start, heights[i]};
        }

        while (m>0){
            int width = heights.size() - stk[m-1].first;
            int height = stk[m-1].second;
            m--;
            res = max(res, height * width);
        }
        return res;
    }
};
int main(){
    Solution a;
    vector<int> heigh{2,1,5,6,2,3};
    int res = a.largestRectangleArea(heigh);
    cout << res << endl;
}