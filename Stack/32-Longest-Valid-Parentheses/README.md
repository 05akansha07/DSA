# 32. Longest Valid Parentheses

**Difficulty:** Hard  
**Topics:** String, Dynamic Programming, Stack  
**Language:** C++

---

## Problem Statement

Given a string containing just the characters `'('` and `')'`, return the length of the longest valid (well-formed) parentheses substring.

---

## Examples

### Example 1:
- **Input:** `s = "(()"`
- **Output:** `2`
- **Explanation:** The longest valid parentheses substring is `"()"`.

### Example 2:
- **Input:** `s = ")()())"`
- **Output:** `4`
- **Explanation:** The longest valid parentheses substring is `"()()"`.

### Example 3:
- **Input:** `s = ""`
- **Output:** `0`

---

## Constraints

- $0 \le \text{s.length} \le 3 \times 10^4$
- `s[i]` is `'('` or `')'`.

---

## Intuition & Approach

### Two-Pass Two-Pointer Counter (Constant Space $\mathcal{O}(1)$)

While stack-based or dynamic programming approaches achieve $\mathcal{O}(N)$ time with $\mathcal{O}(N)$ auxiliary space, we can eliminate the stack entirely by scanning the string twice:

1. **Left-to-Right Pass:**  
   - Maintain counters `open` and `close`.
   - Traverse from index $0$ to $N - 1$:
     - If `s[i] == '('`: increment `open`.
     - If `s[i] == ')'`: increment `close`.
     - **Equilibrium:** If `open == close`, a valid balanced prefix substring is formed. Update `maxLen = max(maxLen, 2 * close)`.
     - **Violation:** If `close > open`, there are more closing brackets than open ones, invalidating the current segment. Reset `open = close = 0`.
   - *Limitation of Pass 1:* It misses valid substrings where `open > close` (e.g., in `"((()"`, `open` never equals `close`).

2. **Right-to-Left Pass:**  
   - Reset `open = close = 0` and traverse backwards from $N - 1$ down to $0$:
     - If `s[i] == '('`: increment `open`.
     - If `s[i] == ')'`: increment `close`.
     - **Equilibrium:** If `open == close`, update `maxLen = max(maxLen, 2 * open)`.
     - **Violation:** If `open > close`, reset `open = close = 0`.

Combining both directions catches all longest balanced substrings while maintaining strict $\mathcal{O}(1)$ space complexity.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  Two linear passes across the string of length $N$.
- **Space Complexity:** $\mathcal{O}(1)$  
  Uses only scalar integer counters (`open`, `close`, `maxLen`), requiring constant auxiliary space.

---

## C++ Implementation

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
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
    cout << "Test 1 Output: " << solver.longestValidParentheses(s1) << "\n";

    // Test Case 2: ")()())" -> Expected: 4
    string s2 = ")()())";
    cout << "Test 2 Output: " << solver.longestValidParentheses(s2) << "\n";

    // Test Case 3: "" -> Expected: 0
    string s3 = "";
    cout << "Test 3 Output: " << solver.longestValidParentheses(s3) << "\n";

    // Test Case 4: "()(()" -> Expected: 2
    string s4 = "()(()";
    cout << "Test 4 Output: " << solver.longestValidParentheses(s4) << "\n";

    return 0;
}
```
