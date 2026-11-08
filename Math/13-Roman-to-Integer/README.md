# 13. Roman to Integer

**Difficulty:** Easy

**Topics:** Hash Table, Math, String

**Language:** C++

## Problem Statement

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

| Symbol | Value |
| :--- | :--- |
| **I** | 1 |
| **V** | 5 |
| **X** | 10 |
| **L** | 50 |
| **C** | 100 |
| **D** | 500 |
| **M** | 1000 |

For example, $2$ is written as `II` in Roman numeral, just two ones added together. $12$ is written as `XII`, which is simply `X + II`. The number $27$ is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:
- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9. 
- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90. 
- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

---

## Examples

### Example 1:
- **Input:** `s = "III"`
- **Output:** `3`
- **Explanation:** `III = 3`.

### Example 2:
- **Input:** `s = "LVIII"`
- **Output:** `58`
- **Explanation:** `L = 50`, `V = 5`, `III = 3`.

### Example 3:
- **Input:** `s = "MCMXCIV"`
- **Output:** `1994`
- **Explanation:** `M = 1000`, `CM = 900`, `XC = 90`, and `IV = 4`.

---

## Constraints

- $1 \le s.\text{length} \le 15$
- `s` contains only the characters (`'I'`, `'V'`, `'X'`, `'L'`, `'C'`, `'D'`, `'M'`).
- It is guaranteed that `s` is a valid roman numeral in the range $[1, 3999]$.

---

## Intuition & Approach

### Subtractive Lookahead Rule

In standard additive notation, each symbol contributes its face value directly to the total sum. Subtraction only occurs when a numeral of strictly lower value precedes a numeral of strictly higher value.

1. **Mapping Numerals:**
   - Instead of hash map lookups (`std::unordered_map`), use an `inline` `switch` statement or small lookup table. This avoids hashing overhead and gives $\mathcal{O}(1)$ branch predictions.

2. **Lookahead Decision Rule:**
   - Iterate through the string from index $0$ to $n - 1$.
   - For character at index $i$ with value $v_i$:
     - Check the adjacent character at $i + 1$ with value $v_{i+1}$.
     - If $i + 1 < n$ and $v_i < v_{i+1}$, $v_i$ is part of a subtractive pair (e.g., `IV` $\to 5 - 1 = 4$, `CM` $\to 1000 - 100 = 900$). Subtract $v_i$ from `total`:
       $$\text{total} \mathrel{-}= v_i$$
     - Otherwise, add $v_i$ to `total`:
       $$\text{total} \mathrel{+}= v_i$$

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  Where $N$ is the length of the string $s$. Since $N \le 15$, this executes in $\mathcal{O}(1)$ time in practice.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Only scalar variables (`total`, `currentVal`, `n`) are used.

---

## C++ Implementation

```cpp
#include <iostream>
#include <string>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
private:
    inline int charToValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default:  return 0;
        }
    }

public:
    int romanToInt(const string& s) {
        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int currentVal = charToValue(s[i]);

            // If a smaller value precedes a larger value, subtract it
            if (i + 1 < n && currentVal < charToValue(s[i + 1])) {
                total -= currentVal;
            } else {
                total += currentVal;
            }
        }

        return total;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "III" -> Expected: 3
    cout << "Test 1: " << solver.romanToInt("III") << endl;

    // Test Case 2: "LVIII" -> Expected: 58
    cout << "Test 2: " << solver.romanToInt("LVIII") << endl;

    // Test Case 3: "MCMXCIV" -> Expected: 1994
    cout << "Test 3: " << solver.romanToInt("MCMXCIV") << endl;

    return 0;
}
```
