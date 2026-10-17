# 3875. Construct Uniform Parity Array I

**Difficulty:** Easy  
**Topics:** Array, Math  
**Language:** C++

---

## Problem Statement

You are given an array `nums1` of `n` distinct integers.

You want to construct another array `nums2` of length `n` such that the elements in `nums2` are either all odd or all even.

For each index `i`, you must choose exactly one of the following (in any order):
- `nums2[i] = nums1[i]`
- `nums2[i] = nums1[i] - nums1[j]`, for an index $j 
eq i$

Return `true` if it is possible to construct such an array, otherwise, return `false`.

---

## Examples

### Example 1:
- **Input:** `nums1 = [2, 3]`
- **Output:** `true`
- **Explanation:**
  - Choose `nums2[0] = nums1[0] - nums1[1] = 2 - 3 = -1`.
  - Choose `nums2[1] = nums1[1] = 3`.
  - `nums2 = [-1, 3]`, and both elements are odd. Thus, the answer is `true`.

### Example 2:
- **Input:** `nums1 = [4, 6]`
- **Output:** `true`
- **Explanation:**
  - Choose `nums2[0] = nums1[0] = 4`.
  - Choose `nums2[1] = nums1[1] = 6`.
  - `nums2 = [4, 6]`, and all elements are even. Thus, the answer is `true`.

---

## Constraints

- $1 \le n == 	ext{nums1.length} \le 100$
- $1 \le 	ext{nums1}[i] \le 100$
- `nums1` consists of distinct integers.

---

## Intuition & Approach

### Parity Arithmetic Analysis

Consider the parity rules for integer subtraction:
- $	ext{Even} - 	ext{Even} = 	ext{Even}$
- $	ext{Odd} - 	ext{Odd} = 	ext{Even}$
- $	ext{Even} - 	ext{Odd} = 	ext{Odd}$
- $	ext{Odd} - 	ext{Even} = 	ext{Odd}$

Let $O$ be the number of odd integers in `nums1`:

1. **If $n = 1$:**  
   A single element is trivially uniform in parity.

2. **If $O = 0$ (All Even):**  
   Every element is already even. Keep `nums2[i] = nums1[i]` for all $i$. The resulting array is all even $	o$ **true**.

3. **If $O \ge 2$ (Two or More Odds):**  
   We can make every element **even**:
   - For any even number `nums1[i]`: keep it unchanged (`nums2[i] = nums1[i]`).
   - For any odd number `nums1[i]`: pick any other odd number `nums1[j]` ($j 
eq i$) and set `nums2[i] = nums1[i] - nums1[j]`. Since $	ext{Odd} - 	ext{Odd} = 	ext{Even}$, all elements become even $	o$ **true**.

4. **If $O = 1$ (Exactly One Odd):**  
   We can make every element **odd**:
   - Let the unique odd element be at index $k$. Keep it unchanged: `nums2[k] = nums1[k]`.
   - For every even number `nums1[i]` ($i 
eq k$): subtract the odd number `nums1[k]`, setting `nums2[i] = nums1[i] - nums1[k]`. Since $	ext{Even} - 	ext{Odd} = 	ext{Odd}$, all elements become odd $	o$ **true**.

Because every scenario across all possible combinations of numbers yields a valid configuration, it is **always possible** to construct an array with uniform parity. Hence, the function unconditionally returns `true`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$  
  Direct constant-time return without needing to inspect the array.
- **Space Complexity:** $\mathcal{O}(1)$  
  Zero auxiliary space.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [2, 3] -> Expected: true
    vector<int> nums1 = {2, 3};
    cout << "Test 1: " << (sol.uniformArray(nums1) ? "true" : "false") << endl;

    // Test Case 2: [4, 6, 8] -> Expected: true
    vector<int> nums2 = {4, 6, 8};
    cout << "Test 2: " << (sol.uniformArray(nums2) ? "true" : "false") << endl;

    // Test Case 3: [1, 5, 7] -> Expected: true
    vector<int> nums3 = {1, 5, 7};
    cout << "Test 3: " << (sol.uniformArray(nums3) ? "true" : "false") << endl;

    return 0;
}
```
