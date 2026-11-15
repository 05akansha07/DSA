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
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                int len = j - i + 1;
                if(len >= l && len <= r && sum > 0){
                    ans = min(ans,sum);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Expected: 1
    vector<int> nums1 = {3, -2, 1, 4};
    cout << "Test 1: " << solver.minimumSumSubarray(nums1, 2, 3) << endl;

    // Test Case 2: Expected: -1
    vector<int> nums2 = {-2, 2, -3, 1};
    cout << "Test 2: " << solver.minimumSumSubarray(nums2, 2, 3) << endl;

    // Test Case 3: Expected: 3
    vector<int> nums3 = {1, 2, 3, 4};
    cout << "Test 3: " << solver.minimumSumSubarray(nums3, 2, 4) << endl;

    return 0;
}