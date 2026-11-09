# 12. Integer to Roman

**Difficulty:** Medium  
**Topics:** Hash Table, Math, String  
**Language:** C++

## Problem Statement

Seven different symbols represent Roman numerals with the following values:

| Symbol | Value |
| :--- | :--- |
| **I** | 1 |
| **V** | 5 |
| **X** | 10 |
| **L** | 50 |
| **C** | 100 |
| **D** | 500 |
| **M** | 1000 |

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral follows these rules:

- If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
- If the value starts with 4 or 9, use the subtractive form representing one symbol subtracted from the following symbol:
  - `4` $\to$ `IV`
  - `9` $\to$ `IX`
  - `40` $\to$ `XL`
  - `90` $\to$ `XC`
  - `400` $\to$ `CD`
  - `900` $\to$ `CM`
- Only powers of 10 (`I`, `X`, `C`, `M`) can be appended consecutively at most 3 times. Symbols `V`, `L`, and `D` cannot be appended multiple times.

Given an integer `num`, convert it to a Roman numeral.

---

## Examples

### Example 1:
- **Input:** `num = 3749`
- **Output:** `"MMMDCCXLIX"`
- **Explanation:**
  - $3000 = \text{MMM}$ ($1000 + 1000 + 1000$)
  - $700 = \text{DCC}$ ($500 + 100 + 100$)
  - $40 = \text{XL}$ ($50 - 10$)
  - $9 = \text{IX}$ ($10 - 1$)

### Example 2:
- **Input:** `num = 58`
- **Output:** `"LVIII"`
- **Explanation:**
  - $50 = \text{L}$
  - $8 = \text{VIII}$ ($5 + 1 + 1 + 1$)

### Example 3:
- **Input:** `num = 1994`
- **Output:** `"MCMXCIV"`
- **Explanation:**
  - $1000 = \text{M}$
  - $900 = \text{CM}$
  - $90 = \text{XC}$
  - $4 = \text{IV}$

---

## Constraints

- $1 \le \text{num} \le 3999$

---

## Intuition & Approach

### Greedy Subtraction via Predefined Denominations

The Roman numeral system is a greedy numeral system where larger denominations always take precedence over smaller ones. 

1. **Precomputing Subtractive Combinations:**  
   Instead of handling the 6 subtractive edge cases (`IV`, `IX`, `XL`, `XC`, `CD`, `CM`) via conditional branching, include them directly as valid base denominations alongside standard symbols in strictly descending order:
   - Values: `[1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]`
   - Symbols: `["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]`

2. **Greedy Reduction:**  
   - Iterate through the sorted denominations from largest to smallest.
   - For each denomination `val[i]`, determine how many times it fits into `num`:  
     $$\text{times} = \lfloor \text{num} / \text{val}[i] \rfloor$$
   - Append `sym[i]` to `result` exactly `times` times.
   - Update `num = num % val[i]`.
   - If `num == 0`, terminate early.

3. **Performance Optimization:**  
   The maximum possible length of a Roman numeral for numbers $\le 3999$ is 15 characters (e.g., `3888` $\to$ `MMMDCCCLXXXVIII`). Reserving 16 bytes for `result` (`result.reserve(16)`) avoids repeated memory reallocations.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$  
  The number of denominations is constant (13 items), and the inner loop executes at most 3 times for any single denomination. The total iterations are strictly bounded regardless of the input value.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Static arrays of fixed size 13 and a string of maximum length 15.

---

## C++ Implementation

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string intToRoman(int num) {
        static const vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        static const vector<string> sym{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = "";
        result.reserve(16);
        for (size_t i = 0; i < val.size(); i++) {
            if (num == 0) {
                break;
            }
            int times = num / val[i];
            while (times--) {
                result += sym[i];
            }
            num = num % val[i];
        }
        return result;
    }
};

int main() {
    Solution solver;

    // Test Case 1: 3749 -> Expected: "MMMDCCXLIX"
    cout << "Test 1: " << solver.intToRoman(3749) << endl;

    // Test Case 2: 58 -> Expected: "LVIII"
    cout << "Test 2: " << solver.intToRoman(58) << endl;

    // Test Case 3: 1994 -> Expected: "MCMXCIV"
    cout << "Test 3: " << solver.intToRoman(1994) << endl;

    return 0;
}
```
