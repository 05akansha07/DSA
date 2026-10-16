#include <iostream>
#include <vector>
#include <vector>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            // Using a boolean visited array since 1 <= nums[i] <= 100
            vector<bool> seen(101, false);
            int distinctCount = 0;

            for (int j = i; j < n; j++) {
                if (!seen[nums[j]]) {
                    seen[nums[j]] = true;
                    distinctCount++;
                }
                totalSum += distinctCount * distinctCount;
            }
        }

        return totalSum;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1, 2, 1] -> Expected: 15
    vector<int> t1 = {1, 2, 1};
    cout << "Test 1 Output: " << solver.sumCounts(t1) << endl;

    // Test Case 2: [1, 1] -> Expected: 3
    vector<int> t2 = {1, 1};
    cout << "Test 2 Output: " << solver.sumCounts(t2) << endl;
    return 0;
}