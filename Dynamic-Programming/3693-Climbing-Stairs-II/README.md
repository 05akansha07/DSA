# 3693. Climbing Stairs II

**Difficulty:** Medium  
**Topics:** Array, Dynamic Programming  
**Language:** C++

---

## Problem Statement

You are climbing a staircase with $n + 1$ steps, numbered from $0$ to $n$.

You are also given a 1-indexed integer array `costs` of length $n$, where `costs[i]` is the cost of step $i$.

From step $i$, you can jump only to step $i + 1$, $i + 2$, or $i + 3$. The cost of jumping from step $i$ to step $j$ is defined as:

$$\text{costs}[j] + (j - i)^2$$

You start from step $0$ with $\text{cost} = 0$.

Return the **minimum total cost** to reach step $n$.

---

## Examples

### Example 1:
- **Input:** `n = 4`, `costs = [1, 2, 3, 4]`
- **Output:** `13`
- **Explanation:**
  - $0 \to 1$: $\text{costs}[1] + (1 - 0)^2 = 1 + 1 = 2$
  - $1 \to 2$: $\text{costs}[2] + (2 - 1)^2 = 2 + 1 = 3$
  - $2 \to 4$: $\text{costs}[4] + (4 - 2)^2 = 4 + 4 = 8$
  - Total: $2 + 3 + 8 = 13$

### Example 2:
- **Input:** `n = 4`, `costs = [5, 1, 6, 2]`
- **Output:** `11`
- **Explanation:**
  - $0 \to 2$: $\text{costs}[2] + (2 - 0)^2 = 1 + 4 = 5$
  - $2 \to 4$: $\text{costs}[4] + (4 - 2)^2 = 2 + 4 = 6$
  - Total: $5 + 6 = 11$

### Example 3:
- **Input:** `n = 3`, `costs = [9, 8, 3]`
- **Output:** `12`
- **Explanation:**
  - $0 \to 3$: $\text{costs}[3] + (3 - 0)^2 = 3 + 9 = 12$

---

## Constraints

- $1 \le n == \text{costs.length} \le 10^5$
- $1 \le \text{costs}[i] \le 10^4$

---

## Intuition & Approach

### Backward Dynamic Programming

Let $\text{dp}[i]$ represent the minimum cost required to reach step $n$ starting from step $i$.

1. **Base Case:**
   - $\text{dp}[n] = 0$, since we are already at the destination.

2. **Transitions:**
   - From step $i$, we can jump to $j \in \{i + 1, i + 2, i + 3\}$ such that $j \le n$.
   - Since `costs` is 1-indexed, landing on step $j$ requires paying `costs[j - 1]`.
   - The jump penalty is $(j - i)^2$.
   - Transition relation:
     $$\text{dp}[i] = \min_{\substack{j \in \{i + 1, i + 2, i + 3\} \\ j \le n}} \left( \text{dp}[j] + \text{costs}[j - 1] + (j - i)^2 \right)$$

3. **Evaluation Order:**
   - Compute states backwards from $i = n - 1$ down to $0$.
   - The answer is stored at $\text{dp}[0]$.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$  
  There are $n + 1$ states, and each state evaluates at most $3$ constant-time transitions.
- **Space Complexity:** $\mathcal{O}(n)$  
  Using a DP array of size $n + 1$. *(Note: This can be optimized to $\mathcal{O}(1)$ space using 4 rolling variables).*

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int cost = INT_MAX;
            for (int step = 1; step <= 3; step++) {
                int j = i + step;
                if (j <= n) {
                    cost = min(cost, dp[j] + costs[j - 1] + step * step);
                }
            }
            dp[i] = cost;
        }

        return dp[0];
    }
};

int main() {
    Solution solver;

    // Test Case 1: Expected: 13
    vector<int> costs1 = {1, 2, 3, 4};
    cout << "Test 1: " << solver.climbStairs(4, costs1) << endl;

    // Test Case 2: Expected: 11
    vector<int> costs2 = {5, 1, 6, 2};
    cout << "Test 2: " << solver.climbStairs(4, costs2) << endl;

    // Test Case 3: Expected: 12
    vector<int> costs3 = {9, 8, 3};
    cout << "Test 3: " << solver.climbStairs(3, costs3) << endl;

    return 0;
}
```
