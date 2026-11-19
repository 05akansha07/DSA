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
    int minChanges(const string& s) {
        int changes = 0;
        int n = s.length();

        for (int i = 0; i < n; i += 2) {
            if (s[i] != s[i + 1]) {
                changes++;
            }
        }

        return changes;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "1001" -> Expected: 2
    cout << "Test 1: " << solver.minChanges("1001") << endl;

    // Test Case 2: "10" -> Expected: 1
    cout << "Test 2: " << solver.minChanges("10") << endl;

    // Test Case 3: "0000" -> Expected: 0
    cout << "Test 3: " << solver.minChanges("0000") << endl;

    return 0;
}
