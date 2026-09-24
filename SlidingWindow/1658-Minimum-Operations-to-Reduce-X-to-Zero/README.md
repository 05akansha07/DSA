# 1658. Minimum Operations to Reduce X to Zero

**Difficulty:** Medium  
**Topics:** Array, Hash Table, Sliding Window, Prefix Sum  
**Language:** C++

---

## Problem Statement

You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this modifies the array for future operations.

Return the **minimum number of operations** to reduce `x` to exactly `0` if it is possible, otherwise return `-1`.

---

## Examples

### Example 1:
- **Input:** `nums = [1, 1, 4, 2, 3]`, `x = 5`
- **Output:** `2`
- **Explanation:** The optimal solution is to remove the last two elements (`[2, 3]`) to reduce `x` to zero ($3 + 2 = 5$).

### Example 2:
- **Input:** `nums = [5, 6, 7, 8, 9]`, `x = 4`
- **Output:** `-1`
- **Explanation:** The smallest element in the array is 5, which is already greater than `x = 4`.

### Example 3:
- **Input:** `nums = [3, 2, 20, 1, 1, 3]`, `x = 10`
- **Output:** `5`
- **Explanation:** The optimal solution is to remove the last three elements (`[1, 1, 3]`) and the first two elements (`[3, 2]`) for a total of 5 operations ($3 + 2 + 1 + 1 + 3 = 10$).

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $1 \le \text{nums}[i] \le 10^4$
- $1 \le x \le 10^9$

---

## Intuition & Approach

### Inverting the Problem: Longest Subarray with Sum Equal to $(\text{Total} - x)$

Removing elements from either the leftmost or rightmost ends to sum to $x$ is equivalent to finding a **contiguous central subarray** that remains untouched.

1. **Equivalence:**  
   $$\text{Target Subarray Sum} = \sum(\text{nums}) - x$$
   To **minimize** the operations (elements removed from the prefix and suffix), we must **maximize** the length of the remaining contiguous subarray that sums to $\text{target}$.

2. **Sliding Window:**  
   Since all elements in `nums` are strictly positive ($nums[i] \ge 1$), the running sum is strictly monotonic with respect to the window boundaries. We can use a standard two-pointer sliding window:
   - Expand `right` and add `nums[right]` to `sum`.
   - While `sum > target` and `left <= right`, shrink by subtracting `nums[left]` and advancing `left`.
   - When `sum == target`, update `maxLen = max(maxLen, right - left + 1)`.

3. **Answer Reconstruction:**  
   If no such subarray is found, return `-1`. Otherwise, the minimum operations required is:
   $$\text{operations} = \text{nums.size}() - \text{maxLen}$$

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  Both `left` and `right` pointers traverse the array of length $N$ at most once.
- **Space Complexity:** $\mathcal{O}(1)$  
  Operates directly on the input array using scalar variables.

---

## C++ Implementation

```cpp
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
    cout << "Test 1 Output: " << solver.minOperations(nums1, x1) << endl;

    // Test Case 2: Impossible to reach target -> -1
    vector<int> nums2 = {5, 6, 7, 8, 9};
    int x2 = 4;
    cout << "Test 2 Output: " << solver.minOperations(nums2, x2) << endl;

    // Test Case 3: Elements removed from both ends -> 5 operations
    vector<int> nums3 = {3, 2, 20, 1, 1, 3};
    int x3 = 10;
    cout << "Test 3 Output: " << solver.minOperations(nums3, x3) << endl;

    // Test Case 4: Total sum == x -> All elements removed
    vector<int> nums4 = {1, 2, 3};
    int x4 = 6;
    cout << "Test 4 Output: " << solver.minOperations(nums4, x4) << endl;

    return 0;
}
```
