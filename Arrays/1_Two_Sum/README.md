# 1. Two Sum

**Difficulty:** Easy  
**Topics:** Array, Hash Table  
**Language:** C++

---

## Problem Statement

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

You can return the answer in any order.

---

## Examples

### Example 1:
- **Input:** `nums = [2, 7, 11, 15]`, `target = 9`
- **Output:** `[0, 1]`
- **Explanation:** Because `nums[0] + nums[1] == 9`, we return `[0, 1]`.

### Example 2:
- **Input:** `nums = [3, 2, 4]`, `target = 6`
- **Output:** `[1, 2]`
- **Explanation:** Because `nums[1] + nums[2] == 6`, we return `[1, 2]`.

### Example 3:
- **Input:** `nums = [3, 3]`, `target = 6`
- **Output:** `[0, 1]`
- **Explanation:** Because `nums[0] + nums[1] == 6`, we return `[0, 1]`.

---

## Constraints

- $2 \le \text{nums.length} \le 10^4$
- $-10^9 \le \text{nums}[i] \le 10^9$
- $-10^9 \le \text{target} \le 10^9$
- **Only one valid answer exists.**

---

## Intuition & Approach

### One-Pass Hash Map Lookup

A naive brute-force approach compares every pair $(i, j)$ using nested loops, taking $\mathcal{O}(N^2)$ time. We can optimize this to $\mathcal{O}(N)$ using a hash map to trade space for speed:

1. **Complement Verification:**  
   For any number $x = \text{nums}[i]$, its required counterpart to reach `target` is:
   $$\text{complement} = \text{target} - x$$

2. **Single Traversal (Lookback Strategy):**  
   - Maintain an `unordered_map<int, int>` mapping `value -> index`.
   - As we iterate through `nums` at index `i`:
     - Check if `complement` is already stored in the map.
     - If found: return `{numMap[complement], i}`.
     - If not found: record the current number and its index `numMap[nums[i]] = i`.

3. **Why Single Pass Works:**  
   - Inserting elements *after* checking ensures that an element cannot match with itself (avoiding duplicate index usage).
   - If the pair is $(A, B)$ with $A$ appearing before $B$, the answer is caught when the loop reaches $B$ and looks back at $A$.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  We traverse the array of length $N$ once. Hash map lookups and insertions (`unordered_map`) operate in $\mathcal{O}(1)$ average time.
- **Space Complexity:** $\mathcal{O}(N)$  
  In the worst case, the hash map stores up to $N$ elements.

---

## C++ Implementation

```cpp
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            // Check if the complement was already encountered
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }

            // Store current value and its index for future lookups
            numMap[nums[i]] = i;
        }

        return {};
    }
};
```
