#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

// Helper function to print permutations
void printPermutation(const std::vector<int>& permutation) {
    for (int num : permutation) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Backtracking function to generate permutations
void generatePermutations(std::vector<int>& sequence, int start, std::set<std::vector<int>>& results) {
    if (start == sequence.size() - 1) {
        results.insert(sequence);
        return;
    }

    for (int i = start; i < sequence.size(); ++i) {
        // Skip duplicates
        if (i > start && sequence[i] == sequence[start]) {
            continue;
        }

        // Swap and generate permutations
        std::swap(sequence[start], sequence[i]);
        generatePermutations(sequence, start + 1, results);
        std::swap(sequence[start], sequence[i]); // Backtrack
    }
}

int main() {
    std::vector<int> sequence = {2, 2, 1, 1}; // Example sequence with duplicates
    std::set<std::vector<int>> results;

    // Sort the sequence to handle duplicates
    std::sort(sequence.begin(), sequence.end());

    generatePermutations(sequence, 0, results);

    std::vector<std::vector<int>> res(results.begin(),results.end());
    // Print all unique permutations
    for (const auto& permutation : res) {
        printPermutation(permutation);
    }

    return 0;
}
