# 1541. Minimum Insertions to Balance a Parentheses String

**Difficulty:** Medium  
**Topics:** String, Stack, Greedy  
**Language:** C++

---

## Problem Statement

Given a parentheses string `s` containing only the characters `'('` and `')'`. A parentheses string is balanced if:
- Any left parenthesis `'('` must have a corresponding two consecutive right parenthesis `'))'`.
- Left parenthesis `'('` must go before the corresponding two consecutive right parenthesis `'))'`.

In other words, we treat `'('` as an opening parenthesis and `'))'` as a closing parenthesis.

For example, `"())"`, `"())(())))"` and `"(())())))"` are balanced, `")()"`, `"()))"` and `"(()))"` are not balanced.

You can insert the characters `'('` and `')'` at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make `s` balanced.

---

## Examples

### Example 1:
- **Input:** `s = "(()))"`
- **Output:** `1`
- **Explanation:** The second `'('` has two matching `'))'`, but the first `'('` has only `')'` matching. We need to add one more `')'` at the end of the string to be `"(())))"`, which is balanced.

### Example 2:
- **Input:** `s = "())"`
- **Output:** `0`
- **Explanation:** The string is already balanced.

### Example 3:
- **Input:** `s = "))())("`
- **Output:** `3`
- **Explanation:** Add `'('` to match the first `'))'`, add `'))'` to match the last `'('`.

---

## Constraints

- $1 \le \text{s.length} \le 10^5$
- `s` consists of `'('` and `')'` only.

---

## Intuition & Approach

### Greedy Demand Tracking (`neededRight`)

In this problem, every single `'('` demands **exactly two** consecutive `')'`. We can track the number of required closing parentheses using an integer counter `neededRight`:

1. **Encountering `'('`:**
   - If `neededRight` is odd, an earlier `'('` was matched with only a single `')'` before this new `'('` arrived. Because closing pairs must be consecutive, we must insert a missing `')'` immediately:
     - `insertions++`
     - `neededRight--`
   - Now, the current `'('` adds a requirement of 2 closing brackets: `neededRight += 2`.

2. **Encountering `')'`:**
   - Consume one demand: `neededRight--`.
   - If `neededRight < 0`, we have an excess `')'` with no available opening bracket. We must insert an opening `'('` to balance it:
     - Inserting `'('` demands two `')'`, but one is already consumed by the current `')'`.
     - `insertions++`
     - `neededRight += 2` (net change: `neededRight` becomes `1`).

3. **Final Cleanup:**
   - After traversing `s`, any remaining `neededRight` must be fulfilled by appending that many `')'` characters at the end:
     $$\text{total insertions} = \text{insertions} + \text{neededRight}$$

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass through the string `s` of length $N$.
- **Space Complexity:** $\mathcal{O}(1)$  
  Uses only two scalar counters (`insertions` and `neededRight`).

---

## C++ Implementation

```cpp
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int neededRight = 0;

        for (char c : s) {
            if (c == '(') {
                // If neededRight is odd, an earlier '(' only got one ')' before this new '('
                if (neededRight % 2 != 0) {
                    insertions++;   // Insert a missing ')'
                    neededRight--;  // Pair completed
                }
                neededRight += 2;   // This new '(' requires two ')'
            } else { // c == ')'
                neededRight--;

                // More ')' than matched '(' available
                if (neededRight < 0) {
                    insertions++;     // Insert an opening '('
                    neededRight += 2; // '(' needs two ')', one is already consumed (net: +1)
                }
            }
        }

        // Remaining neededRight brackets must be inserted at the end
        return insertions + neededRight;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "(()))" -> Expected: 1
    string s1 = "(()))";
    cout << "Test 1 Output: " << solver.minInsertions(s1) << endl;

    // Test Case 2: "())" -> Expected: 0
    string s2 = "())";
    cout << "Test 2 Output: " << solver.minInsertions(s2) << endl;

    // Test Case 3: "))())(" -> Expected: 3
    string s3 = "))())(";
    cout << "Test 3 Output: " << solver.minInsertions(s3) << endl;

    // Test Case 4: "((((((" -> Expected: 12
    string s4 = "((((((";
    cout << "Test 4 Output: " << solver.minInsertions(s4) << endl;

    // Test Case 5: ")))))))" -> Expected: 5
    string s5 = ")))))))";
    cout << "Test 5 Output: " << solver.minInsertions(s5) << endl;

    return 0;
}
```
