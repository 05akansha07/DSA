# 3727. Maximum Alternating Sum of Squares

**Difficulty:** Medium  
**Topics:** Array, Math, Greedy, Sorting  
**Language:** C++

---

## Problem Statement

You are given an integer array `nums`. You may rearrange the elements in any order.

The alternating score of an array `arr` of length $n$ is defined as:
$$\text{score} = \text{arr}[0]^2 - \text{arr}[1]^2 + \text{arr}[2]^2 - \text{arr}[3]^2 + \dots$$

Return an integer denoting the **maximum possible alternating score** of `nums` after rearranging its elements.

---

## Examples

### Example 1:
- **Input:** `nums = [1, 2, 3]`
- **Output:** `12`
- **Explanation:**
  A possible rearrangement is `[2, 1, 3]`:
  $$\text{score} = 2^2 - 1^2 + 3^2 = 4 - 1 + 9 = 12$$

### Example 2:
- **Input:** `nums = [1, -1, 2, -2, 3, -3]`
- **Output:** `16`
- **Explanation:**
  A possible rearrangement is `[-3, -1, -2, 1, 3, 2]`:
  $$\text{score} = (-3)^2 - (-1)^2 + (-2)^2 - 1^2 + 3^2 - 2^2 = 9 - 1 + 4 - 1 + 9 - 4 = 16$$

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $-4 \times 10^4 \le \text{nums}[i] \le 4 \times 10^4$

---

## Intuition & Approach

### Greedy Sign Assignment via Sorting

The alternating sum pattern assigns signs based on indices:
- Even positions ($0, 2, 4, \dots$) have a positive sign ($+$).
- Odd positions ($1, 3, 5, \dots$) have a negative sign ($-$).

1. **Sign Distribution:**  
   In an array of length $n$:
   - Exactly $\lfloor n / 2 \rfloor$ elements will be assigned a negative sign ($-$).
   - Exactly $\lceil n / 2 \rceil$ elements will be assigned a positive sign ($+$).

2. **Absolute Values & Squaring:**  
   Because squaring eliminates negative signs ($(-x)^2 = x^2$), the contribution of each element depends solely on its magnitude $|x|$. We can convert all elements in-place to their absolute values $|x|$.

3. **Greedy Maximization:**  
   To maximize the net sum $\sum(+) - \sum(-)$:
   - Assign the **smallest** $\lfloor n / 2 \rfloor$ magnitudes to the negative positions.
   - Assign the **largest** $\lceil n / 2 \rceil$ magnitudes to the positive positions.

4. **Algorithm:**  
   - Replace each element with its absolute value: `x = abs(x)`.
   - Sort the array in non-decreasing order.
   - Let $k = \lfloor n / 2 \rfloor$. Subtract the squares of elements in index range $[0, k - 1]$ and add the squares of elements in $[k, n - 1]$.
   - Use `1LL * nums[i] * nums[i]` to prevent 32-bit signed integer overflow during squaring.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \log N)$  
  Sorting the array of length $N$ dominates the runtime. The two linear summation loops take $\mathcal{O}(N)$ time.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Modifications and sorting are performed in-place on the input array without allocating additional data structures.

---

## C++ Implementation

```cpp
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // 1. In-place absolute values (no extra memory)
        for (int &x : nums) {
            x = abs(x);
        }

        // 2. Sort 32-bit ints directly (faster than 64-bit longs)
        sort(nums.begin(), nums.end());

        long long score = 0;
        int k = n / 2; // Exactly floor(n / 2) smallest values get subtracted

        // 3. Sequential loops without branch evaluation
        for (int i = 0; i < k; i++) {
            score -= 1LL * nums[i] * nums[i];
        }
        for (int i = k; i < n; i++) {
            score += 1LL * nums[i] * nums[i];
        }

        return score;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1, 2, 3] -> Expected: 12
    vector<int> t1 = {1, 2, 3};
    cout << "Test 1 Output: " << solver.maxAlternatingSum(t1) << endl;

    // Test Case 2: [1, -1, 2, -2, 3, -3] -> Expected: 16
    vector<int> t2 = {1, -1, 2, -2, 3, -3};
    cout << "Test 2 Output: " << solver.maxAlternatingSum(t2) << endl;

    // Test Case 3: [5] -> Expected: 25
    vector<int> t3 = {5};
    cout << "Test 3 Output: " << solver.maxAlternatingSum(t3) << endl;

    return 0;
}
```
