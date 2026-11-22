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
    bool checkString(const string& s) {
        int n = s.length();
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == 'b' && s[i] == 'a') {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "aaabbb" -> Expected: 1 (true)
    cout << "Test 1: " << solver.checkString("aaabbb") << endl;

    // Test Case 2: "abab" -> Expected: 0 (false)
    cout << "Test 2: " << solver.checkString("abab") << endl;

    // Test Case 3: "bbb" -> Expected: 1 (true)
    cout << "Test 3: " << solver.checkString("bbb") << endl;

    return 0;
}
