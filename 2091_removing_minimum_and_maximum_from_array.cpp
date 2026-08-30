/**
 * Problem: LeetCode 2091 - Removing Minimum and Maximum From Array
 * Description: Given a 0-indexed array of distinct integers 'nums', find the minimum 
 *              number of deletions required to remove both the minimum and maximum elements.
 *              Deletions can only be made from the front or back of the array.
 * 
 * Approach: Greedy & Index Comparison
 * 1. Find the 0-based indices of the minimum and maximum elements in a single pass.
 * 2. Order the indices such that i = min(minIdx, maxIdx) and j = max(minIdx, maxIdx).
 * 3. Evaluate the 3 possible deletion strategies:
 *    - Delete both from the front: j + 1
 *    - Delete both from the back:  n - i
 *    - Delete from both ends:      (i + 1) + (n - j)
 * 4. Return the minimum of the three options.
 * 
 * Time Complexity:  O(N) - Single pass to find minimum and maximum indices.
 * Space Complexity: O(1) - Constant extra space used.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int minIdx = 0;
        int maxIdx = 0;

        for (int k = 1; k < n; k++) {
            if (nums[k] < nums[minIdx]) minIdx = k;
            if (nums[k] > nums[maxIdx]) maxIdx = k;
        }

        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);

        // Option 1: Remove both from front
        int frontOnly = j + 1;

        // Option 2: Remove both from back
        int backOnly = n - i;

        // Option 3: Remove one from front, one from back
        int bothSides = (i + 1) + (n - j);

        return min({frontOnly, backOnly, bothSides});
    }
};

int main() {
    Solution sol;

    // Test Case 1: [2, 10, 7, 5, 4, 1, 8, 6] -> Expected: 5
    vector<int> nums1 = {2, 10, 7, 5, 4, 1, 8, 6};
    cout << "Test 1 Output: " << sol.minimumDeletions(nums1) << endl;

    // Test Case 2: [0, -4, 19, 1, 8, -2, -3, 5] -> Expected: 3
    vector<int> nums2 = {0, -4, 19, 1, 8, -2, -3, 5};
    cout << "Test 2 Output: " << sol.minimumDeletions(nums2) << endl;

    // Test Case 3: [101] -> Expected: 1
    vector<int> nums3 = {101};
    cout << "Test 3 Output: " << sol.minimumDeletions(nums3) << endl;

    return 0;
}