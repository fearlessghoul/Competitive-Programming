#include <iostream>
#include <vector>

void generateCombinations(const std::vector<int>& arr, std::vector<int>& combination, int start) {
    // Print the current combination
    for (int i : combination) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Recursively add elements to the combination
    for (int i = start; i < arr.size(); ++i) {
        combination.push_back(arr[i]);
        generateCombinations(arr, combination, i); // `i` instead of `i + 1` to allow repetition
        combination.pop_back(); // backtrack
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3};
    std::vector<int> combination;
    
    generateCombinations(arr, combination, 0);
    
    return 0;
}
