# 3963. Create Grid With Exactly One Path

**Difficulty:** Easy  
**Topics:** Array, Matrix, Constructive  
**Language:** C++

---

## Problem Statement

You are given two integers `m` and `n`, representing the number of rows and columns of a grid.

Construct any $m \times n$ grid consisting only of the characters `.` and `#`, where:
- `.` represents a free cell.
- `#` represents an obstacle cell.

A valid path is a sequence of free cells that:
- Starts at the top-left cell $(0, 0)$.
- Ends at the bottom-right cell $(m - 1, n - 1)$.
- Moves only:
  - **Right**, from $(i, j)$ to $(i, j + 1)$, or
  - **Down**, from $(i, j)$ to $(i + 1, j)$.

Return any grid such that there is **exactly one** valid path from the top-left cell to the bottom-right cell.

---

## Examples

### Example 1:
- **Input:** `m = 2, n = 3`
- **Output:** `["..#","#.."]`
- **Explanation:** The only valid path is: $(0,0) \to (0,1) \to (1,1) \to (1,2)$.

### Example 2:
- **Input:** `m = 3, n = 3`
- **Output:** `["..#","#..","##."]`
- **Explanation:** The only valid path is: $(0,0) \to (0,1) \to (1,1) \to (1,2) \to (2,2)$.

### Example 3:
- **Input:** `m = 1, n = 4`
- **Output:** `["...."]`
- **Explanation:** The only valid path is: $(0,0) \to (0,1) \to (0,2) \to (0,3)$.

---

## Constraints

- $1 \le m, n \le 25$

---

## Intuition & Approach

### Perimeter L-Path Construction

Any single non-branching chain of free cells `.` from $(0, 0)$ to $(m - 1, n - 1)$ where every cell has at most one valid move (Right or Down) guarantees that the total number of paths is strictly $1$.

A straightforward, deterministic shape is an **L-shaped path**:
1. Start with the entire $m \times n$ grid filled with obstacles `#`.
2. Carve row $0$ from column $0$ to column $n - 1$ as free cells `.`. At each step $(0, c)$ for $c < n - 1$, the only free neighbor is $(0, c + 1)$ (moving Right), because cell $(1, c)$ is `#`.
3. Carve column $n - 1$ from row $0$ to row $m - 1$ as free cells `.`. At each step $(r, n - 1)$ for $r < m - 1$, the only available move is $(r + 1, n - 1)$ (moving Down).

Because there is zero branching at any point along this trajectory:
$$(0, 0) \xrightarrow{\text{Right}} \dots \xrightarrow{\text{Right}} (0, n - 1) \xrightarrow{\text{Down}} \dots \xrightarrow{\text{Down}} (m - 1, n - 1)$$
the number of valid paths is guaranteed to be exactly $1$.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(m \times n)$  
  Initializing the grid takes $\mathcal{O}(m \times n)$ time, and carving the path takes $\mathcal{O}(m + n)$ steps.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Excluding the returned grid, no additional memory is allocated.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // Step 1: Initialize an m x n grid filled entirely with obstacles '#'
        vector<string> grid(m, string(n, '#'));

        // Step 2: Carve row 0 all the way to column n - 1
        for (int c = 0; c < n; c++) {
            grid[0][c] = '.';
        }

        // Step 3: Carve column n - 1 down to row m - 1
        for (int r = 0; r < m; r++) {
            grid[r][n - 1] = '.';
        }

        return grid;
    }
};

int main() {
    Solution solver;

    // Test Case 1: m = 2, n = 3
    auto g1 = solver.createGrid(2, 3);
    cout << "Test 1 (2x3):\n";
    for (const string& row : g1) {
        cout << row << "\n";
    }

    // Test Case 2: m = 3, n = 3
    auto g2 = solver.createGrid(3, 3);
    cout << "\nTest 2 (3x3):\n";
    for (const string& row : g2) {
        cout << row << "\n";
    }

    // Test Case 3: m = 1, n = 4
    auto g3 = solver.createGrid(1, 4);
    cout << "\nTest 3 (1x4):\n";
    for (const string& row : g3) {
        cout << row << "\n";
    }

    return 0;
}
```
