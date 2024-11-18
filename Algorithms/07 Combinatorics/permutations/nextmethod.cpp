#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long factorial(int n){
    long res=1;
    for (int i = 1; i <= n; i++) res*=i;
    return res;
}
int main() {
    vector<int> nums = {2, 2, 1, 1};
    vector<vector<int>> results;
    sort(nums.begin(), nums.end());
    do {
        results.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    for (const auto& permutation : results) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << std::endl;
    }

    return 0;
}
