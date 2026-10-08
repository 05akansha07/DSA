# 1021. Remove Outermost Parentheses

**Difficulty:** Easy  
**Topics:** String, Stack  
**Language:** C++

---

## Problem Statement

A valid parentheses string is either empty `""`, `"(" + A + ")"`, or `A + B`, where `A` and `B` are valid parentheses strings, and `+` represents string concatenation.

For example, `""`, `"()"`, `"(())()"`, and `"(()(()))"` are all valid parentheses strings.

A valid parentheses string `s` is primitive if it is nonempty, and there does not exist a way to split it into `s = A + B`, with `A` and `B` nonempty valid parentheses strings.

Given a valid parentheses string `s`, consider its primitive decomposition: `s = P_1 + P_2 + ... + P_k`, where `P_i` are primitive valid parentheses strings.

Return `s` after removing the outermost parentheses of every primitive string in the primitive decomposition of `s`.

---

## Examples

### Example 1:
- **Input:** `s = "(()())(())"`
- **Output:** `"()()()"`
- **Explanation:** 
  The input string is `"(()())(())"`, with primitive decomposition `"(()())" + "(())"`.
  After removing the outer parentheses of each part, this becomes `"()()" + "()" = "()()()"`.

### Example 2:
- **Input:** `s = "(()())(())(()(()))"`
- **Output:** `"()()()()(())"`
- **Explanation:** 
  The input string is `"(()())(())(()(()))"`, with primitive decomposition `"(()())" + "(())" + "(()(()))"`.
  After removing outer parentheses of each part, this becomes `"()()" + "()" + "()(())" = "()()()()(())"`.

### Example 3:
- **Input:** `s = "()()"`
- **Output:** `""`
- **Explanation:** 
  The input string is `"()()"`, with primitive decomposition `"()" + "()"`.
  After removing outer parentheses of each part, this becomes `"" + "" = ""`.

---

## Constraints

- $1 \le \text{s.length} \le 10^5$
- `s[i]` is either `'('` or `')'`.
- `s` is a valid parentheses string.

---

## Intuition & Approach

### Balance Tracking without Stack Overhead

Every primitive valid parentheses string starts with an opening parenthesis `'('` at balance level `0` and finishes with a closing parenthesis `')'` that brings the balance back down to `0`. 

- An opening bracket `'('` is outermost if and only if it is encountered when `depth == 0`.
- A closing bracket `')'` is outermost if and only if it brings `depth` down to `0`.

Hence, we only keep characters belonging to internal nested levels:
1. When encountering `'('`:
   - If `depth > 0`, it is an inner bracket $\to$ append to `ans`.
   - Increment `depth++`.
2. When encountering `')'`:
   - Decrement `depth--`.
   - If `depth > 0`, it was an inner bracket $\to$ append to `ans`.

This filters out all outermost boundaries in a single pass without needing explicit stack allocations or string splitting.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass through the string `s` of length $N$.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Excluding the returned string `ans`, only a single integer scalar `depth` is maintained.

---

## C++ Implementation

```cpp
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
    cout << "Test 1 Output: \"" << solver.removeOuterParentheses(s1) << "\"\n";

    // Test Case 2: "(()())(())(()(()))" -> Expected: "()()()()(())"
    string s2 = "(()())(())(()(()))";
    cout << "Test 2 Output: \"" << solver.removeOuterParentheses(s2) << "\"\n";

    // Test Case 3: "()()" -> Expected: ""
    string s3 = "()()";
    cout << "Test 3 Output: \"" << solver.removeOuterParentheses(s3) << "\"\n";

    return 0;
}
```
