#include <iostream>
#include <vector>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxSumSquares(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> bitCount(31, 0);

        // Step 1: Count frequency of each bit position across the array
        for (int num : nums) {
            for (int b = 0; b < 30; b++) {
                if ((num >> b) & 1) {
                    bitCount[b]++;
                }
            }
        }

        long long totalSum = 0;

        // Step 2: Greedily construct the k largest possible numbers
        for (int i = 0; i < k; i++) {
            long long currentVal = 0;
            for (int b = 0; b < 30; b++) {
                if (bitCount[b] > 0) {
                    currentVal |= (1LL << b);
                    bitCount[b]--;
                }
            }
            long long squareVal = (currentVal % MOD) * (currentVal % MOD) % MOD;
            totalSum = (totalSum + squareVal) % MOD;
        }

        return totalSum;
    }
};

int main() {
    Solution solver;

    // Test Case 1: nums = [2,6,5,8], k = 2 -> Expected: 261
    vector<int> t1 = {2, 6, 5, 8};
    cout << "Test 1 Output: " << solver.maxSumSquares(t1, 2) << endl;
    // Test Case 2: nums = [4,5,4,7], k = 3 -> Expected: 90
    vector<int> t2 = {4, 5, 4, 7};
    cout << "Test 2 Output: " << solver.maxSumSquares(t2, 3) << endl;

    // Test Case 3: nums = [1,1,1], k = 1 -> Expected: 1
    vector<int> t3 = {1, 1, 1};
    cout << "Test 3 Output: " << solver.maxSumSquares(t3, 1) << endl;

    return 0;
}