#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total = 0;
        for (int num : nums) {
            total += num;
        }

        long long target = total - x;

        // If the total array sum is less than x, we cannot reduce x to 0
        if (target < 0) return -1;

        // If the total sum equals x, we must remove all elements
        if (target == 0) return nums.size();

        long long sum = 0;
        int maxLen = -1;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            // Safely shrink window if the current window sum exceeds target
            while (left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            // Record maximum length of a subarray whose sum equals target
            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return (maxLen == -1) ? -1 : (nums.size() - maxLen);
    }
};

int main() {
    Solution solver;

    // Test Case 1: Elements removed from the right [2, 3] -> 2 operations
    vector<int> nums1 = {1, 1, 4, 2, 3};
    int x1 = 5;
    cout << "Test 1 Output: " << solver.minOperations(nums1, x1)<< endl;

    // Test Case 2: Impossible to reach target -> -1
    vector<int> nums2 = {5, 6, 7, 8, 9};
    int x2 = 4;
    cout << "Test 2 Output: " << solver.minOperations(nums2, x2)<< endl;

    // Test Case 3: Elements removed from both ends -> 5 operations
    vector<int> nums3 = {3, 2, 20, 1, 1, 3};
    int x3 = 10;
    cout << "Test 3 Output: " << solver.minOperations(nums3, x3)<< endl;

    // Test Case 4: Total sum == x -> All elements removed
    vector<int> nums4 = {1, 2, 3};
    int x4 = 6;
    cout << "Test 4 Output: " << solver.minOperations(nums4, x4)<< endl;

    return 0;
}