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
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minVal = INT_MAX;
        long long sum = 0; 
        for(int i = 0; i < n; i++){
            if(nums[i] < minVal){
                minVal = nums[i];
            }
            sum += nums[i];
        }
        return static_cast<int> (sum - 1LL*n*minVal); 
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1, 2, 3] -> Expected: 3
    vector<int> t1 = {1, 2, 3};
    cout << "Test 1: " << solver.minMoves(t1) << endl;

    // Test Case 2: [1, 1, 1] -> Expected: 0
    vector<int> t2 = {1, 1, 1};
    cout << "Test 2: " << solver.minMoves(t2) << endl;

    // Test Case 3: [-100, 0, 100] -> Expected: 300
    vector<int> t3 = {-100, 0, 100};
    cout << "Test 3: " << solver.minMoves(t3) << endl;

    return 0;
}