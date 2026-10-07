# 921. Minimum Add to Make Parentheses Valid

**Difficulty:** Medium  
**Topics:** String, Stack, Greedy  
**Language:** C++

---

## Problem Statement

A parentheses string is valid if and only if:
1. It is the empty string,
2. It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
3. It can be written as `(A)`, where `A` is a valid string.

You are given a parentheses string `s`. In one move, you can insert a parenthesis at any position of the string.

For example, if `s = "()))"`, you can insert an opening parenthesis to be `"(()))"` or a closing parenthesis to be `"())))"`.

Return the **minimum number of moves** required to make `s` valid.

---

## Examples

### Example 1:
- **Input:** `s = "())"`
- **Output:** `1`

### Example 2:
- **Input:** `s = "((("`
- **Output:** `3`

---

## Constraints

- $1 \le \text{s.length} \le 1000$
- `s[i]` is either `'('` or `')'`.

---

## Intuition & Approach

### Greedy Counter Simulation (Space-Optimal $\mathcal{O}(1)$)

Instead of using an actual stack data structure to store unclosed `'('` brackets, we can track the balance using two integer counters:

1. **Counters:**
   - `openCount`: The number of open `'('` brackets encountered that have not yet found a matching `')'`.
   - `insertionsNeeded`: The number of unmatched `')'` brackets that appeared when no `'('` was available. Each of these strictly requires inserting an opening `'('` before it.

2. **Traversal:**
   - When encountering `'('`: increment `openCount++`.
   - When encountering `')'`:
     - If `openCount > 0`: we can match this `')'` with an earlier unmatched `'('`. Decrement `openCount--`.
     - If `openCount == 0`: there is no opening bracket to balance this closing bracket. We must insert a `'('`, so increment `insertionsNeeded++`.

3. **Total Insertions:**
   - Any remaining `openCount` represents open brackets that never received a matching `')'`. Each requires one `')'` insertion.
   - Total moves required is:
     $$\text{total moves} = \text{insertionsNeeded} + \text{openCount}$$

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass through the string `s` of length $N$.
- **Space Complexity:** $\mathcal{O}(1)$  
  Uses only two primitive integer variables (`openCount` and `insertionsNeeded`).

---

## C++ Implementation

```cpp
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0;
        int insertionsNeeded = 0;

        for (char c : s) {
            if (c == '(') {
                openCount++;
            } else { // c == ')'
                if (openCount > 0) {
                    openCount--; // Matched pair found
                } else {
                    insertionsNeeded++; // Need to insert an opening '('
                }
            }
        }

        // Remaining openCount requires that many ')' to be appended
        return insertionsNeeded + openCount;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "())" -> Expected: 1
    string s1 = "())";
    cout << "Test 1 Output: " << solver.minAddToMakeValid(s1) << endl;

    // Test Case 2: "(((" -> Expected: 3
    string s2 = "(((";
    cout << "Test 2 Output: " << solver.minAddToMakeValid(s2) << endl;

    // Test Case 3: "()" -> Expected: 0
    string s3 = "()";
    cout << "Test 3 Output: " << solver.minAddToMakeValid(s3) << endl;

    // Test Case 4: "()))((" -> Expected: 4
    string s4 = "()))((";
    cout << "Test 4 Output: " << solver.minAddToMakeValid(s4) << endl;

    // Test Case 5: "v" -> Expected: 0 (non-parenthesis / edge case)
    string s5 = "v";
    cout << "Test 5 Output: " << solver.minAddToMakeValid(s5) << endl;

    return 0;
}
```
