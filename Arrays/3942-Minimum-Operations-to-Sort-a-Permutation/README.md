# 3942. Minimum Operations to Sort a Permutation

**Difficulty:** Medium  
**Topics:** Array, Math, Greedy  
**Language:** C++

---

## Problem Statement

You are given an integer array `nums` of length `n`, where `nums` is a permutation of the integers from `0` to `n - 1`.

You may perform only the following operations:
- **Reverse the entire array.**
- **Rotate Left by One:** Move the first element to the end of the array, and rest elements to left by one position.

Return an integer denoting the **minimum number of operations** required to sort the array in increasing order. If it is not possible to sort the array using only the given operations, return `-1`.

---

## Examples

### Example 1:
- **Input:** `nums = [0, 2, 1]`
- **Output:** `2`
- **Explanation:**
  - Rotate Left by one: `[2, 1, 0]`
  - Reverse the array: `[0, 1, 2]`
  The array becomes sorted in 2 operations, which is minimal.

### Example 2:
- **Input:** `nums = [1, 0, 2]`
- **Output:** `2`
- **Explanation:**
  - Reverse the array: `[2, 0, 1]`
  - Rotate Left by one: `[0, 1, 2]`
  The array becomes sorted in 2 operations, which is minimal.

### Example 3:
- **Input:** `nums = [2, 0, 1, 3]`
- **Output:** `-1`
- **Explanation:** It is impossible to reach `[0, 1, 2, 3]`. Thus, the answer is `-1`.

---

## Constraints

- $1 \le n == \text{nums.length} \le 10^5$
- $0 \le \text{nums}[i] \le n - 1$
- `nums` is a permutation of integers from $0$ to $n - 1$.

---

## Intuition & Approach

### Cyclic Adjacency & Dihedral Symmetries

Because **Rotate Left** preserves relative circular ordering and **Reverse** inverts it, the set of reachable configurations belongs to the dihedral group of the cycle. A permutation is sortable if and only if adjacent elements satisfy either a circularly ascending or descending relationship for all $n - 1$ consecutive steps.

Since each value in a valid cyclic permutation directly encodes its offset relative to the identity sequence:

1. **Circularly Ascending (`asc_count == n - 1`):**
   - If `nums[0] == 0`, the array is already sorted in $0$ operations.
   - **Rotate Left only:** Takes $n - \text{nums}[0]$ shifts to bring $0$ to index $0$.
   - **Simulated Rotate Right (via Reverse):** Takes $2 + \text{nums}[0]$ operations (Reverse $\to$ rotate left $\text{nums}[0]$ times $\to$ Reverse).
   - $\text{Cost} = \min(n - \text{nums}[0],\, 2 + \text{nums}[0])$.

2. **Circularly Descending (`des_count == n - 1`):**
   - **Reverse first:** Reversing yields an ascending array where the new first element is `nums.back()`. Shifting to sorted order takes $1 + (n - \text{nums.back()}) \bmod n$ operations.
   - **Rotate Left first, then Reverse:** Shifting left until $0$ lands at index $n - 1$ followed by a final Reverse takes $1 + (\text{nums}[0] + 1) \bmod n$ operations.
   - $\text{Cost} = \min(1 + (n - \text{nums.back()}) \bmod n,\, 1 + (\text{nums}[0] + 1) \bmod n)$.

3. **Any Other Order:**
   - Impossible to sort $\to$ return `-1`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass of length $N$ verifies the transition counts and extracts values in $\mathcal{O}(1)$ time per element.
- **Space Complexity:** $\mathcal{O}(1)$  
  Operates using scalar counters without extra memory allocation.

---

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
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int asc_count = 0;
        int des_count = 0;

        for (int i = 1; i < n; i++) {
            asc_count += (nums[i] == (nums[i - 1] + 1) % n);
            des_count += (nums[i - 1] == (nums[i] + 1) % n);
        }

        // Already sorted in increasing order: [0, 1, 2, ..., n-1]
        if (asc_count == n - 1 && nums[0] == 0) {
            return 0;
        }

        // Case 1: Circularly Ascending
        if (asc_count == n - 1) {
            int leftRot = n - nums[0];
            int rightRot = 2 + nums[0];
            return min(leftRot, rightRot);
        }

        // Case 2: Circularly Descending
        if (des_count == n - 1) {
            int leftRot = 1 + (n - nums.back()) % n; // Reverse first, then rotate left
            int rightRot = 1 + (nums[0] + 1) % n;    // Rotate left until 0 is at end, then reverse
            return min(leftRot, rightRot);
        }

        return -1;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [0, 2, 1] -> Expected: 2
    vector<int> t1 = {0, 2, 1};
    cout << "Test 1: " << solver.minOperations(t1) << endl;

    // Test Case 2: [1, 0, 2] -> Expected: 2
    vector<int> t2 = {1, 0, 2};
    cout << "Test 2: " << solver.minOperations(t2) << endl;

    // Test Case 3: [2, 0, 1, 3] -> Expected: -1
    vector<int> t3 = {2, 0, 1, 3};
    cout << "Test 3: " << solver.minOperations(t3) << endl;

    return 0;
}
```
