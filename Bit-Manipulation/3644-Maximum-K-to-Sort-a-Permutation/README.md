# 3644. Maximum K to Sort a Permutation

**Difficulty:** Medium  
**Topics:** Array, Math, Bit Manipulation  
**Language:** C++

---

## Problem Statement

You are given an integer array `nums` of length `n`, where `nums` is a permutation of the numbers in the range `[0..n - 1]`.

You may swap elements at indices `i` and `j` only if `nums[i] AND nums[j] == k`, where `AND` denotes the bitwise AND operation and `k` is a non-negative integer.

Return the **maximum value of $k$** such that the array can be sorted in non-decreasing order using any number of such swaps. If `nums` is already sorted, return `0`.

---

## Examples

### Example 1:
- **Input:** `nums = [0, 3, 2, 1]`
- **Output:** `1`
- **Explanation:** Choose $k = 1$. Swapping `nums[1] = 3` and `nums[3] = 1` is allowed since $3 \text{ AND } 1 == 1$, resulting in a sorted permutation: `[0, 1, 2, 3]`.

### Example 2:
- **Input:** `nums = [0, 1, 3, 2]`
- **Output:** `2`
- **Explanation:** Choose $k = 2$. Swapping `nums[2] = 3` and `nums[3] = 2` is allowed since $3 \text{ AND } 2 == 2$, resulting in a sorted permutation: `[0, 1, 2, 3]`.

### Example 3:
- **Input:** `nums = [3, 2, 1, 0]`
- **Output:** `0`
- **Explanation:** Only $k = 0$ allows sorting since no greater $k$ allows the required swaps where `nums[i] AND nums[j] == k`.

---

## Constraints

- $1 \le n == \text{nums.length} \le 10^5$
- $0 \le \text{nums}[i] \le n - 1$
- `nums` is a permutation of integers from $0$ to $n - 1$.

---

## Intuition & Approach

### Common Submask of Displaced Elements

1. **Permutation Cycles & Swaps:**  
   To sort a permutation, any element that is not at its target index ($nums[i] \neq i$) must participate in swaps along disjoint permutation cycles to reach its sorted position.

2. **Bitwise AND Property:**  
   If elements $u$ and $v$ can be swapped, they must satisfy:
   $$u \text{ AND } v = k$$
   This implies that for every bit set in $k$, that bit must be set in **both** $u$ and $v$. By transitivity across connected components, if an entire set of displaced elements can be rearranged into their correct positions via valid swap sequences, **every displaced element must have all the set bits of $k$**.

3. **Maximizing $k$:**  
   Since $k$ must be a submask of every single displaced element:
   $$k \subseteq \bigcap_{nums[i] \neq i} nums[i]$$
   The maximum possible value for $k$ is precisely the cumulative bitwise AND of all elements that are currently out of place:
   $$k = \bigwedge_{nums[i] \neq i} nums[i]$$

4. **Edge Case (Already Sorted):**  
   If no elements are displaced ($nums[i] == i$ for all $i$), the problem specifies returning `0`. Starting with `ans = -1` (all bits set to `1` in two's complement) naturally leaves `ans == -1` when untouched, allowing `max(ans, 0)` to return `0`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single linear pass over the array of length $N$ to evaluate displaced elements.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Only a single scalar integer variable `ans` is maintained.

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
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = -1; // -1 represents all bits set to 1 in two's complement

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans &= nums[i];
            }
        }

        // If array was already sorted, ans remains -1, so return 0
        return max(ans, 0);
    }
};

int main() {
    Solution solver;

    // Test Case 1: [0, 3, 2, 1] -> Expected: 1
    vector<int> t1 = {0, 3, 2, 1};
    cout << "Test 1: " << solver.sortPermutation(t1) << endl;

    // Test Case 2: [0, 1, 3, 2] -> Expected: 2
    vector<int> t2 = {0, 1, 3, 2};
    cout << "Test 2: " << solver.sortPermutation(t2) << endl;

    // Test Case 3: [3, 2, 1, 0] -> Expected: 0
    vector<int> t3 = {3, 2, 1, 0};
    cout << "Test 3: " << solver.sortPermutation(t3) << endl;

    return 0;
}
```
