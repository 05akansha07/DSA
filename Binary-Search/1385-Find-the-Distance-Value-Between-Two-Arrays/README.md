# 1385. Find the Distance Value Between Two Arrays

**Difficulty:** Easy  
**Topics:** Array, Two Pointers, Binary Search, Sorting  
**Language:** C++

---

## Problem Statement

Given two integer arrays `arr1` and `arr2`, and the integer `d`, return the distance value between the two arrays.

The distance value is defined as the number of elements `arr1[i]` such that there is **not** any element `arr2[j]` where:
$$\vert \text{arr1}[i] - \text{arr2}[j] \vert \le d$$

---

## Examples

### Example 1:
- **Input:** `arr1 = [4, 5, 8]`, `arr2 = [10, 9, 1, 8]`, `d = 2`
- **Output:** `2`
- **Explanation:**
  - For `arr1[0] = 4`:
    - $|4 - 10| = 6 > 2$
    - $|4 - 9| = 5 > 2$
    - $|4 - 1| = 3 > 2$
    - $|4 - 8| = 4 > 2$
    - Condition satisfied.
  - For `arr1[1] = 5`:
    - $|5 - 10| = 5 > 2$
    - $|5 - 9| = 4 > 2$
    - $|5 - 1| = 4 > 2$
    - $|5 - 8| = 3 > 2$
    - Condition satisfied.
  - For `arr1[2] = 8`:
    - $|8 - 10| = 2 \le 2$ (Invalidates condition)
  - Result $= 2$.

### Example 2:
- **Input:** `arr1 = [1, 4, 2, 3]`, `arr2 = [-4, -3, 6, 10, 20, 30]`, `d = 3`
- **Output:** `2`

### Example 3:
- **Input:** `arr1 = [2, 1, 100, 3]`, `arr2 = [-5, -2, 10, -3, 7]`, `d = 6`
- **Output:** `1`

---

## Constraints

- $1 \le \text{arr1.length}, \text{arr2.length} \le 500$
- $-1000 \le \text{arr1}[i], \text{arr2}[j] \le 1000$
- $0 \le d \le 100$

---

## Intuition & Approach

### Condition Analysis
For a fixed element $x \in \text{arr1}$, the invalidating condition is:
$$\vert x - y \vert \le d \iff x - d \le y \le x + d$$
Thus, an element $x$ is valid if and only if **no** element $y \in \text{arr2}$ falls inside the closed range $[x - d, x + d]$.

### Implementation Strategies

1. **Direct Simulation / Linear Scan:**
   - For every element $x \in \text{arr1}$, iterate through all elements $y \in \text{arr2}$.
   - If any $|x - y| \le d$, mark $x$ as invalid and immediately break out of the inner loop.
   - If the inner loop finishes without finding any violating element, increment `count`.
   - Given $N, M \le 500$, $N \times M \le 2.5 \times 10^5$, which executes in less than $2\text{ ms}$.

2. **Binary Search Optimization (Alternative):**
   - Sort `arr2` in $\mathcal{O}(M \log M)$ time.
   - For each element $x \in \text{arr1}$, perform a binary search using `std::lower_bound` to find the first element $\ge x - d$.
   - If that element exists and is $\le x + d$, then a violating element exists in the range.
   - Overall complexity with binary search: $\mathcal{O}((M + N) \log M)$.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \times M)$  
  Where $N = \text{arr1.length}$ and $M = \text{arr2.length}$. In the worst case, every pair is compared. With early break optimizations, average runtime is even faster.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Only scalar loop counters and boolean flags are used.

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
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            bool isValid = true;
            for (int j = 0; j < m; j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Expected: 2
    vector<int> a1 = {4, 5, 8};
    vector<int> b1 = {10, 9, 1, 8};
    cout << "Test 1: " << solver.findTheDistanceValue(a1, b1, 2) << endl;

    // Test Case 2: Expected: 2
    vector<int> a2 = {1, 4, 2, 3};
    vector<int> b2 = {-4, -3, 6, 10, 20, 30};
    cout << "Test 2: " << solver.findTheDistanceValue(a2, b2, 3) << endl;

    // Test Case 3: Expected: 1
    vector<int> a3 = {2, 1, 100, 3};
    vector<int> b3 = {-5, -2, 10, -3, 7};
    cout << "Test 3: " << solver.findTheDistanceValue(a3, b3, 6) << endl;

    return 0;
}
```
