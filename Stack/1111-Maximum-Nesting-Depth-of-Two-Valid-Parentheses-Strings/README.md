# 1111. Maximum Nesting Depth of Two Valid Parentheses Strings

**Difficulty:** Medium  
**Topics:** String, Stack, Greedy  
**Language:** C++

---

## Problem Statement

A string is a **valid parentheses string** (denoted **VPS**) if and only if it consists of `"("` and `")"` characters only, and:
- It is the empty string, or
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are VPS's, or
- It can be written as `(A)`, where `A` is a VPS.

We can similarly define the nesting depth `depth(S)` of any VPS `S` as follows:
- `depth("") = 0`
- `depth(A + B) = max(depth(A), depth(B))`, where `A` and `B` are VPS's
- `depth("(" + A + ")") = 1 + depth(A)`, where `A` is a VPS.

Given a VPS `seq`, split it into two disjoint subsequences `A` and `B`, such that `A` and `B` are VPS's (and `A.length + B.length = seq.length`). The subsequences may not necessarily be contiguous.

Choose any such `A` and `B` such that `max(depth(A), depth(B))` is the **minimum possible value**.

Return an answer array (of length `seq.length`) that encodes such a choice of `A` and `B`: `answer[i] = 0` if `seq[i]` is part of `A`, else `answer[i] = 1`. You may return any valid answer.

---

## Examples

### Example 1:
- **Input:** `seq = "(()())"`
- **Output:** `[0, 1, 1, 1, 1, 0]`

### Example 2:
- **Input:** `seq = "()(())()"`
- **Output:** `[0, 0, 0, 1, 1, 0, 1, 1]`

---

## Constraints

- $1 \le \text{seq.size} \le 10000$

---

## Intuition & Approach

### Parity-Based Depth Distribution

To minimize $\max(\text{depth}(A), \text{depth}(B))$, the total nesting depth $D$ must be split as evenly as possible between subsequences $A$ and $B$, achieving an optimal depth of $\lceil D / 2 \rceil$.

1. **Even vs. Odd Depths:**  
   Assign alternating nesting depth levels to $A$ and $B$:
   - All parentheses at **even** nesting depths are assigned to group `0` ($A$).
   - All parentheses at **odd** nesting depths are assigned to group `1` ($B$).

2. **Matching Brackets to the Same Group:**  
   For each matching pair of parentheses:
   - When encountering `'('`: Increment `depth` first, then assign `ans[i] = depth % 2`.
   - When encountering `')'`: Assign `ans[i] = depth % 2` *before* decrementing `depth`.
   
   This ensures that any opening bracket and its corresponding closing bracket share the exact same `depth` value, putting both into the same subsequence and preserving the VPS property for both $A$ and $B$.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single linear scan across the string `seq` of length $N$.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Excluding the output array `ans`, only scalar integer counters are allocated.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n, 0);
        int depth = 0;

        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                depth++;
                ans[i] = depth % 2;
            } else {
                ans[i] = depth % 2;
                depth--;
            }
        }

        return ans;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "(()())"
    string seq1 = "(()())";
    vector<int> res1 = solver.maxDepthAfterSplit(seq1);
    cout << "Test 1 Output: [";
    for (size_t i = 0; i < res1.size(); i++) {
        cout << res1[i] << (i + 1 < res1.size() ? ", " : "");
    }
    cout << "]\n";

    // Test Case 2: "()(())()"
    string seq2 = "()(())()";
    vector<int> res2 = solver.maxDepthAfterSplit(seq2);
    cout << "Test 2 Output: [";
    for (size_t i = 0; i < res2.size(); i++) {
        cout << res2[i] << (i + 1 < res2.size() ? ", " : "");
    }
    cout << "]\n";

    return 0;
}
```
