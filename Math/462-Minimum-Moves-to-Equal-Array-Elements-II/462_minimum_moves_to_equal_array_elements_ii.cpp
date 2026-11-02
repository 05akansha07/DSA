#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;

        // O(N) average time to place the median element at index mid
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        int median = nums[mid];

        long long moves = 0;
        for (int x : nums) {
            moves += std::abs(static_cast<long long>(x) - median);
        }

        return static_cast<int>(moves);
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1, 2, 3] -> Expected: 2
    vector<int> t1 = {1, 2, 3};
    cout << "Test 1: " << solver.minMoves2(t1) << endl;

    // Test Case 2: [1, 10, 2, 9] -> Expected: 16
    vector<int> t2 = {1, 10, 2, 9};
    cout << "Test 2: " << solver.minMoves2(t2) << endl;

    return 0;
}