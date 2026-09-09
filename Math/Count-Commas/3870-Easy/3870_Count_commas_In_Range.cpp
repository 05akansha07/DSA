/**
 * Problem: Number of Commas in Standard Number Formatting
 * Complexity:
 *   - Time: O(1)
 *   - Space: O(1)
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) {
            return 0;
        }
        return n - 999;
    }
};

// --- Follow-up: Generalized Solution for any n (up to 10^18) ---
class SolutionFollowUp {
public:
    long long countTotalCommas(long long n) {
        long long total = 0;
        long long threshold = 1000;

        while (n >= threshold) {
            total += (n - threshold + 1);
            threshold *= 1000;
        }
        return total;
    }
};

int main() {
    Solution sol;
    cout << "Test 1 (n = 1002): " << sol.countCommas(1002) << " (Expected: 3)" << endl;
    cout << "Test 2 (n = 998):  " << sol.countCommas(998) << " (Expected: 0)" << endl;
    cout << "Test 3 (n = 100000): " << sol.countCommas(100000) << " (Expected: 99001)" << endl;
    return 0;
}
