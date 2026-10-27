# 3619. Count Islands With Total Value Divisible by K

**Difficulty:** Medium  
**Topics:** Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix  
**Language:** C++

---

## Problem Statement

You are given an $m \times n$ matrix `grid` and a positive integer `k`. An island is a group of positive integers (representing land) that are 4-directionally connected (horizontally or vertically).

The **total value** of an island is the sum of the values of all cells in the island.

Return the number of islands with a total value divisible by `k`.

---

## Examples

### Example 1:
- **Input:** `grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]]`, `k = 5`
- **Output:** `2`
- **Explanation:**
  - Island 1: values at (0,1), (0,2) sum to $2 + 1 = 3$ (not divisible by 5).
  - Island 2: value at (1,1) is $5$ (divisible by 5: $5 \% 5 == 0$).
  - Island 3: value at (1,4) is $5$ (divisible by 5: $5 \% 5 == 0$).
  - Island 4: values at (2,2), (3,1), (3,2), (3,3), (4,1), (4,4)... sum is checked accordingly.
  - Exactly 2 islands have a total sum divisible by 5.

### Example 2:
- **Input:** `grid = [[3,0,3,0],[0,3,0,3],[3,0,3,0]]`, `k = 3`
- **Output:** `6`
- **Explanation:** There are 6 isolated cells of value 3, each forming an island of sum 3 (divisible by 3).

---

## Constraints

- $m == \text{grid.length}$
- $n == \text{grid}[i].\text{length}$
- $1 \le m, n \le 1000$
- $1 \le m \times n \le 10^5$
- $0 \le \text{grid}[i][j] \le 10^6$
- $1 \le k \le 10^6$

---

## Intuition & Approach

### Connected Components via DFS & In-Place Traversal

1. **Island Definition:**  
   Land cells are defined by $\text{grid}[i][j] > 0$, while water/visited cells are represented by $0$. Two land cells belong to the same island if they are adjacent horizontally or vertically.

2. **Summing Component Values:**  
   - Iterate through every cell $(i, j)$ in the matrix.
   - When an unvisited land cell $\text{grid}[i][j] > 0$ is found, start a Depth-First Search (DFS) to explore its connected component.
   - Accumulate cell values into a 64-bit integer (`long long sum`) to prevent overflow, as cell values can be up to $10^6$ and $m \times n \le 10^5$ (maximum possible island sum $\approx 10^{11}$).
   - Set $\text{grid}[i][j] = 0$ upon visit to avoid infinite loops and eliminate the need for an auxiliary visited table.

3. **Divisibility Check:**  
   Once the entire connected island has been traversed and its total sum calculated, increment `count` if $\text{sum} \pmod k == 0$.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(m \times n)$  
  Every cell in the grid is visited at most a constant number of times during the matrix scan and DFS traversals.
- **Space Complexity:** $\mathcal{O}(m \times n)$  
  The recursion call stack of DFS can grow up to $\mathcal{O}(m \times n)$ in the worst case (e.g., when the entire grid consists of land cells forming a single snake-like path). Constant auxiliary space otherwise since the grid is modified in-place.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
private:
    int m, n;
    const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    long long dfs(int i, int j, vector<vector<int>>& grid) {
        long long sum = grid[i][j];
        grid[i][j] = 0; // Mark visited

        for (const auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] > 0) {
                sum += dfs(ni, nj, grid);
            }
        }
        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long totalValue = dfs(i, j, grid);
                    if (totalValue % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Expected: 2
    vector<vector<int>> g1 = {
        {0, 2, 1, 0, 0},
        {0, 5, 0, 0, 5},
        {0, 0, 1, 0, 0},
        {0, 1, 4, 7, 0},
        {0, 2, 0, 0, 8}
    };
    cout << "Test 1: " << solver.countIslands(g1, 5) << endl;

    // Test Case 2: Expected: 6
    vector<vector<int>> g2 = {
        {3, 0, 3, 0},
        {0, 3, 0, 3},
        {3, 0, 3, 0}
    };
    cout << "Test 2: " << solver.countIslands(g2, 3) << endl;

    return 0;
}
```
