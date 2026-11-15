# 3364. Minimum Positive Sum Subarray

**Difficulty:** Easy

**Topics:** Array, Sliding Window, Prefix Sum

**Language:** C++

## Problem Statement

You are given an integer array `nums` and two integers `l` and `r`. Your task is to find the **minimum sum** of a subarray whose size is between `l` and `r` (inclusive) and whose sum is greater than $0$.

Return the minimum sum of such a subarray. If no such subarray exists, return `-1`.

A **subarray** is a contiguous non-empty sequence of elements within an array.

## Examples

### Example 1:

* **Input:** `nums = [3, -2, 1, 4]`, `l = 2`, `r = 3`

* **Output:** `1`

* **Explanation:**
  The subarrays of length between $l = 2$ and $r = 3$ where the sum is greater than $0$ are:
  * `[3, -2]` with a sum of $1$
  * `[1, 4]` with a sum of $5$
  * `[3, -2, 1]` with a sum of $2$
  * `[-2, 1, 4]` with a sum of $3$

  Out of these, `[3, -2]` has the smallest positive sum of $1$.

### Example 2:

* **Input:** `nums = [-2, 2, -3, 1]`, `l = 2`, `r = 3`

* **Output:** `-1`

* **Explanation:**
  There is no subarray of length between $l$ and $r$ that has a sum greater than $0$.

### Example 3:

* **Input:** `nums = [1, 2, 3, 4]`, `l = 2`, `r = 4`

* **Output:** `3`

* **Explanation:**
  The subarray `[1, 2]` has length $2$ and yields the minimum positive sum of $3$.

## Constraints

* $1 \le \text{nums.length} \le 100$

* $1 \le l \le r \le \text{nums.length}$

* $-1000 \le \text{nums}[i] \le 1000$

## Intuition & Approach

### Constrained Subarray Enumeration with Running Sum

1. **Constraint Exploitation:**
   Because the input array length is small ($n \le 100$), evaluating all valid contiguous subarrays directly via nested loops requires at most $\frac{n(n + 1)}{2} \approx 5050$ iterations, which runs instantaneously without complex data structures.

2. **Incremental Window Expansion:**
   * Fix a starting index $i \in [0, n - 1]$ and initialize a running accumulator `sum = 0`.
   * Expand the ending index $j$ from $i$ up to $n - 1$ (or early-break once $\text{len} > r$), adding `nums[j]` to `sum` in $\mathcal{O}(1)$ time.
   * Compute the current subarray length:
     $$\text{len} = j - i + 1$$
   * If $l \le \text{len} \le r$ and $\text{sum} > 0$, update the minimum positive sum:
     $$\text{ans} = \min(\text{ans}, \text{sum})$$

3. **No Valid Subarray Handling:**
   Initialize `ans = INT_MAX`. After checking all subarrays, if `ans` remains `INT_MAX`, return `-1`; otherwise, return `ans`.

*(Note: For larger constraints like $N \le 10^5$, this problem can be solved in $\mathcal{O}(N \log N)$ time using prefix sums combined with a balanced BST / `std::multiset` to query the largest prefix sum strictly less than `prefix[j]` within window $[j - r, j - l]$).*

## Complexity Analysis

* **Time Complexity:** $\mathcal{O}(N^2)$
  Two nested loops examine all contiguous subarrays starting at each index $i$, maintaining the running sum in $\mathcal{O}(1)$ per step.

* **Space Complexity:** $\mathcal{O}(1)$ auxiliary space
  Uses only scalar integer variables without extra memory allocations.

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                int len = j - i + 1;
                if (len > r) break;
                if (len >= l && sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Expected: 1
    vector<int> nums1 = {3, -2, 1, 4};
    cout << "Test 1: " << solver.minimumSumSubarray(nums1, 2, 3) << endl;

    // Test Case 2: Expected: -1
    vector<int> nums2 = {-2, 2, -3, 1};
    cout << "Test 2: " << solver.minimumSumSubarray(nums2, 2, 3) << endl;

    // Test Case 3: Expected: 3
    vector<int> nums3 = {1, 2, 3, 4};
    cout << "Test 3: " << solver.minimumSumSubarray(nums3, 2, 4) << endl;

    return 0;
}
```
