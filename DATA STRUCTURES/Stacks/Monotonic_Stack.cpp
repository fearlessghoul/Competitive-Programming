#include <iostream>
#include <vector>
#include <stack>

class MonotonicStack {
private:
    std::stack<int> s;  // Stack to store elements
    std::vector<int> result;  // Vector to store results

public:
    MonotonicStack(int size) : result(size, -1) {}

    void processNextGreaterElement(const std::vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; --i) {
            while (!s.empty() && s.top() <= nums[i]) {
                s.pop();
            }

            if (!s.empty()) {
                result[i] = s.top();
            }

            s.push(nums[i]);
        }
    }

    void processNextSmallerElement(const std::vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; --i) {
            while (!s.empty() && s.top() >= nums[i]) {
                s.pop();
            }

            if (!s.empty()) {
                result[i] = s.top();
            }

            s.push(nums[i]);
        }
    }

    std::vector<int> getResult() const {
        return result;
    }
};

int main() {
    std::vector<int> nums = {2, 1, 2, 4, 3};

    // Create a MonotonicStack object for next greater element
    MonotonicStack ms(nums.size());

    // Process next greater element
    ms.processNextGreaterElement(nums);

    std::vector<int> nextGreater = ms.getResult();

    std::cout << "Next Greater Elements: ";
    for (int num : nextGreater) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Process next smaller element
    MonotonicStack ms2(nums.size());
    ms2.processNextSmallerElement(nums);

    std::vector<int> nextSmaller = ms2.getResult();

    std::cout << "Next Smaller Elements: ";
    for (int num : nextSmaller) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
