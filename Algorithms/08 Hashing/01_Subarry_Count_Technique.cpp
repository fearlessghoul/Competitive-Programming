#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to count subarrays with sum equal to k
int countSubarraysWithSumK(const vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumFreq; // Stores frequency of prefix sums
    int count = 0, prefixSum = 0;

    for (int num : arr) {
        prefixSum += num; // Update current prefix sum

        // If the current prefix sum itself is k, increment count
        if (prefixSum == k) 
            count++;

        // Check if (prefixSum - k) exists in map, meaning a subarray sums to k
        if (prefixSumFreq.count(prefixSum - k))
            count += prefixSumFreq[prefixSum - k];

        // Increment the frequency of current prefix sum
        prefixSumFreq[prefixSum]++;
    }
    return count;
}

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    
    cout << countSubarraysWithSumK(arr, k) << endl;
    return 0;
}
