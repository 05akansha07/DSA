# 3876. Construct Uniform Parity Array II

**Difficulty:** Medium  
**Topics:** Array, Math, Greedy  
**Language:** C++

---

## Problem Statement

You are given an array `nums1` of `n` distinct integers.

You want to construct another array `nums2` of length `n` such that the elements in `nums2` are either all odd or all even.

For each index `i`, you must choose exactly one of the following (in any order):
- `nums2[i] = nums1[i]`
- `nums2[i] = nums1[i] - nums1[j]`, for an index $j \neq i$, such that $\text{nums1}[i] - \text{nums1}[j] \ge 1$

Return `true` if it is possible to construct such an array, otherwise return `false`.

---

## Examples

### Example 1:
- **Input:** `nums1 = [1, 4, 7]`
- **Output:** `true`
- **Explanation:**
  - Set `nums2[0] = nums1[0] = 1`.
  - Set `nums2[1] = nums1[1] - nums1[0] = 4 - 1 = 3`.
  - Set `nums2[2] = nums1[2] = 7`.
  - `nums2 = [1, 3, 7]`, and all elements are odd. Thus, the answer is `true`.

### Example 2:
- **Input:** `nums1 = [2, 3]`
- **Output:** `false`
- **Explanation:** It is not possible to construct `nums2` such that all elements have the same parity. Thus, the answer is `false`.

### Example 3:
- **Input:** `nums1 = [4, 6]`
- **Output:** `true`
- **Explanation:**
  - Set `nums2[0] = nums1[0] = 4`.
  - Set `nums2[1] = nums1[1] = 6`.
  - `nums2 = [4, 6]`, and all elements are even. Thus, the answer is `true`.

---

## Constraints

- $1 \le n == \text{nums1.length} \le 10^5$
- $1 \le \text{nums1}[i] \le 10^9$
- `nums1` consists of distinct integers.

---

## Intuition & Approach

### Minimum Element Parity Analysis

The restriction $\text{nums1}[i] - \text{nums1}[j] \ge 1$ strictly requires choosing a smaller element $\text{nums1}[j] < \text{nums1}[i]$.

1. **The Role of the Global Minimum (`mini`):**  
   The smallest element in `nums1`, `mini`, has no strictly smaller element available in the array. Thus, `mini` can never perform Option 2 and is forced to retain its original value (`nums2 = mini`). Consequently, **`mini` dictates the only viable uniform parity for the entire array**.

2. **Case 1: `mini` is Odd (Target Parity = Odd):**  
   - Any odd element can simply keep its original value.
   - Any even element $x$ is strictly greater than `mini` ($x > \text{mini}$). We can subtract `mini`:
     $$\text{Even} - \text{Odd} = \text{Odd}$$
     This always produces a valid positive odd number.
   - Hence, if `mini` is odd, it is **always possible** (`true`).

3. **Case 2: `mini` is Even (Target Parity = Even):**  
   - The entire array must become even.
   - Any even element can keep its original value.
   - To make an odd element even, it must subtract a smaller odd element:
     $$\text{Odd} - \text{Odd} = \text{Even}$$
   - However, consider the **smallest odd element** in `nums1`: there are no smaller odd elements in the array to subtract from it! Thus, the smallest odd element can never become even.
   - Therefore, if `mini` is even, a uniform array is only possible if there are **no odd numbers** in `nums1` at all.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass through the array to find the global minimum and check for the existence of an odd number.
- **Space Complexity:** $\mathcal{O}(1)$  
  Only scalar variables (`mini`, `hasOdd`) are used.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasOdd = false;
        int mini = INT_MAX;

        for (int x : nums1) {
            mini = min(mini, x);
            if (x % 2 != 0) {
                hasOdd = true;
            }
        }

        return (mini % 2 != 0) || !hasOdd;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [1, 4, 7] -> mini = 1 (Odd) -> Expected: true
    vector<int> nums1 = {1, 4, 7};
    cout << "Test 1: " << (sol.uniformArray(nums1) ? "true" : "false") << endl;

    // Test Case 2: [2, 4, 6] -> mini = 2 (Even, no odds) -> Expected: true
    vector<int> nums2 = {2, 4, 6};
    cout << "Test 2: " << (sol.uniformArray(nums2) ? "true" : "false") << endl;

    // Test Case 3: [2, 3, 5] -> mini = 2 (Even, has odds) -> Expected: false
    vector<int> nums3 = {2, 3, 5};
    cout << "Test 3: " << (sol.uniformArray(nums3) ? "true" : "false") << endl;

    return 0;
}
```
