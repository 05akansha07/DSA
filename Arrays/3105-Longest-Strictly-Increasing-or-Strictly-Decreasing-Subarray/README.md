# 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

**Difficulty:** Easy

**Topics:** Array

**Language:** C++

## Problem Statement

You are given an array of integers `nums`. Return the length of the **longest subarray** of `nums` which is either **strictly increasing** or **strictly decreasing**.

## Examples

### Example 1:

* **Input:** `nums = [1, 4, 3, 3, 2]`

* **Output:** `2`

* **Explanation:**
  * The strictly increasing subarrays of `nums` are `[1]`, `[2]`, `[3]`, `[3]`, `[4]`, and `[1, 4]`.
  * The strictly decreasing subarrays of `nums` are `[1]`, `[2]`, `[3]`, `[3]`, `[4]`, `[3, 2]`, and `[4, 3]`.
  * Hence, we return `2`.

### Example 2:

* **Input:** `nums = [3, 3, 3, 3]`

* **Output:** `1`

* **Explanation:**
  * Every single element forms a monotonic subarray of length `1`, and no adjacent elements differ.
  * Hence, we return `1`.

### Example 3:

* **Input:** `nums = [3, 2, 1]`

* **Output:** `3`

* **Explanation:**
  * The entire array `[3, 2, 1]` is strictly decreasing, giving a maximum length of `3`.

## Constraints

* $1 \le \text{nums.length} \le 50$

* $1 \le \text{nums}[i] \le 50$

## Intuition & Approach

### Single-Pass State Tracking

Because any contiguous subarray ending at index $i$ can either extend the monotonic streak ending at $i - 1$ or start a brand-new streak of length $1$ at index $i$, we can solve the problem in a single pass using two running counters:

1. **State Variables:**
   * `incLen`: Length of the current strictly increasing subarray ending at index $i$.
   * `decLen`: Length of the current strictly decreasing subarray ending at index $i$.
   * `maxLen`: Global maximum monotonic subarray length seen so far (initialized to $1$ for $n \ge 1$).

2. **Transition Rules (for each $i$ from $1$ to $n - 1$):**
   * **Strictly Increasing ($\text{nums}[i] > \text{nums}[i - 1]$):**
     * The increasing streak extends: `incLen++`.
     * The decreasing streak breaks and resets to just the current element: `decLen = 1`.
   * **Strictly Decreasing ($\text{nums}[i] < \text{nums}[i - 1]$):**
     * The decreasing streak extends: `decLen++`.
     * The increasing streak breaks and resets to just the current element: `incLen = 1`.
   * **Equal Elements ($\text{nums}[i] == \text{nums}[i - 1]$):**
     * Strict monotonicity is broken in both directions: reset both `incLen = 1` and `decLen = 1`.

3. **Global Update:**
   * At each step, update `maxLen = max({maxLen, incLen, decLen})`.

## Complexity Analysis

* **Time Complexity:** $\mathcal{O}(N)$

  Performs a single linear traversal across the $N$ elements of `nums` with constant-time comparisons at each index.

* **Space Complexity:** $\mathcal{O}(1)$ auxiliary space

  Maintains only three integer variables (`maxLen`, `incLen`, `decLen`).

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int longestMonotonicSubarray(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxLen = 1;
        int incLen = 1;
        int decLen = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                incLen++;
                decLen = 1;
            } else if (nums[i] < nums[i - 1]) {
                decLen++;
                incLen = 1;
            } else {
                incLen = 1;
                decLen = 1;
            }
            maxLen = max({maxLen, incLen, decLen});
        }

        return maxLen;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1, 4, 3, 3, 2] -> Expected: 2
    vector<int> nums1 = {1, 4, 3, 3, 2};
    cout << "Test 1: " << solver.longestMonotonicSubarray(nums1) << endl;

    // Test Case 2: [3, 3, 3, 3] -> Expected: 1
    vector<int> nums2 = {3, 3, 3, 3};
    cout << "Test 2: " << solver.longestMonotonicSubarray(nums2) << endl;

    // Test Case 3: [3, 2, 1] -> Expected: 3
    vector<int> nums3 = {3, 2, 1};
    cout << "Test 3: " << solver.longestMonotonicSubarray(nums3) << endl;

    return 0;
}
```
