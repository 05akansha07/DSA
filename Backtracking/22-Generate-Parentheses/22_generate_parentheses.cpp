#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void backtrack(int openCount, int closeCount, int n, string& current, vector<string>& result) {
        // Base case: length reaches 2 * n
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Option 1: Add '(' if available
        if (openCount < n) {
            current.push_back('(');
            backtrack(openCount + 1, closeCount, n, current, result);
            current.pop_back(); // Backtrack
        }

        // Option 2: Add ')' only if it matches an open bracket
        if (closeCount < openCount) {
            current.push_back(')');
            backtrack(openCount, closeCount + 1, n, current, result);
            current.pop_back(); // Backtrack
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtrack(0, 0, n, current, result);
        return result;
    }
};

int main() {
    Solution solver;

    // Test Case 1: n = 3
    int n1 = 3;
    vector<string> res1 = solver.generateParenthesis(n1);
    cout << "Test 1 (n = 3):\n";
    for (const string& s : res1) {
        cout << "  " << s << "\n";
    }

    // Test Case 2: n = 1
    int n2 = 1;
    vector<string> res2 = solver.generateParenthesis(n2);
    cout << "\nTest 2 (n = 1):\n";
    for (const string& s : res2) {
        cout << "  " << s << "\n";
    }

    return 0;
}