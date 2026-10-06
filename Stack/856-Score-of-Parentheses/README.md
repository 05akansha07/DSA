# 856. Score of Parentheses

**Difficulty:** Medium  
**Topics:** String, Stack, Bit Manipulation  
**Language:** C++

---

## Problem Statement

Given a balanced parentheses string `s`, return the *score* of the string.

The score of a balanced parentheses string is based on the following rules:
- `"()"` has score `1`.
- `AB` has score `A + B`, where `A` and `B` are balanced parentheses strings.
- `(A)` has score `2 * A`, where `A` is a balanced parentheses string.

---

## Examples

### Example 1:
- **Input:** `s = "()"`
- **Output:** `1`

### Example 2:
- **Input:** `s = "(())"`
- **Output:** `2`

### Example 3:
- **Input:** `s = "()()"`
- **Output:** `2`

### Example 4:
- **Input:** `s = "(()(()))"`
- **Output:** `6`

---

## Constraints

- $2 \le \text{s.length} \le 50$
- `s` consists of only `'('` and `')'`.
- `s` is a balanced parentheses string.

---

## Intuition & Approach

### Depth-Based Bit Shift Counting ($\mathcal{O}(1)$ Space)

Every score ultimately originates from the primitive pair `"()"`, which has a base value of $1$. Whenever an expression is enclosed in another set of parentheses `(A)`, its entire value is multiplied by $2$.

1. **Distributive Law of Multiplication:**  
   Notice that the score of an expression is simply the sum of the contributions of every core `"()"` pair:
   $$\text{Score} = \sum_{\text{core } ()} 2^{\text{depth}}$$
   Where $\text{depth}$ is the number of outer enclosing parentheses surrounding that specific `"()"` pair.

2. **Identifying Core Pairs:**  
   A closing parenthesis `s[i] == ')'` forms a core `"()"` pair if and only if its immediate predecessor is an opening bracket:
   $$s[i - 1] == 	ext{'('}$$

3. **Algorithm:**  
   - Maintain `depth` as the current nesting level.
   - Iterate through `s`:
     - If `s[i] == '('`: increment `depth++`.
     - If `s[i] == ')'`: decrement `depth--`.
     - If `s[i - 1] == '('`: we just closed a core `"()"` pair at the current remaining depth level! Add $2^{\text{depth}}$ (computed cleanly via bit-shift `1 << depth`) to `score`.
   - Other `')'` brackets simply close outer scopes and do not directly contribute new points, as their multiplication effect has already been accounted for in the depth exponent.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass through the string `s` of length $N$.
- **Space Complexity:** $\mathcal{O}(1)$  
  Uses only two primitive integer variables (`score` and `depth`).

---

## C++ Implementation

```cpp
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Approach: O(1) Auxiliary Space (Optimal)
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
```
