# 3718. Smallest Missing Multiple of K

**Difficulty:** Easy  
**Topics:** Array, Hash Table, Math  
**Language:** C++

---

## Problem Statement

Given an integer array `nums` and an integer `k`, return the smallest positive multiple of `k` that is missing from `nums`.

A multiple of `k` is any positive integer divisible by `k`.

---

## Examples

### Example 1:
- **Input:** `nums = [8, 2, 3, 4, 6]`, `k = 2`
- **Output:** `10`
- **Explanation:** The positive multiples of $k = 2$ are $2, 4, 6, 8, 10, 12, \dots$. The smallest multiple missing from `nums` is $10$.

### Example 2:
- **Input:** `nums = [1, 4, 7, 10, 15]`, `k = 5`
- **Output:** `5`
- **Explanation:** The positive multiples of $k = 5$ are $5, 10, 15, 20, \dots$. The smallest multiple missing from `nums` is $5$.

---

## Constraints

- $1 \le \text{nums.length} \le 100$
- $1 \le \text{nums}[i] \le 100$
- $1 \le k \le 100$

---

## Intuition & Approach

### Hash Set Lookup for Incremental Multiples

To find the smallest missing positive multiple of $k$:

1. **Hash Set Insertion:**  
   Insert all elements of `nums` into an `unordered_set<int>` to achieve $\mathcal{O}(1)$ average-time membership lookups.

2. **Sequential Multiples Generation:**  
   - Start with the first positive multiple: `target = k`.
   - While `target` exists in the set, advance to the next multiple by adding $k$ (`target += k`).

3. **Termination:**  
   The first value of `target` that is not present in the set is guaranteed to be the smallest missing positive multiple of $k$.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N + M)$  
  Where $N$ is the number of elements in `nums` (inserted into the hash set in $\mathcal{O}(N)$ average time), and $M$ is the number of multiples checked until a missing one is found. Since $\text{nums}[i] \le 100$, $M \le \lfloor 100 / k \rfloor + 1 \le 101$.
- **Space Complexity:** $\mathcal{O}(N)$  
  To store elements of `nums` in the `unordered_set`.

---

## C++ Implementation

```cpp
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        int target = k;
        while (s.count(target)) {
            target += k;
        }
        return target;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [8, 2, 3, 4, 6], k = 2 -> Expected: 10
    vector<int> nums1 = {8, 2, 3, 4, 6};
    int k1 = 2;
    cout << "Test 1 Output: " << sol.missingMultiple(nums1, k1) << " (Expected: 10)" << endl;

    // Test Case 2: [1, 4, 7, 10, 15], k = 5 -> Expected: 5
    vector<int> nums2 = {1, 4, 7, 10, 15};
    int k2 = 5;
    cout << "Test 2 Output: " << sol.missingMultiple(nums2, k2) << " (Expected: 5)" << endl;

    return 0;
}
```
