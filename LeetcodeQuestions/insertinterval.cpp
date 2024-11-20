#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<vector<int>> insert(vector<vector<int>> intervals, vector<int> newInterval){
        int l = 0, size = intervals.size(), r = size - 1, mid, ans1 = size, ans2 = size;
        if(size==0){
            return {newInterval};
        }
        if (intervals[r][1] < newInterval[0]){
            intervals.push_back(newInterval);
            return intervals;
        }
        else if (intervals[0][0] > newInterval[1]){
            vector<vector<int>> res(size + 1);
            res[0] = newInterval;
            for (int i = 1; i <= size; i++){
                res[i] = intervals[i - 1];
            }
            return res;
        }

        while (l <= r){
            mid = l + (r - l) / 2;
            if (intervals[mid][0] <= newInterval[0]){
                l = mid + 1;
            }
            else{
                ans1 = mid;
                r = mid - 1;
            }
        }

        if (ans1 > 0 && newInterval[0] <= intervals[ans1 - 1][1] || ans1 == 0 && newInterval[1] < intervals[0][0] || ans1 == size)
            ans1--;
        l = max(0, ans1 - 1), r = size - 1;
        while (l <= r){
            mid = l + (r - l) / 2;
            if (intervals[mid][1] <= newInterval[1]){
                l = mid + 1;
            }
            else{
                ans2 = mid;
                r = mid - 1;
            }
        }
        if (ans2 < size && newInterval[1] < intervals[ans2][0] || ans2 == size)
            ans2--;
        if (ans1 == ans2){
            intervals[ans1] = {min(intervals[ans1][0], newInterval[0]), max(intervals[ans1][1], newInterval[1])};
        }
        else{
            int k = 0;
            vector<vector<int>> res(size - ans2 + ans1);
            for (int i = 0; i < ans1; i++){
                res[k++] = intervals[i];
            }
            res[ans1] = {min(intervals[ans1][0], newInterval[0]), max(intervals[ans2][1], newInterval[1])};
            for (int i = ans2 + 1; i < size; i++){
                res[k++] = intervals[i];
            }
            return res;
        }
        return intervals;
    }
};
int main(){
    Solution a;
    auto res = a.insert({}, {4, 8});
    for (auto it : res){
        for (auto it2 : it){
            cout << it2 << " ";
        }
        cout << endl;
    }
}