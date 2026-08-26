/**
 * Problem: LeetCode 209 - Minimum Size Subarray Sum
 * Description: Given an array of positive integers 'nums' and a positive integer 'target',
 *              return the minimal length of a subarray whose sum is greater than or equal to 'target'.
 *              If there is no such subarray, return 0 instead.
 *
 * Approach: Dynamic Sliding Window (Two Pointers)
 * 1. Expand the window by adding nums[right] to 'sum'.
 * 2. Whenever sum >= target, update minLength and shrink the window from the left (sum -= nums[left], left++).
 * 3. Return 0 if no valid subarray was found, otherwise return minLength.
 *
 * Time Complexity:  O(N) - Each element is visited at most twice (once by right, once by left).
 * Space Complexity: O(1) - Constant extra space used.
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;
        int sum = 0;
        int minLength = INT_MAX;
        int n = nums.size();
        for (int right = 0; right < n; right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        if (minLength == INT_MAX)
        {
            return 0;
        }
        return minLength;
    }
};
int main()
{
    Solution sol;

    // Test Case 1
    int target1 = 7;
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    cout << "Test 1 Output: " << sol.minSubArrayLen(target1, nums1)  << endl;

    // Test Case 2
    int target2 = 4;
    vector<int> nums2 = {1, 4, 4};
    cout << "Test 2 Output: " << sol.minSubArrayLen(target2, nums2)  << endl;

    // Test Case 3
    int target3 = 11;
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Test 3 Output: " << sol.minSubArrayLen(target3, nums3)  << endl;

    return 0;
}