#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Optimal O(N) Wormhole Teleportation Solution
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pairIdx(n, 0);
        stack<int> st;

        // Step 1: Precompute matching pairs of parentheses
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int openIdx = st.top();
                st.pop();
                pairIdx[openIdx] = i;
                pairIdx[i] = openIdx;
            }
        }

        // Step 2: Traverse with direction flipping
        string result = "";
        int curr = 0;
        int step = 1; // 1 = forward, -1 = backward

        while (curr < n && curr >= 0) {
            if (s[curr] == '(' || s[curr] == ')') {
                curr = pairIdx[curr]; // Teleport across matching bracket
                step = -step;         // Reverse movement direction
            } else {
                result += s[curr];
            }
            curr += step;
        }

        return result;
    }

};

int main() {
    Solution solver;

    // Test Case 1: "(abcd)" -> Expected: "dcba"
    string s1 = "(abcd)";
    cout << "Test 1 Output: " << solver.reverseParentheses(s1) << endl;

    // Test Case 2: "(u(love)i)" -> Expected: "iloveu"
    string s2 = "(u(love)i)";
    cout << "Test 2 Output: " << solver.reverseParentheses(s2) << endl;

    // Test Case 3: "(ed(et(oc))el)" -> Expected: "leetcode"
    string s3 = "(ed(et(oc))el)";
    cout << "Test 3 Output: " << solver.reverseParentheses(s3) << endl;

    return 0;
}