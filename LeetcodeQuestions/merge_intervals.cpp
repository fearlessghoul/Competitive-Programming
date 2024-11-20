#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<vector<int>> intervals{{2,6},{1,3},{8,10},{15,18}};
    std::sort(intervals.begin(), intervals.end());

    int j = 0;
    for (int i = 1; i < intervals.size(); i++){
        if (intervals[i][0] <= intervals[j][1]){
            if (intervals[i][1] > intervals[j][1]){
                intervals[j][1] = intervals[i][1];
            }
        }
        else{
            j++;
            intervals[j] = intervals[i];
        }
    }
    intervals.resize(j + 1);
    for (auto it : intervals){
        cout << it[0] << " " << it[1] << endl;
    }

    return 0;
}