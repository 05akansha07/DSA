# 560. Subarray Sum Equals K

**Difficulty:** Medium  
**Topics:** Array, Hash Table, Prefix Sum  
**Language:** C++

---

## Problem Statement

Given an array of integers `nums` and an integer `k`, return the total number of subarrays whose sum equals to `k`.

A subarray is a contiguous non-empty sequence of elements within an array.

---

## Examples

### Example 1:
- **Input:** `nums = [1, 1, 1]`, `k = 2`
- **Output:** `2`
- **Explanation:** The subarrays `[1, 1]` at index `[0, 1]` and `[1, 2]` both sum to 2.

### Example 2:
- **Input:** `nums = [1, 2, 3]`, `k = 3`
- **Output:** `2`
- **Explanation:** The subarrays `[1, 2]` and `[3]` both sum to 3.

---

## Constraints

- $1 \le \text{nums.length} \le 2 \times 10^4$
- $-1000 \le \text{nums}[i] \le 1000$
- $-10^7 \le k \le 10^7$

---

## Intuition & Approach

### Prefix Sum + Hash Map (Two Sum on Cumulative Sums)

A brute-force solution checking every subarray $[i, j]$ takes $\mathcal{O}(N^2)$ time, which TLEs given $N = 2 \times 10^4$. Because the array can contain negative values, a standard two-pointer/sliding-window approach does not apply. Instead, we use a **Prefix Sum with Hash Map**:

1. **Subarray Sum via Prefix Sums:**  
   The sum of elements from index $i$ to $j$ is given by:
   $$\text{sum}(i, j) = \text{prefix\_sum}[j] - \text{prefix\_sum}[i - 1]$$
   We want $\text{sum}(i, j) = k$, which rearranges to:
   $$\text{prefix\_sum}[i - 1] = \text{prefix\_sum}[j] - k$$

2. **Algorithm:**  
   - Maintain `current_sum` as running prefix sum.
   - Maintain a hash map `prefix_count` mapping each prefix sum to how many times it has appeared so far.
   - Initialize `prefix_count[0] = 1` to account for subarrays starting at index `0` whose sum is exactly `k`.
   - At each element `num`:
     - Update `current_sum += num`.
     - Check if `needed = current_sum - k` exists in `prefix_count`. If so, add its frequency to `total_count`.
     - Increment `prefix_count[current_sum]++`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass through `nums`. Each lookup and insertion in `unordered_map` operates in $\mathcal{O}(1)$ average time.
- **Space Complexity:** $\mathcal{O}(N)$  
  In the worst case, all prefix sums are distinct, storing up to $N + 1$ keys in the hash map.

---

## C++ Implementation

```cpp
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_count;
        prefix_count[0] = 1; // Base case: prefix sum of 0 before starting
        int total_count = 0;
        int current_sum = 0;

        for (int num : nums) {
            current_sum += num;
            int needed = current_sum - k;

            if (prefix_count.find(needed) != prefix_count.end()) {
                total_count += prefix_count[needed];
            }

            prefix_count[current_sum]++;
        }

        return total_count;
    }
};
```
