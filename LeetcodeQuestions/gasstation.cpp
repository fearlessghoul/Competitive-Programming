#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
        int n = gas.size();
        int sum = 0;
        int cum = 0;
        int start;
        bool set = false;
        for (int i = 0; i < n; i++){
            gas[i] -= cost[i];
            sum += gas[i];
            if (gas[i] >= 0 && !set){
                start = i;
                set = true;
            }
            if (set)
                cum += gas[i];
            if (cum < 0){
                cum = 0;
                set = false;
            }
        }
        if (sum < 0)
            return -1;
        return start;
    }
};
int main(){
    Solution a;
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    int res = a.canCompleteCircuit(gas, cost);
    cout << res << endl;
}