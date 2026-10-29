3882. Minimum XOR Path in a GridDifficulty: MediumTopics: Array, Dynamic Programming, Bit Manipulation, MatrixLanguage: C++Problem StatementYou are given a 2D integer array grid of size $m \times n$.You start at the top-left cell $(0, 0)$ and want to reach the bottom-right cell $(m - 1, n - 1)$. At each step, you may move either right or down.The cost of a path is defined as the bitwise XOR of all the values in the cells along that path, including the start and end cells.Return the minimum possible XOR value among all valid paths from $(0, 0)$ to $(m - 1, n - 1)$.ExamplesExample 1:Input: grid = [[1,2],[3,4]]Output: 6Explanation:
There are two valid paths:$(0, 0) \to (0, 1) \to (1, 1)$ with $\text{XOR} = 1 \oplus 2 \oplus 4 = 7$$(0, 0) \to (1, 0) \to (1, 1)$ with $\text{XOR} = 1 \oplus 3 \oplus 4 = 6$
The minimum XOR value among all valid paths is $6$.Example 2:Input: grid = [[6,7],[5,8]]Output: 9Explanation:
There are two valid paths:$(0, 0) \to (0, 1) \to (1, 1)$ with $\text{XOR} = 6 \oplus 7 \oplus 8 = 9$$(0, 0) \to (1, 0) \to (1, 1)$ with $\text{XOR} = 6 \oplus 5 \oplus 8 = 11$
The minimum XOR value among all valid paths is $9$.Example 3:Input: grid = [[2,7,5]]Output: 0Explanation:
There is only one valid path:$(0, 0) \to (0, 1) \to (0, 2)$ with $\text{XOR} = 2 \oplus 7 \oplus 5 = 0$
The XOR value of this path is $0$, which is the minimum possible.Constraints$1 \le m == \text{grid.length} \le 1000$$1 \le n == \text{grid}[i].\text{length} \le 1000$$m \times n \le 1000$$0 \le \text{grid}[i][j] \le 1023$Intuition & ApproachDynamic Programming with Bitset State ReachabilitySince XOR is neither monotonic nor greedy-friendly, we must keep track of all reachable XOR values at each cell rather than only a single minimum or maximum.State Space Upper Bound:The cell values satisfy $0 \le \text{grid}[i][j] \le 1023 < 2^{10}$.XOR operations on values $< 1024$ cannot produce any value $\ge 1024$.Thus, the set of all achievable XOR values at any cell $(i, j)$ is a subset of $[0, 1023]$, which fits cleanly into a std::bitset<1024>.Transitions:Any path entering $(i, j)$ must arrive from either the top cell $(i - 1, j)$ or the left cell $(i, j - 1)$.We collect the union of reachable values from top and left:
$$\text{combined} = \text{dp}[i - 1][j] \mid \text{dp}[i][j - 1]$$For every bit $v$ set in $\text{combined}$, the reachable XOR value at $(i, j)$ becomes:
$$v \oplus \text{grid}[i][j]$$Space Optimization:To reduce memory, maintain only a 1D vector of bitsets representing the previous row dp[j] and compute the current row next_dp[j].After reaching $(m - 1, n - 1)$, find the smallest index $v \in [0, 1023]$ where dp[n - 1].test(v) is true.Complexity AnalysisTime Complexity: $\mathcal{O}(m \times n \times K)$Where $K = 1024$. With $m \times n \le 1000$, total operations are bounded by $1000 \times 1024 \approx 10^6$, running well within $5\text{ ms}$.Space Complexity: $\mathcal{O}(n \times K)$ bitsOnly two rows of $n$ bitsets of size $1024$ are maintained simultaneously.C++ Implementation#include <iostream>
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
