#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string digitSum(string s, int k) {
        while (static_cast<int>(s.length()) > k) {
            string nextStr;
            int n = s.length();

            for (int i = 0; i < n; i += k) {
                int groupSum = 0;
                int limit = min(n, i + k);

                for (int j = i; j < limit; j++) {
                    groupSum += s[j] - '0';
                }

                nextStr += to_string(groupSum);
            }

            s = move(nextStr);
        }

        return s;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Expected: "135"
    cout << "Test 1: " << solver.digitSum("11111222223", 3) << endl;

    // Test Case 2: Expected: "000"
    cout << "Test 2: " << solver.digitSum("00000000", 3) << endl;

    // Test Case 3: Edge case where s.length() <= k initially -> Expected: "99"
    cout << "Test 3: " << solver.digitSum("99", 3) << endl;

    return 0;
}
