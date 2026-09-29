# 1614. Maximum Nesting Depth of the Parentheses

**Difficulty:** Easy  
**Topics:** String, Stack  
**Language:** C++

---

## Problem Statement

Given a valid parentheses string `s`, return the *nesting depth* of `s`. The nesting depth is the maximum number of nested parentheses.

---

## Examples

### Example 1:
- **Input:** `s = "(1+(2*3)+((8)/4))+1"`
- **Output:** `3`
- **Explanation:** Digit `8` is inside of 3 nested parentheses in the string.

### Example 2:
- **Input:** `s = "(1)+((2))+(((3)))"`
- **Output:** `3`
- **Explanation:** Digit `3` is inside of 3 nested parentheses in the string.

### Example 3:
- **Input:** `s = "()(())((()()))"`
- **Output:** `3`

---

## Constraints

- $1 \le \text{s.length} \le 100$
- `s` consists of digits `0-9` and characters `'+'`, `'-'`, `'*'`, `'/'`, `'('`, and `')'`.
- It is guaranteed that parentheses expression `s` is a **VPS** (Valid Parentheses String).

---

## Intuition & Approach

### Linear Counter Tracking

Because the input string is guaranteed to be a Valid Parentheses String (VPS), we do not need to validate bracket correctness or maintain an actual `std::stack` data structure:

1. **State Tracking:**  
   - Maintain `currentDepth` to represent the number of open, unclosed parentheses encountered so far.
   - Maintain `maxDepthVal` to store the highest `currentDepth` reached during the traversal.

2. **Single Pass:**  
   Iterate through each character `ch` in `s`:
   - If `ch == '('`: An additional layer of nesting opens. Increment `currentDepth` and update `maxDepthVal = max(maxDepthVal, currentDepth)`.
   - If `ch == ')'`: A nesting level closes. Decrement `currentDepth`.
   - Any other character (digits, arithmetic operators): Ignore, as they do not affect nesting depth.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single linear scan over string `s` of length $N$.
- **Space Complexity:** $\mathcal{O}(1)$  
  Only uses two integer scalar counters (`currentDepth` and `maxDepthVal`).

---

## C++ Implementation

```cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int currentDepth = 0;
        int maxDepthVal = 0;

        for (char ch : s) {
            if (ch == '(') {
                currentDepth++;
                maxDepthVal = max(maxDepthVal, currentDepth);
            } else if (ch == ')') {
                currentDepth--;
            }
        }

        return maxDepthVal;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "(1+(2*3)+((8)/4))+1" -> Expected: 3
    string s1 = "(1+(2*3)+((8)/4))+1";
    cout << "Test 1 Output: " << solver.maxDepth(s1) << endl;

    // Test Case 2: "(1)+((2))+(((3)))" -> Expected: 3
    string s2 = "(1)+((2))+(((3)))";
    cout << "Test 2 Output: " << solver.maxDepth(s2) << endl;

    // Test Case 3: "()(())((()()))" -> Expected: 3
    string s3 = "()(())((()()))";
    cout << "Test 3 Output: " << solver.maxDepth(s3) << endl;

    // Test Case 4: No parentheses "1+2*3" -> Expected: 0
    string s4 = "1+2*3";
    cout << "Test 4 Output: " << solver.maxDepth(s4) << endl;

    return 0;
}
```
