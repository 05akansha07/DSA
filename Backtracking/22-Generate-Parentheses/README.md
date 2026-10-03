# 22. Generate Parentheses

**Difficulty:** Medium  
**Topics:** String, Dynamic Programming, Backtracking  
**Language:** C++

---

## Problem Statement

Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

---

## Examples

### Example 1:
- **Input:** `n = 3`
- **Output:** `["((()))", "(()())", "(())()", "()(())", "()()()"]`

### Example 2:
- **Input:** `n = 1`
- **Output:** `["()"]`

---

## Constraints

- $1 \le n \le 8$

---

## Intuition & Approach

### Backtracking with Valid Prefix Invariants

A brute-force solution generates all $2^{2n}$ possible strings of length $2n$ and validates each one, taking $\mathcal{O}(2^{2n} \cdot n)$ time. We can prune invalid branches early by enforcing the invariants of a **well-formed parentheses string** during construction:

1. **State Constraints:**
   - **Adding `'('`:** We can place an open parenthesis whenever `openCount < n`.
   - **Adding `')'`:** We can place a close parenthesis only when `closeCount < openCount`. This ensures no prefix ever contains more closing brackets than opening brackets, guaranteeing validity.

2. **Base Case:**
   - When `current.length() == 2 * n` (or equivalently `openCount == n && closeCount == n`), a valid combination is formed $\to$ add `current` to `result`.

3. **Catalan Number Growth:**
   The total number of valid combinations for $n$ pairs is given by the $n^{\text{th}}$ Catalan number:
   $$C_n = \frac{1}{n + 1} \binom{2n}{n}$$
   For $n = 8$, $C_8 = 1430$, so the search tree is extremely compact and generates only valid paths.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}\left(\frac{4^n}{\sqrt{n}}\right)$  
  Bounded by the $n^{\text{th}}$ Catalan number $C_n = \frac{1}{n+1}\binom{2n}{n} \approx \frac{4^n}{n\sqrt{\pi n}}$, where copying each valid string of length $2n$ into the result vector takes $\mathcal{O}(n)$ time.
- **Space Complexity:** $\mathcal{O}(n)$  
  The recursion call stack and `current` string use at most $2n = \mathcal{O}(n)$ auxiliary memory (excluding the space needed to store the output).

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void backtrack(int openCount, int closeCount, int n, string& current, vector<string>& result) {
        // Base case: length reaches 2 * n
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Option 1: Add '(' if available
        if (openCount < n) {
            current.push_back('(');
            backtrack(openCount + 1, closeCount, n, current, result);
            current.pop_back(); // Backtrack
        }

        // Option 2: Add ')' only if it matches an open bracket
        if (closeCount < openCount) {
            current.push_back(')');
            backtrack(openCount, closeCount + 1, n, current, result);
            current.pop_back(); // Backtrack
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtrack(0, 0, n, current, result);
        return result;
    }
};

int main() {
    Solution solver;

    // Test Case 1: n = 3
    int n1 = 3;
    vector<string> res1 = solver.generateParenthesis(n1);
    cout << "Test 1 (n = 3):\n";
    for (const string& s : res1) {
        cout << "  " << s << "\n";
    }

    // Test Case 2: n = 1
    int n2 = 1;
    vector<string> res2 = solver.generateParenthesis(n2);
    cout << "\nTest 2 (n = 1):\n";
    for (const string& s : res2) {
        cout << "  " << s << "\n";
    }

    return 0;
}
```
