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