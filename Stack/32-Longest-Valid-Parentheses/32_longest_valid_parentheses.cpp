#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Approach 1: Index-Tracking Stack (O(N) Time, O(N) Space)
    /*int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Base boundary
        int maxLen = 0;

        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // Update the boundary marker to the current index
                    st.push(i);
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }*/

    // Approach 2: Two-Pass Greedy Counter (O(N) Time, O(1) Auxiliary Space)
    int longestValidParentheses(string s)
    {
        int n = s.length();
        int open = 0, close = 0;
        int maxLen = 0;

        // Pass 1: Left-to-right
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }

            if (open == close)
            {
                maxLen = max(maxLen, 2 * close);
            }
            else if (close > open)
            {
                open = close = 0;
            }
        }

        // Pass 2: Right-to-left
        open = close = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }

            if (open == close)
            {
                maxLen = max(maxLen, 2 * open);
            }
            else if (open > close)
            {
                open = close = 0;
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution solver;

    // Test Case 1: "(()" -> Expected: 2
    string s1 = "(()";
    cout << "Test 1 Output: " << solver.longestValidParentheses(s1)<< "\n";

    // Test Case 2: ")()())" -> Expected: 4
    string s2 = ")()())";
    cout << "Test 2 Output: " << solver.longestValidParentheses(s2)<< "\n";

    // Test Case 3: "" -> Expected: 0
    string s3 = "";
    cout << "Test 3 Output: " << solver.longestValidParentheses(s3)<< "\n";

    // Test Case 4: "()(()" -> Expected: 2
    string s4 = "()(()";
    cout << "Test 4 Output: " << solver.longestValidParentheses(s4)<< "\n";

    return 0;
}