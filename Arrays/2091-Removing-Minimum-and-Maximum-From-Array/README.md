# 2091. Removing Minimum and Maximum From Array

**Difficulty:** Medium  
**Topics:** Array, Greedy, Two Pointers  
**Language:** C++

---

## Problem Statement

You are given a **0-indexed** array of **distinct** integers `nums`.

There is an element in `nums` that has the lowest value and an element that has the highest value. We call them the **minimum** and **maximum** respectively. Your goal is to remove both these elements from the array.

A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.

Return the **minimum number of deletions** it would take to remove both the minimum and maximum element from the array.

---

## Examples

### Example 1:
- **Input:** `nums = [2, 10, 7, 5, 4, 1, 8, 6]`
- **Output:** `5`
- **Explanation:**
  - Minimum element: `nums[5] = 1`
  - Maximum element: `nums[1] = 10`
  - We can remove both by taking 2 elements from the front (`[2, 10]`) and 3 elements from the back (`[1, 8, 6]`), totaling $2 + 3 = 5$ deletions.

### Example 2:
- **Input:** `nums = [0, -4, 19, 1, 8, -2, -3, 5]`
- **Output:** `3`
- **Explanation:**
  - Minimum element: `nums[1] = -4`
  - Maximum element: `nums[2] = 19`
  - Removing 3 elements from the front (`[0, -4, 19]`) clears both elements in 3 deletions.

### Example 3:
- **Input:** `nums = [101]`
- **Output:** `1`
- **Explanation:** The single element is both the minimum and maximum; 1 deletion suffices.

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $-10^5 \le \text{nums}[i] \le 10^5$
- The integers in `nums` are **distinct**.

---

## Intuition & Approach

### 3-Strategy Greedy Comparison

Let $n$ be the size of `nums`.
1. **Find Indices:**  
   Identify the 0-indexed positions of the minimum and maximum values (`minIdx` and `maxIdx`).
2. **Order Indices:**  
   Sort the two indices so that $i = \min(\text{minIdx}, \text{maxIdx})$ and $j = \max(\text{minIdx}, \text{maxIdx})$ ($i < j$).
3. **Evaluate the 3 Independent Strategies:**
   - **Front Only:** Delete elements from index $0$ through $j$:
     $$\text{frontOnly} = j + 1$$
   - **Back Only:** Delete elements from index $i$ through $n - 1$:
     $$\text{backOnly} = n - i$$
   - **Both Sides:** Delete elements from the front up to $i$, and from the back down to $j$:
     $$\text{bothSides} = (i + 1) + (n - j)$$

The optimal answer is simply:
$$\min(\text{frontOnly}, \text{backOnly}, \text{bothSides})$$

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass through the array of length $N$ to locate `minIdx` and `maxIdx`.
- **Space Complexity:** $\mathcal{O}(1)$  
  Only scalar integer variables are allocated.

---

## C++ Implementation

```cpp
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
```
