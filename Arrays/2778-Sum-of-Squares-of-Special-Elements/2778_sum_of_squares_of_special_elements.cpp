#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                sum += nums[i - 1] * nums[i - 1];
            }
        }

        return sum;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1,2,3,4] -> Expected: 21
    vector<int> t1 = {1, 2, 3, 4};
    cout << "Test 1 Output: " << solver.sumOfSquares(t1) << endl;

    // Test Case 2: [2,7,1,19,18,3] -> Expected: 63
    vector<int> t2 = {2, 7, 1, 19, 18, 3};
    cout << "Test 2 Output: " << solver.sumOfSquares(t2) << endl;

    // Test Case 3: Single element [5] -> Expected: 25
    vector<int> t3 = {5};
    cout << "Test 3 Output: " << solver.sumOfSquares(t3) << endl;

    return 0;
}