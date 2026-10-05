#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { // c == '*'
                low--;
                high++;
            }

            // More ')' than possible '(' and '*' combined
            if (high < 0) return false;

            // low cannot be negative; '*' as ')' cannot carry a negative balance
            low = max(low, 0);
        }

        return low == 0;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "()" -> Expected: true
    cout << boolalpha;
    cout << "Test 1: " << solver.checkValidString("()") << endl;

    // Test Case 2: "(*)" -> Expected: true
    cout << "Test 2: " << solver.checkValidString("(*)") << endl;

    // Test Case 3: "(*))" -> Expected: true
    cout << "Test 3: " << solver.checkValidString("(*))") << endl;

    // Test Case 4: "(" -> Expected: false
    cout << "Test 4: " << solver.checkValidString("(") << endl;

    // Test Case 5: "*(())*" -> Expected: true
    cout << "Test 5: " << solver.checkValidString("*(())*") << endl;
    return 0;
}