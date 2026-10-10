#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int neededRight = 0;

        for (char c : s) {
            if (c == '(') {
                // If neededRight is odd, an earlier '(' only got one ')' before this new '('
                if (neededRight % 2 != 0) {
                    insertions++;   // Insert a missing ')'
                    neededRight--;  // Pair completed
                }
                neededRight += 2;   // This new '(' requires two ')'
            } else { // c == ')'
                neededRight--;

                // More ')' than matched '(' available
                if (neededRight < 0) {
                    insertions++;   // Insert an opening '('
                    neededRight += 2; // '(' needs two ')', one is already consumed (net: +1)
                }
            }
        }

        // Remaining neededRight brackets must be inserted at the end
        return insertions + neededRight;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "(()))" -> Expected: 1
    string s1 = "(()))";
    cout << "Test 1 Output: " << solver.minInsertions(s1) << endl;

    // Test Case 2: "())" -> Expected: 0
    string s2 = "())";
    cout << "Test 2 Output: " << solver.minInsertions(s2) << endl;

    // Test Case 3: "))())(" -> Expected: 3
    string s3 = "))())(";
    cout << "Test 3 Output: " << solver.minInsertions(s3) << endl;

    // Test Case 4: "((((((" -> Expected: 12
    string s4 = "((((((";
    cout << "Test 4 Output: " << solver.minInsertions(s4) << endl ;

    // Test Case 5: ")))))))" -> Expected: 5
    string s5 = ")))))))";
    cout << "Test 5 Output: " << solver.minInsertions(s5) << endl;

    return 0;
}