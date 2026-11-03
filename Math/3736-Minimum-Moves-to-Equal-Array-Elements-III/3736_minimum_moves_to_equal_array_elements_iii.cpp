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
    int minMoves(vector<int>& nums) {
        int n =  nums.size();
        int maxVal = *max_element(nums.begin(),nums.end());
        int count = 0;
        for(int i = 0; i < n; i++){
            count += maxVal-nums[i];
        }
        return count;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [2, 1, 3] -> Expected: 3
    vector<int> t1 = {2, 1, 3};
    cout << "Test 1: " << solver.minMoves(t1) << endl;

    // Test Case 2: [4, 4, 5] -> Expected: 2
    vector<int> t2 = {4, 4, 5};
    cout << "Test 2: " << solver.minMoves(t2) << endl;

    return 0;
}