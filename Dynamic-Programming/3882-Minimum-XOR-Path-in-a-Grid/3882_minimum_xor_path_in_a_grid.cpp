#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[j] holds all reachable XOR sums at column j
        vector<bitset<1024>> dp(n);

        for (int i = 0; i < m; i++) {
            vector<bitset<1024>> next_dp(n);
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];

                if (i == 0 && j == 0) {
                    next_dp[0].set(val);
                    continue;
                }

                bitset<1024> combined;
                if (i > 0) {
                    combined |= dp[j];
                }
                if (j > 0) {
                    combined |= next_dp[j - 1];
                }

                // Transition: for each achievable XOR sum v, set (v ^ val)
                for (int v = 0; v < 1024; v++) {
                    if (combined.test(v)) {
                        next_dp[j].set(v ^ val);
                    }
                }
            }
            dp = move(next_dp);
        }

        // Find the minimum set bit at (m - 1, n - 1)
        for (int v = 0; v < 1024; v++) {
            if (dp[n - 1].test(v)) {
                return v;
            }
        }

        return 0;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Expected: 6
    vector<vector<int>> g1 = {{1, 2}, {3, 4}};
    cout << "Test 1: " << solver.minCost(g1) << endl;

    // Test Case 2: Expected: 9
    vector<vector<int>> g2 = {{6, 7}, {5, 8}};
    cout << "Test 2: " << solver.minCost(g2) << endl;

    // Test Case 3: Expected: 0
    vector<vector<int>> g3 = {{2, 7, 5}};
    cout << "Test 3: " << solver.minCost(g3) << endl;

    return 0;
}