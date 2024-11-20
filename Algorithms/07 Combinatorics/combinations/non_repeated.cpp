#include <iostream>
#include <vector>
#include<algorithm>
// with n! complexity
void generateCombinations(const std::vector<int> &arr, std::vector<int> &combination, int start){
    if (!combination.empty()){
        for (int i : combination)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    for (int i = start; i < arr.size(); ++i){
        if (i > start && arr[i] == arr[i - 1]) {
            // Skip duplicates
            continue;
        }
        combination.push_back(arr[i]);
        generateCombinations(arr, combination, i + 1);
        combination.pop_back();
    }
}

// with 2^n complexity
void generateCombinations(const std::vector<int> &arr, std::vector<int> &combination, int start){

    if (start == arr.size()){
        if (!combination.empty()){
            for (int i : combination){
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
        return;
    }
    combination.push_back(arr[start]);
    generateCombinations(arr, combination, start + 1);
    combination.pop_back();
    generateCombinations(arr, combination, start + 1);
}
int main(){
    std::vector<int> arr = {10,1,2,7,6,1,5};
    std::vector<int> combination;
    sort(arr.begin(), arr.end());
    generateCombinations(arr, combination, 0);

    return 0;
}
