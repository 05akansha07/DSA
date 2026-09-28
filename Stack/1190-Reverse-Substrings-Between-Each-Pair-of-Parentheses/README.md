# 1190. Reverse Substrings Between Each Pair of Parentheses

**Difficulty:** Medium  
**Topics:** String, Stack  
**Language:** C++

---

## Problem Statement

You are given a string `s` that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

---

## Examples

### Example 1:
- **Input:** `s = "(abcd)"`
- **Output:** `"dcba"`

### Example 2:
- **Input:** `s = "(u(love)i)"`
- **Output:** `"iloveu"`
- **Explanation:** The substring `"love"` is reversed first, then the whole string is reversed.

### Example 3:
- **Input:** `s = "(ed(et(oc))el)"`
- **Output:** `"leetcode"`
- **Explanation:** First, we reverse the substring `"oc"`, then `"etco"`, and finally, the whole string.

---

## Constraints

- $1 \le \text{s.length} \le 2000$
- `s` only contains lowercase English characters and parentheses.
- It is guaranteed that all parentheses are balanced.

---

## Intuition & Approach

### Optimal $\mathcal{O}(N)$ Wormhole Teleportation

A straightforward stack simulation physically reverses characters whenever a closing parenthesis `')'` is met, yielding $\mathcal{O}(N^2)$ time in the worst case (e.g., deeply nested brackets).

Instead, we can observe that reversing a substring inside parentheses is equivalent to changing the traversal direction when entering and leaving the boundaries:

1. **Precompute Parentheses Pairs (Wormholes):**  
   Using a stack, match every `'('` with its corresponding `')'` and record their positions in an array `pairIdx`:
   - `pairIdx[openIdx] = closeIdx`
   - `pairIdx[closeIdx] = openIdx`

2. **Directional Traversal:**  
   - Start at `curr = 0` with direction `step = 1` (forward).
   - If `s[curr]` is a bracket (`'('` or `')'`):
     - **Teleport:** Jump across the matching pair: `curr = pairIdx[curr]`.
     - **Invert Direction:** `step = -step`.
   - If `s[curr]` is an alphabetic character:
     - Append `s[curr]` to `result`.
   - Advance: `curr += step`.

Every character is processed at most twice (once to match brackets and once during traversal), enabling optimal linear runtime.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  - Pass 1: Bracket matching using a stack takes $\mathcal{O}(N)$ time.
  - Pass 2: Traversing the characters via teleportation takes $\mathcal{O}(N)$ time.
  - Overall time is strictly linear $\mathcal{O}(N)$.
- **Space Complexity:** $\mathcal{O}(N)$  
  Requires $\mathcal{O}(N)$ space for the stack and the `pairIdx` jump table.

---

## C++ Implementation

```cpp
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
```
