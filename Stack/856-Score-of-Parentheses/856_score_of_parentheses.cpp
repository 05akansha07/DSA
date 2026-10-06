#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Approach 1: O(1) Auxiliary Space (Optimal)
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;

        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                // Check if this ')' forms an immediate "()" pair
                if (s[i - 1] == '(') {
                    score += (1 << depth);
                }
            }
        }

        return score;
    }

};

int main() {
    Solution solver;

    // Test Case 1: "()" -> Expected: 1
    string s1 = "()";
    cout << "Test 1: " << solver.scoreOfParentheses(s1) << " \n";

    // Test Case 2: "(())" -> Expected: 2
    string s2 = "(())";
    cout << "Test 2: " << solver.scoreOfParentheses(s2) << " \n";

    // Test Case 3: "()()" -> Expected: 2
    string s3 = "()()";
    cout << "Test 3: " << solver.scoreOfParentheses(s3) << " \n";

    // Test Case 4: "(()(()))" -> Expected: 6
    string s4 = "(()(()))";
    cout << "Test 4: " << solver.scoreOfParentheses(s4) << " \n";

    return 0;
}