/**
 * Problem: LeetCode 3876 - Construct Uniform Parity Array II
 * Description: Given an array nums1 of n distinct integers, determine if it is
 *              possible to construct an array nums2 of length n such that all
 *              elements are either all odd or all even.
 *              For each index i, we can choose:
 *                1) nums2[i] = nums1[i]
 *                2) nums2[i] = nums1[i] - nums1[j], for j != i where nums1[i] - nums1[j] >= 1
 * 
 * Approach: Minimum Element Parity Analysis (O(N) Time, O(1) Space)
 * - The constraint nums1[i] - nums1[j] >= 1 forces nums1[j] < nums1[i].
 * - The global minimum element (mini) cannot pick Option 2 because no smaller element exists.
 *   Hence, mini must retain its original value and dictates the target parity.
 * 
 * Case 1: mini is Odd
 *   - Target parity must be odd.
 *   - Any odd element retains its value.
 *   - Any even element x is strictly greater than mini, so x - mini gives:
 *     Even - Odd = Odd.
 *   - Every element can become odd -> Always true.
 * 
 * Case 2: mini is Even
 *   - Target parity must be even.
 *   - Any even element retains its value.
 *   - To turn an odd element even, it must subtract a smaller odd element:
 *     Odd - Odd = Even.
 *   - However, the smallest odd element in the array has no smaller odd element
 *     to subtract. It cannot be converted to even.
 *   - Therefore, if mini is even, the array can only be made uniform if there
 *     are no odd numbers present in nums1 at all.
 * 
 * Condition: (mini % 2 != 0) || !hasOdd
 * 
 * Time Complexity:  O(N) - Single pass to find mini and track parity.
 * Space Complexity: O(1) - Constant auxiliary space.
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasOdd = false;
        int mini = INT_MAX;

        for (int x : nums1) {
            mini = min(mini, x);
            if (x % 2 != 0) {
                hasOdd = true;
            }
        }

        return (mini % 2 != 0) || !hasOdd;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [1, 4, 7] -> mini = 1 (Odd) -> Expected: true
    vector<int> nums1 = {1, 4, 7};
    cout << "Test 1: " << (sol.uniformArray(nums1) ? "true" : "false") << endl;

    // Test Case 2: [2, 4, 6] -> mini = 2 (Even, no odds) -> Expected: true
    vector<int> nums2 = {2, 4, 6};
    cout << "Test 2: " << (sol.uniformArray(nums2) ? "true" : "false") << endl;

    // Test Case 3: [2, 3, 5] -> mini = 2 (Even, has odds) -> Expected: false
    vector<int> nums3 = {2, 3, 5};
    cout << "Test 3: " << (sol.uniformArray(nums3) ? "true" : "false") << endl;

    return 0;
}