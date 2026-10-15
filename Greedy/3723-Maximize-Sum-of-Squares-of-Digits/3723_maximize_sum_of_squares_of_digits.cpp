#include <iostream>
#include <string>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // Feasibility check:
        // A positive integer of 'num' digits has a digit sum between 1 and 9 * num.
        if (sum < 1 || (long long)sum > 9LL * num) {
            return "";
        }

        int count9 = sum / 9;
        int rem = sum % 9;
        int count0 = num - count9 - (rem > 0 ? 1 : 0);

        string result = "";
        result.reserve(num);

        // Maximize number: place 9's first, then remainder, then 0's
        result.append(count9, '9');
        if (rem > 0) {
            result.push_back('0' + rem);
        }
        result.append(count0, '0');

        return result;
    }
};

int main() {
    Solution solver;

    // Test Case 1: num = 2, sum = 3 -> Expected: "30"
    cout << "Test 1: " << solver.maxSumOfSquares(2, 3) << endl;

    // Test Case 2: num = 2, sum = 17 -> Expected: "98"
    cout << "Test 2: " << solver.maxSumOfSquares(2, 17) << endl;

    // Test Case 3: num = 1, sum = 10 -> Expected: ""
    cout << "Test 3: \"" << solver.maxSumOfSquares(1, 10) << endl;

    // Test Case 4: num = 4, sum = 18 -> Expected: "9900"
    cout << "Test 4: " << solver.maxSumOfSquares(4, 18) << endl;

    return 0;
}