#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// Function to create the shift table
std::unordered_map<char, int> createShiftTable(const std::string& pattern) {
    int m = pattern.size();
    std::unordered_map<char, int> shiftTable;

    // Fill the shift table with default values (length of the pattern)
    for (int i = 0; i < 256; ++i) {
        shiftTable[static_cast<char>(i)] = m;
    }

    // Update the shift table based on the pattern
    for (int i = 0; i < m - 1; ++i) {
        shiftTable[pattern[i]] = m - 1 - i;
    }

    return shiftTable;
}

// Boyer-Moore-Horspool search algorithm
int boyerMooreHorspoolSearch(const std::string& text, const std::string& pattern) {
    int n = text.size();
    int m = pattern.size();

    // Edge case: pattern longer than text
    if (m > n) return -1;

    // Create the shift table
    std::unordered_map<char, int> shiftTable = createShiftTable(pattern);

    // Start the search
    int i = 0; // index in the text
    while (i <= n - m) {
        int j = m - 1; // index in the pattern

        // Compare the pattern with the text from right to left
        while (j >= 0 && pattern[j] == text[i + j]) {
            j--;
        }

        // If pattern is found
        if (j < 0) {
            return i; // Return the index of the first match
        }

        // Shift the pattern based on the shift table
        i += shiftTable[text[i + m - 1]];
    }

    return -1; // Pattern not found
}

int main() {
    std::string text = "HERE IS A SIMPLE EXAMPLE";
    std::string pattern = "EXAMPLE";

    int result = boyerMooreHorspoolSearch(text, pattern);

    if (result != -1) {
        std::cout << "Pattern found at index: " << result << std::endl;
    } else {
        std::cout << "Pattern not found." << std::endl;
    }

    return 0;
}
