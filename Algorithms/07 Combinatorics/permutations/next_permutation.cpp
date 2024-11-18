#include <iostream>
#include <vector>
#include <algorithm> // For reverse function

void nextPermutation(std::vector<int> &nums)
{
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find the first ascending pair
    for (i = n - 2; i >= 0; --i)
    {
        if (nums[i] < nums[i + 1])
        {
            break;
        }
    }

    if (i < 0)
    {
        // No next permutation, sequence is in descending order
        std::reverse(nums.begin(), nums.end());
    }
    else
    {

        // Step 2: Find the rightmost element larger than sequence[i]
        int j;
        for (j = n - 1; j > i; --j)
        {
            if (nums[j] > nums[i])
            {
                break;
            }
        }

        // Step 3: Swap elements at i and j
        std::swap(nums[i], nums[j]);

        // Step 4: Reverse the sequence after i
        std::reverse(nums.begin() + i + 1, nums.end());
    }
}

int main()
{
    std::vector<int> sequence = {1, 3, 5, 4, 2};
    nextPermutation(sequence);
    for (int num : sequence)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
