# 1254. Number of Closed Islands

**Difficulty:** Medium  
**Topics:** Array, Depth-First Search, Breadth-First Search, Union Find, Matrix  
**Language:** C++

---

## Problem Statement

Given a 2D `grid` consists of `0`s (land) and `1`s (water). An island is a maximal 4-directionally connected group of `0`s and a **closed island** is an island totally (all left, top, right, bottom) surrounded by `1`s.

Return the number of closed islands.

---

## Examples

### Example 1:
- **Input:** `grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]`
- **Output:** `2`
- **Explanation:** Islands in gray/inner areas are closed because they are completely surrounded by water (group of 1s).

### Example 2:
- **Input:** `grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]`
- **Output:** `1`

### Example 3:
- **Input:** 
  ```text
  grid = [[1,1,1,1,1,1,1],
          [1,0,0,0,0,0,1],
          [1,0,1,1,1,0,1],
          [1,0,1,0,1,0,1],
          [1,0,1,1,1,0,1],
          [1,0,0,0,0,0,1],
          [1,1,1,1,1,1,1]]
  ```
- **Output:** `2`

---

## Constraints

- $1 \le \text{grid.length}, \text{grid}[0].\text{length} \le 100$
- $0 \le \text{grid}[i][j] \le 1$

---

## Intuition & Approach

### Boundary Flooding (Two-Pass DFS)

A group of connected land cells (`0`) forms a closed island if and only if **no cell in the component touches the perimeter boundary** of the grid. If an island touches the outer boundary, it cannot be fully surrounded by water (`1`) on all four sides.

1. **Step 1: Invalidate Boundary-Connected Land**
   - Iterate through all four borders (top, bottom, left, right edges).
   - Whenever an unvisited land cell (`grid[r][c] == 0`) is detected on any border, trigger a DFS traversal.
   - During the DFS, flood-fill the entire connected component by setting `grid[r][c] = 1`. This safely removes every land cell connected to the perimeter from consideration.

2. **Step 2: Count Enclosed Islands**
   - Traverse the remaining interior cells: $1 \le r < m - 1$ and $1 \le c < n - 1$.
   - Any land cell (`grid[r][c] == 0`) found at this point is guaranteed to belong to a strictly closed island.
   - Increment `closedIslands++`, and run DFS starting from that cell to mark the entire component as visited (`1`).

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(M \times N)$  
  Every cell in the $M \times N$ grid is visited at most a constant number of times across both boundary and interior DFS phases.
- **Space Complexity:** $\mathcal{O}(M \times N)$ auxiliary space  
  In the worst-case scenario (e.g., entire grid is land), the DFS call stack can reach a recursion depth of $\mathcal{O}(M \times N)$.

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
    void dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 0) {
            return;
        }

        // Mark visited by turning land (0) into water (1)
        grid[r][c] = 1;

        dfs(grid, r + 1, c, m, n);
        dfs(grid, r - 1, c, m, n);
        dfs(grid, r, c + 1, m, n);
        dfs(grid, r, c - 1, m, n);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Step 1: Invalidate all islands connected to the boundary
        for (int r = 0; r < m; r++) {
            if (grid[r][0] == 0) dfs(grid, r, 0, m, n);
            if (grid[r][n - 1] == 0) dfs(grid, r, n - 1, m, n);
        }

        for (int c = 0; c < n; c++) {
            if (grid[0][c] == 0) dfs(grid, 0, c, m, n);
            if (grid[m - 1][c] == 0) dfs(grid, m - 1, c, m, n);
        }

        // Step 2: Count all fully enclosed interior islands
        int closedIslands = 0;
        for (int r = 1; r < m - 1; r++) {
            for (int c = 1; c < n - 1; c++) {
                if (grid[r][c] == 0) {
                    closedIslands++;
                    dfs(grid, r, c, m, n);
                }
            }
        }

        return closedIslands;
    }
};

int main() {
    Solution solver;

    // Test Case 1
    vector<vector<int>> g1 = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}
    };
    cout << "Test 1: " << solver.closedIsland(g1) << endl;

    // Test Case 2
    vector<vector<int>> g2 = {
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0}
    };
    cout << "Test 2: " << solver.closedIsland(g2) << endl;

    return 0;
}
```
