# 3736. Minimum Moves to Equal Array Elements III

**Difficulty:** Easy  
**Topics:** Array, Math, Greedy  
**Language:** C++

---

## Problem Statement

You are given an integer array `nums`.

In one move, you may increase the value of any single element `nums[i]` by $1$.

Return the **minimum total number of moves** required so that all elements in `nums` become equal.

---

## Examples

### Example 1:
- **Input:** `nums = [2, 1, 3]`
- **Output:** `3`
- **Explanation:**
  To make all elements equal:
  - Increase `nums[0] = 2` by $1$ to make it $3$.
  - Increase `nums[1] = 1` by $1$ to make it $2$.
  - Increase `nums[1] = 2` by $1$ to make it $3$.
  Now, all elements of `nums` are equal to $3$. The minimum total moves is $3$.

### Example 2:
- **Input:** `nums = [4, 4, 5]`
- **Output:** `2`
- **Explanation:**
  To make all elements equal:
  - Increase `nums[0] = 4` by $1$ to make it $5$.
  - Increase `nums[1] = 4` by $1$ to make it $5$.
  Now, all elements of `nums` are equal to $5$. The minimum total moves is $2$.

---

## Constraints

- $1 \le \text{nums.length} \le 100$
- $1 \le \text{nums}[i] \le 100$

---

## Intuition & Approach

### Monotonic Growth & Maximum Target

1. **Unidirectional Operations:**  
   Unlike problem variations where elements can be decremented or shifted, here we are **only allowed to increment** values (`nums[i] += 1`).

2. **Optimal Target Selection:**  
   - Since no element can be decreased, the final common value $T$ must be greater than or equal to every initial element:  
     $$T \ge \max(\text{nums})$$
   - Each element $x$ requires $T - x$ increments. The total moves required to reach target $T$ is:
     $$\text{Total Moves}(T) = \sum_{i=0}^{n-1} (T - \text{nums}[i]) = n \times T - \sum_{i=0}^{n-1} \text{nums}[i]$$
   - Because $n > 0$, this function is strictly increasing with respect to $T$.  
   - To minimize the total operations, we must choose the smallest possible valid value for $T$, which is precisely the maximum element currently in the array:
     $$T^* = \max(\text{nums})$$

3. **Algorithm:**  
   - Find $\text{maxVal} = \max(\text{nums})$.
   - Accumulate $\sum (\text{maxVal} - \text{nums}[i])$ across all elements.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  Finding the maximum element takes $\mathcal{O}(N)$ operations, and computing the sum of differences takes another $\mathcal{O}(N)$ pass.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Only scalar variables (`maxVal`, `count`) are used.

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
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += maxVal - nums[i];
        }
        return count;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [2, 1, 3] -> Expected: 3
    vector<int> t1 = {2, 1, 3};
    cout << "Test 1: " << solver.minMoves(t1) << endl;

    // Test Case 2: [4, 4, 5] -> Expected: 2
    vector<int> t2 = {4, 4, 5};
    cout << "Test 2: " << solver.minMoves(t2) << endl;

    return 0;
}
```
