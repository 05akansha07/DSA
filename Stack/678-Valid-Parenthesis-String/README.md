# 678. Valid Parenthesis String

**Difficulty:** Medium  
**Topics:** String, Dynamic Programming, Stack, Greedy  
**Language:** C++

---

## Problem Statement

Given a string `s` containing only three types of characters: `'('`, `')'` and `'*'`, return `true` if `s` is valid.

The following rules define a valid string:
1. Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
2. Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
3. Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
4. `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string `""`.

---

## Examples

### Example 1:
- **Input:** `s = "()"`
- **Output:** `true`

### Example 2:
- **Input:** `s = "(*)"`
- **Output:** `true`

### Example 3:
- **Input:** `s = "(*))"`
- **Output:** `true`

### Example 4:
- **Input:** `s = "("`
- **Output:** `false`

---

## Constraints

- $1 \le \text{s.length} \le 100$
- `s[i]` is `'('`, `')'`, or `'*'`.

---

## Intuition & Approach

### Range-Based Greedy Tracking ($[\text{low}, \text{high}]$)

Since `'*'` can act as `'('`, `')'`, or an empty string, the count of open parentheses at any given step is not a fixed integer, but rather a contiguous range $[\text{low}, \text{high}]$:
- `low`: The **minimum** number of open parentheses possible (treating `'*'` as `')'` or empty).
- `high`: The **maximum** number of open parentheses possible (treating `'*'` as `'('`).

1. **State Transitions per Character:**
   - **`'('`:** Both minimum and maximum open counts increase:  
     `low++`, `high++`
   - **`')'`:** Both minimum and maximum open counts decrease:  
     `low--`, `high--`
   - **`'*'`:**
     - If treated as `')'`: open count decreases (`low--`).
     - If treated as `'('`: open count increases (`high++`).
     - If treated as `""`: open count stays the same (covered inside the interval $[\text{low}, \text{high}]$).

2. **Invariants & Pruning:**
   - **Excess Closing Brackets:** If `high < 0`, even under the most optimistic scenario (treating every `'*'` as `'('`), there are more `')'` than `'('`. The string can never be balanced $\to$ return `false`.
   - **Floor at Zero:** `low` cannot drop below `0` because an open bracket count cannot be negative. If `low < 0`, it simply means some `'*'` characters were assumed to be `')'` unnecessarily, so we clamp `low = max(low, 0)`.

3. **Final Check:**  
   After iterating through the string, the string is valid if and only if $0 \in [\text{low}, \text{high}]$, which simplifies to checking `low == 0`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass through the string `s` of length $N$.
- **Space Complexity:** $\mathcal{O}(1)$  
  Uses only two scalar integer bounds (`low` and `high`).

---

## C++ Implementation

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { // c == '*'
                low--;
                high++;
            }

            // More ')' than possible '(' and '*' combined
            if (high < 0) return false;

            // low cannot be negative; '*' as ')' cannot carry a negative balance
            low = max(low, 0);
        }

        return low == 0;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "()" -> Expected: true
    cout << boolalpha;
    cout << "Test 1: " << solver.checkValidString("()") << endl;

    // Test Case 2: "(*)" -> Expected: true
    cout << "Test 2: " << solver.checkValidString("(*)") << endl;

    // Test Case 3: "(*))" -> Expected: true
    cout << "Test 3: " << solver.checkValidString("(*))") << endl;

    // Test Case 4: "(" -> Expected: false
    cout << "Test 4: " << solver.checkValidString("(") << endl;

    // Test Case 5: "*(())*" -> Expected: true
    cout << "Test 5: " << solver.checkValidString("*(())*") << endl;

    return 0;
}
```
