# 974. Subarray Sums Divisible by K

**Difficulty:** Medium  
**Topics:** Array, Hash Table, Prefix Sum  
**Language:** C++

---

## Problem Statement

Given an integer array `nums` and an integer `k`, return the number of non-empty subarrays that have a sum divisible by `k`.

A subarray is a contiguous part of an array.

---

## Examples

### Example 1:
- **Input:** `nums = [4, 5, 0, -2, -3, 1]`, `k = 5`
- **Output:** `7`
- **Explanation:** There are 7 subarrays with a sum divisible by $k = 5$:  
  `[4, 5, 0, -2, -3, 1]`, `[5]`, `[5, 0]`, `[5, 0, -2, -3]`, `[0]`, `[0, -2, -3]`, `[-2, -3]`

### Example 2:
- **Input:** `nums = [5]`, `k = 9`
- **Output:** `0`

---

## Constraints

- $1 \le \text{nums.length} \le 3 \times 10^4$
- $-10^4 \le \text{nums}[i] \le 10^4$
- $2 \le k \le 10^4$

---

## Intuition & Approach

### Modular Arithmetic on Prefix Sums

For a subarray from index $i$ to $j$ to have a sum divisible by $k$:
$$(\text{prefix}[j] - \text{prefix}[i - 1]) \pmod k = 0$$

Equivalently:
$$\text{prefix}[j] \pmod k = \text{prefix}[i - 1] \pmod k$$

Whenever two prefix sums yield the exact same remainder modulo $k$, the elements between them sum to a multiple of $k$.

1. **Handling Negative Remainders in C++:**  
   In C++, the `%` operator on negative numbers preserves the sign (e.g., `-2 % 5 = -2`). To normalize into the non-negative range $[0, k - 1]$:
   $$\text{rem} = ((\text{current\_sum} \pmod k) + k) \pmod k$$

2. **Fixed Frequency Array:**  
   Since remainders modulo $k$ strictly lie in $[0, k - 1]$ and $k \le 10^4$, a fixed-size `vector<int> remainder_count(k, 0)` is faster and lighter than an `unordered_map`.

3. **Base Case:**  
   Set `remainder_count[0] = 1` to account for valid prefix subarrays that are divisible by $k$ from index $0$.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass through the array `nums` of size $N$, with $\mathcal{O}(1)$ updates per step.
- **Space Complexity:** $\mathcal{O}(k)$  
  Allocates a vector of size $k$ to track remainder frequencies.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Remainder frequency array for remainders 0 to k - 1
        vector<int> remainder_count(k, 0);
        
        // Base case: prefix sum of 0 has remainder 0 occurring once
        remainder_count[0] = 1;

        int current_sum = 0;
        int total_subarrays = 0;

        for (int num : nums) {
            current_sum += num;

            // Normalize negative remainders in C++: ((val % k) + k) % k
            int rem = ((current_sum % k) + k) % k;

            // Every time this remainder was seen before, it forms a valid subarray
            total_subarrays += remainder_count[rem];
            
            // Increment the occurrence of the current remainder
            remainder_count[rem]++;
        }

        return total_subarrays;
    }
};

int main() {
    Solution solver;

    // Test Case 1
    vector<int> nums1 = {4, 5, 0, -2, -3, 1};
    int k1 = 5;
    cout << "Test 1: " << solver.subarraysDivByK(nums1, k1) << endl;

    // Test Case 2
    vector<int> nums2 = {5};
    int k2 = 9;
    cout << "Test 2: " << solver.subarraysDivByK(nums2, k2) << endl;

    // Test Case 3: Handling negatives
    vector<int> nums3 = {-1, 2, 9};
    int k3 = 2;
    cout << "Test 3: " << solver.subarraysDivByK(nums3, k3) << endl;

    return 0;
}
```
