# 209. Minimum Size Subarray Sum

**Difficulty:** Medium  
**Topics:** Array, Binary Search, Sliding Window, Prefix Sum  
**Language:** C++

---

## Problem Statement

Given an array of positive integers `nums` and a positive integer `target`, return the **minimal length** of a subarray whose sum is greater than or equal to `target`. If there is no such subarray, return `0` instead.

---

## Examples

### Example 1:
- **Input:** `target = 7, nums = [2, 3, 1, 2, 4, 3]`
- **Output:** `2`
- **Explanation:** The subarray `[4, 3]` has the minimal length under the problem constraint.

### Example 2:
- **Input:** `target = 4, nums = [1, 4, 4]`
- **Output:** `1`
- **Explanation:** The subarrays `[4]` at index 1 or 2 have minimal length 1.

### Example 3:
- **Input:** `target = 11, nums = [1, 1, 1, 1, 1, 1, 1, 1]`
- **Output:** `0`
- **Explanation:** The total sum of the entire array is 8, which never reaches target 11.

---

## Constraints

- $1 \le \text{target} \le 10^9$
- $1 \le \text{nums.length} \le 10^5$
- $1 \le \text{nums}[i] \le 10^4$

---

## Follow-up

If you have figured out the $\mathcal{O}(N)$ solution, try coding another solution of which the time complexity is $\mathcal{O}(N \log N)$.

---

## Intuition & Approach

### Sliding Window (Two Pointers)

Because all numbers in `nums` are strictly positive ($nums[i] \ge 1$), the running sum is strictly monotonic with respect to window expansion and contraction:
- Expanding the right boundary always **increases** the sum.
- Shrinking the left boundary always **decreases** the sum.

This allows us to maintain a dynamic sliding window $[\text{left}, \text{right}]$:
1. **Expand Window:**  
   Advance `right` from $0$ to $N - 1$, adding `nums[right]` to `sum`.
2. **Shrink Window & Record Minimum:**  
   Whenever `sum >= target`, the current window is a valid candidate:
   - Update `minLength = min(minLength, right - left + 1)`.
   - Subtract `nums[left]` from `sum` and advance `left++`.
   - Repeat until `sum < target`.
3. **Result:**  
   If `minLength` was never updated (remains `INT_MAX`), return `0`. Otherwise, return `minLength`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  Although there is a nested `while` loop, each element is visited at most twice (once by `right` and once by `left`). Hence, the amortized time is strictly linear $\mathcal{O}(N)$.
- **Space Complexity:** $\mathcal{O}(1)$  
  Only a few scalar variables (`left`, `sum`, `minLength`) are maintained.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minLength = INT_MAX;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        if (minLength == INT_MAX) {
            return 0;
        }

        return minLength;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [2, 3, 1, 2, 4, 3], target = 7 -> Expected: 2 ([4, 3])
    int target1 = 7;
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    cout << "Test 1 Output: " << sol.minSubArrayLen(target1, nums1) << endl;

    // Test Case 2: [1, 4, 4], target = 4 -> Expected: 1 ([4])
    int target2 = 4;
    vector<int> nums2 = {1, 4, 4};
    cout << "Test 2 Output: " << sol.minSubArrayLen(target2, nums2) << endl;

    // Test Case 3: [1, 1, 1, 1, 1, 1, 1, 1], target = 11 -> Expected: 0
    int target3 = 11;
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Test 3 Output: " << sol.minSubArrayLen(target3, nums3) << endl;

    return 0;
}
```
