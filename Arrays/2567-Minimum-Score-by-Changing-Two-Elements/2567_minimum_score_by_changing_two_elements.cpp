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
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        return min({
            nums[n-3] - nums[0],nums[n-1] - nums[2],nums[n-2] - nums[1]
        });
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1, 4, 7, 8, 5] -> Expected: 3
    vector<int> nums1 = {1, 4, 7, 8, 5};
    cout << "Test 1: " << solver.minimizeSum(nums1) << endl;

    // Test Case 2: [1, 4, 3] -> Expected: 0
    vector<int> nums2 = {1, 4, 3};
    cout << "Test 2: " << solver.minimizeSum(nums2) << endl;

    return 0;
}
