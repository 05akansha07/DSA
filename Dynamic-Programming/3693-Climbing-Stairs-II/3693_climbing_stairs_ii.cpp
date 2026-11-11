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
        vector <int> dp(n+1,0);
        for(int i = n - 1; i >= 0; i--){
            int cost = INT_MAX;
            int j = i + 1;
            if(j <= n){
                cost = dp[j] +costs[j-1] + (j-i)*(j-i);
            }
            j = i + 2;
            if(j <= n){
                cost = min(cost,dp[j] + costs[j-1] + (j-i)*(j-i));
            }
            j = i + 3;
            if(j <= n){
                cost = min(cost,dp[j] + costs[j-1] + (j-i)*(j-i));
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