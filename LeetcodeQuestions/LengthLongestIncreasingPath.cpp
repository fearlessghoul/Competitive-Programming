#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxPathLength(vector<vector<int>> &coordinates, int k){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int count = 0;
        vector<int> test = coordinates[k];
        int size = coordinates.size();
        vector<int> it;
        sort(coordinates.begin(), coordinates.end(), [](const vector<int> &v1, const vector<int> &v2) -> bool
             { return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0]; });
        for (int i = 0; i < size; i++){
            if (coordinates[i][0] < test[0] && coordinates[i][1] < test[1] && coordinates[i + 1][1] > coordinates[i][1]) count++;
            if (coordinates[i][0] > test[0]&& coordinates[i][1] > test[1] && coordinates[i][1] > coordinates[i - 1][1]) count++;
        }

        return count;
    }
};
int main(){
    Solution a;
    vector<vector<int>> coordinates{{2, 1}, {7, 0}, {5, 6}};
    int res = a.maxPathLength(coordinates, 2);
    cout << res << endl;
}