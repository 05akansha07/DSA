#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxVal = nums.back();
        vector<int> dp(maxVal + 2, 0);
        int maxLen = 1;

        for (int x : nums) {
            // Update x + 1 BEFORE x so a single element isn't counted twice
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);
            dp[x] = max(dp[x], dp[x - 1] + 1);

            maxLen = max({maxLen, dp[x], dp[x + 1]});
        }

        return maxLen;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [2, 1, 5, 1, 1] -> Expected: 3
    vector<int> nums1 = {2, 1, 5, 1, 1};
    cout << "Test 1: " << solver.maxSelectedElements(nums1) << endl;

    // Test Case 2: [1, 4, 7, 10] -> Expected: 1
    vector<int> nums2 = {1, 4, 7, 10};
    cout << "Test 2: " << solver.maxSelectedElements(nums2) << endl;

    // Test Case 3: Duplicate elements [1, 1, 1] -> Expected: 2 ([1, 2])
    vector<int> nums3 = {1, 1, 1};
    cout << "Test 3: " << solver.maxSelectedElements(nums3) << endl;

    return 0;
}
