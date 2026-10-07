#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0;
        int insertionsNeeded = 0;

        for (char c : s) {
            if (c == '(') {
                openCount++;
            } else { // c == ')'
                if (openCount > 0) {
                    openCount--; // Matched pair found
                } else {
                    insertionsNeeded++; // Need to insert an opening '('
                }
            }
        }

        // Remaining openCount requires that many ')' to be appended
        return insertionsNeeded + openCount;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "())" -> Expected: 1
    string s1 = "())";
    cout << "Test 1 Output: " << solver.minAddToMakeValid(s1) << endl;

    // Test Case 2: "(((" -> Expected: 3
    string s2 = "(((";
    cout << "Test 2 Output: " << solver.minAddToMakeValid(s2) << endl;

    // Test Case 3: "()" -> Expected: 0
    string s3 = "()";
    cout << "Test 3 Output: " << solver.minAddToMakeValid(s3) << endl;

    // Test Case 4: "()))((" -> Expected: 4
    string s4 = "()))((";
    cout << "Test 4 Output: " << solver.minAddToMakeValid(s4) << endl;
    // Test Case 5: "v" -> Expected: 0 (non-parenthesis / edge case)
    string s5 = "v";
    cout << "Test 5 Output: " << solver.minAddToMakeValid(s5) << endl;
    return 0;
}