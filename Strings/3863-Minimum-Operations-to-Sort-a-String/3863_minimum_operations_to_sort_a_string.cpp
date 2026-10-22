#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        if (n == 2) {
            return -1;
        }

        char minChar = *min_element(s.begin(), s.end());
        char maxChar = *max_element(s.begin(), s.end());

        // Can finish in 1 operation using a suffix or prefix sort
        if (s[0] == minChar || s[n - 1] == maxChar) {
            return 1;
        }

        // Check if s[0] is the sole global maximum AND s[n-1] is the sole global minimum
        char minMid = *min_element(s.begin() + 1, s.end() - 1);
        char maxMid = *max_element(s.begin() + 1, s.end() - 1);

        if (s[0] > maxMid && s[n - 1] < minMid) {
            return 3;
        }

        return 2;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "dog" -> Expected: 1
    cout << "Test 1: " << solver.minOperations("dog") << endl;

    // Test Case 2: "card" -> Expected: 2
    cout << "Test 2: " << solver.minOperations("card") << endl;

    // Test Case 3: "gf" -> Expected: -1
    cout << "Test 3: " << solver.minOperations("gf") << endl;

    return 0;
}