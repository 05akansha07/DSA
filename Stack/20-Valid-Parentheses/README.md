# 20. Valid Parentheses

**Difficulty:** Easy  
**Topics:** String, Stack  
**Language:** C++

---

## Problem Statement

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

---

## Examples

### Example 1:
- **Input:** `s = "()"`
- **Output:** `true`

### Example 2:
- **Input:** `s = "()[]{}"`
- **Output:** `true`

### Example 3:
- **Input:** `s = "(]"`
- **Output:** `false`

### Example 4:
- **Input:** `s = "([])"`
- **Output:** `true`

### Example 5:
- **Input:** `s = "([)]"`
- **Output:** `false`

---

## Constraints

- $1 \le \text{s.length} \le 10^4$
- `s` consists of parentheses only `'()[]{}'`.

---

## Intuition & Approach

### Last-In, First-Out (LIFO) Stack

Brackets must be matched in reverse order of appearance—the most recently opened bracket must be the first one to be closed. A **Stack** naturally enforces this behavior:

1. **Length Parity Check:**  
   If `s.length() % 2 != 0`, the string cannot possibly be balanced, so return `false` immediately.

2. **Traversal Logic:**  
   Iterate through each character of `s`:
   - **Opening Brackets (`'('`, `'{'`, `'['`):** Push onto the stack.
   - **Closing Brackets (`')'`, `'}'`, `']'`):**
     - If the stack is empty, there is no matching opening bracket $\to$ return `false`.
     - Check if `st.top()` matches the corresponding opening type:
       - `')'` matches `'('`
       - `'}'` matches `'{'`
       - `']'` matches `'['`
     - If it matches, pop from the stack.
     - Otherwise, the brackets are mismatched or out of order $\to$ return `false`.

3. **Final Validation:**  
   After processing all characters, the stack must be completely empty (`st.empty()`). Any remaining element represents an unclosed opening bracket.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass through the string `s` of length $N$, with $\mathcal{O}(1)$ push and pop operations per character.
- **Space Complexity:** $\mathcal{O}(N)$  
  In the worst-case scenario (e.g., all opening brackets `((((...`), the stack stores up to $N$ characters.

---

## C++ Implementation

```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.length() % 2 != 0) return false;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;
                if (s[i] == ')' && st.top() == '(')
                    st.pop();
                else if (s[i] == '}' && st.top() == '{')
                    st.pop();
                else if (s[i] == ']' && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solver;

    // Test Case 1: "()" -> Expected: true
    cout << boolalpha;
    cout << "Test 1: " << solver.isValid("()") << endl;

    // Test Case 2: "()[]{}" -> Expected: true
    cout << "Test 2: " << solver.isValid("()[]{}") << endl;

    // Test Case 3: "(]" -> Expected: false
    cout << "Test 3: " << solver.isValid("(]") << endl;

    // Test Case 4: "([])" -> Expected: true
    cout << "Test 4: " << solver.isValid("([])") << endl;

    // Test Case 5: "([)]" -> Expected: false
    cout << "Test 5: " << solver.isValid("([)]") << endl;

    return 0;
}
```
