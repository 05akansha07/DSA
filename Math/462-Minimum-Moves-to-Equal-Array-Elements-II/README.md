# 462. Minimum Moves to Equal Array Elements II

**Difficulty:** Medium  
**Topics:** Array, Math, Sorting  
**Language:** C++

---

## Problem Statement

Given an integer array `nums` of size $n$, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by $1$.

Test cases are designed so that the answer will fit in a 32-bit integer.

---

## Examples

### Example 1:
- **Input:** `nums = [1, 2, 3]`
- **Output:** `2`
- **Explanation:** Only two moves are needed (each move increments or decrements one element):
  `[1, 2, 3]` $\to$ `[2, 2, 3]` $\to$ `[2, 2, 2]`

### Example 2:
- **Input:** `nums = [1, 10, 2, 9]`
- **Output:** `16`
- **Explanation:** Choosing the median (either 2 or 9):
  $|1 - 2| + |10 - 2| + |2 - 2| + |9 - 2| = 1 + 8 + 0 + 7 = 16$.

---

## Constraints

- $n == \text{nums.length}$
- $1 \le \text{nums.length} \le 10^5$
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## Intuition & Approach

### Median as the L1 Minimizer

The problem requires finding an integer target $k$ that minimizes the sum of absolute deviations:
$$f(k) = \sum_{i=0}^{n-1} | \text{nums}[i] - k |$$

1. **Why Median?**  
   - Consider any pair of elements $(a, b)$ with $a \le b$. For any target $k$ located between $a$ and $b$ ($a \le k \le b$), the combined distance is:
     $$|a - k| + |b - k| = (k - a) + (b - k) = b - a$$
   - If $k$ is chosen outside the interval $[a, b]$, the combined distance strictly increases.
   - Pairing smallest and largest elements together from the outside in shows that placing $k$ within the innermost intersection—the **median** of the array—minimizes the sum of distances for all pairs simultaneously.

2. **Linear Time Selection via `std::nth_element`:**  
   - Instead of fully sorting the array in $\mathcal{O}(N \log N)$ time, we only need the element at index $\lfloor n / 2 \rfloor$.
   - C++ standard library provides `std::nth_element`, which implements introselect (Quickselect with fallback) and finds the $k$-th smallest element in $\mathcal{O}(N)$ average time.

3. **Accumulation:**  
   - Once the median is located at index $n / 2$, iterate through `nums` and compute $\sum |\text{nums}[i] - \text{median}|$.
   - Use `long long` intermediate math to prevent 32-bit signed integer overflow when subtracting large numbers before casting to `int`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$ average  
  `std::nth_element` finds the median in $\mathcal{O}(N)$ expected time ($\mathcal{O}(N^2)$ worst case, though introselect prevents degradation in practice). Summing the distances takes a single $\mathcal{O}(N)$ pass.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  The rearrangement occurs in-place within `nums`.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;

        // O(N) average time to place the median element at index mid
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        int median = nums[mid];

        long long moves = 0;
        for (int x : nums) {
            moves += std::abs(static_cast<long long>(x) - median);
        }

        return static_cast<int>(moves);
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1, 2, 3] -> Expected: 2
    vector<int> t1 = {1, 2, 3};
    cout << "Test 1: " << solver.minMoves2(t1) << endl;

    // Test Case 2: [1, 10, 2, 9] -> Expected: 16
    vector<int> t2 = {1, 10, 2, 9};
    cout << "Test 2: " << solver.minMoves2(t2) << endl;

    return 0;
}
```
