#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                // If depth > 0, this '(' is not the outermost one
                if (depth > 0) {
                    ans.push_back(c);
                }
                depth++;
            } else { // c == ')'
                depth--;
                // If depth > 0, this ')' is not the outermost one
                if (depth > 0) {
                    ans.push_back(c);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "(()())(())" -> Expected: "()()()"
    string s1 = "(()())(())";
    cout << "Test 1 Output: \"" << solver.removeOuterParentheses(s1) << endl;

    // Test Case 2: "(()())(())(()(()))" -> Expected: "()()()()(())"
    string s2 = "(()())(())(()(()))";
    cout << "Test 2 Output: \"" << solver.removeOuterParentheses(s2) << endl;

    // Test Case 3: "()()" -> Expected: ""
    string s3 = "()()";
    cout << "Test 3 Output: \"" << solver.removeOuterParentheses(s3) << endl;

    return 0;
}