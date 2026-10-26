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