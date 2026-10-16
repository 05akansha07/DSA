# 2913. Subarrays Distinct Element Sum of Squares I

**Difficulty:** Easy  
**Topics:** Array, Hash Table  
**Language:** C++

---

## Problem Statement

You are given a **0-indexed** integer array `nums`.

The **distinct count** of a subarray of `nums` is defined as:
- Let `nums[i..j]` be a subarray of `nums` consisting of all indices from `i` to `j` such that $0 \le i \le j < \text{nums.length}$. Then the number of distinct values in `nums[i..j]` is called the distinct count of `nums[i..j]`.

Return the sum of the squares of distinct counts of all subarrays of `nums`.

A **subarray** is a contiguous non-empty sequence of elements within an array.

---

## Examples

### Example 1:
- **Input:** `nums = [1, 2, 1]`
- **Output:** `15`
- **Explanation:** Six possible subarrays are:
  - `[1]`: 1 distinct value $\to 1^2 = 1$
  - `[2]`: 1 distinct value $\to 1^2 = 1$
  - `[1]`: 1 distinct value $\to 1^2 = 1$
  - `[1, 2]`: 2 distinct values $\to 2^2 = 4$
  - `[2, 1]`: 2 distinct values $\to 2^2 = 4$
  - `[1, 2, 1]`: 2 distinct values $\to 2^2 = 4$
  - Total sum $= 1 + 1 + 1 + 4 + 4 + 4 = 15$.

### Example 2:
- **Input:** `nums = [1, 1]`
- **Output:** `3`
- **Explanation:** Three possible subarrays are:
  - `[1]`: 1 distinct value $\to 1^2 = 1$
  - `[1]`: 1 distinct value $\to 1^2 = 1$
  - `[1, 1]`: 1 distinct value $\to 1^2 = 1$
  - Total sum $= 1 + 1 + 1 = 3$.

---

## Constraints

- $1 \le \text{nums.length} \le 100$
- $1 \le \text{nums}[i] \le 100$

---

## Intuition & Approach

### Expanding Subarray Simulation with Direct Frequency Tracking

Given the small constraint $N \le 100$, an $\mathcal{O}(N^2)$ traversal efficiently visits every contiguous subarray $[i..j]$:

1. **Outer Loop (Subarray Start $i$):**  
   Fix the start index $i$. For each $i$, initialize a frequency tracker `seen` and reset `distinctCount = 0`.
   - Since $1 \le \text{nums}[i] \le 100$, a boolean array or `vector<bool>` of size $101$ allows $\mathcal{O}(1)$ tracking without hash table overhead.

2. **Inner Loop (Subarray End $j$):**  
   Expand the subarray to the right by incrementing $j$ from $i$ to $N - 1$:
   - If `nums[j]` hasn't been seen in the current window (`!seen[nums[j]]`), mark it as seen and increment `distinctCount++`.
   - Add `distinctCount * distinctCount` directly to `totalSum`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N^2)$  
  There are $\frac{N(N + 1)}{2}$ contiguous subarrays. Each extension takes $\mathcal{O}(1)$ time. For $N = 100$, operations are $\approx 5000$, executing in $< 1$ ms.
- **Space Complexity:** $\mathcal{O}(M)$  
  Where $M = 101$ is the value range of elements in `nums`. Constant auxiliary space $\mathcal{O}(1)$.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            // Using a boolean visited array since 1 <= nums[i] <= 100
            vector<bool> seen(101, false);
            int distinctCount = 0;

            for (int j = i; j < n; j++) {
                if (!seen[nums[j]]) {
                    seen[nums[j]] = true;
                    distinctCount++;
                }
                totalSum += distinctCount * distinctCount;
            }
        }

        return totalSum;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1, 2, 1] -> Expected: 15
    vector<int> t1 = {1, 2, 1};
    cout << "Test 1 Output: " << solver.sumCounts(t1) << endl;

    // Test Case 2: [1, 1] -> Expected: 3
    vector<int> t2 = {1, 1};
    cout << "Test 2 Output: " << solver.sumCounts(t2) << endl;

    return 0;
}
```
