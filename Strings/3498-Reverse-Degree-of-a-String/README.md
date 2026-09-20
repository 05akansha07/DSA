# 3498. Reverse Degree of a String

**Difficulty:** Easy  
**Topics:** String, Simulation  
**Language:** C++

---

## Problem Statement

Given a string `s`, calculate its reverse degree.

The reverse degree is calculated as follows:
- For each character, multiply its position in the reversed alphabet (`'a' = 26`, `'b' = 25`, ..., `'z' = 1`) with its position in the string (1-indexed).
- Sum these products for all characters in the string.

Return the reverse degree of `s`.

---

## Examples

### Example 1:

- **Input:** `s = "abc"`
- **Output:** `148`
- **Explanation:**

| Letter | Index in Reversed Alphabet | Index in String | Product |
| :---: | :---: | :---: | :---: |
| `'a'` | 26 | 1 | 26 |
| `'b'` | 25 | 2 | 50 |
| `'c'` | 24 | 3 | 72 |

$$\text{Total} = 26 + 50 + 72 = 148$$

### Example 2:

- **Input:** `s = "zaza"`
- **Output:** `160`
- **Explanation:**

| Letter | Index in Reversed Alphabet | Index in String | Product |
| :---: | :---: | :---: | :---: |
| `'z'` | 1 | 1 | 1 |
| `'a'` | 26 | 2 | 52 |
| `'z'` | 1 | 3 | 3 |
| `'a'` | 26 | 4 | 104 |

$$\text{Total} = 1 + 52 + 3 + 104 = 160$$

---

## Constraints

- $1 \le \text{s.length} \le 1000$
- `s` contains only lowercase English letters.

---

## Intuition & Approach

### Linear Simulation

The problem requires a direct evaluation of each character's weighted contribution based on two properties:
1. **Reversed Alphabet Weight:**  
   The standard 0-indexed position of character $c$ in the alphabet is $c - \text{'a'}$, which ranges from $0$ for `'a'` to $25$ for `'z'`.  
   Inverting this mapping gives:
   $$\text{charWeight} = 26 - (c - \text{'a'})$$
   This assigns $26$ to `'a'` and $1$ to `'z'`.

2. **1-Indexed Position:**  
   For index $i$ in a 0-indexed string:
   $$\text{StringPos} = i + 1$$

3. **Accumulation:**  
   Iterate through each index $i$ from $0$ to $N - 1$, compute $\text{charWeight} \times \text{StringPos}$, and add it to the running sum.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  Where $N$ is the length of string `s`. The algorithm iterates through the string once, performing $\mathcal{O}(1)$ arithmetic per character.
- **Space Complexity:** $\mathcal{O}(1)$  
  Uses only constant scalar variables for calculation.

---

## C++ Implementation

```cpp
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            int charWeight = 26 - (s[i] - 'a');
            int StringPos = i + 1;
            total += charWeight * StringPos;
        }
        return total;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    string s1 = "abc";
    int result1 = solution.reverseDegree(s1);
    cout << "Test Case 1:" << endl;
    cout << "Input: s = \"" << s1 << "\"" << endl;
    cout << "Output: " << result1 << " (Expected: 148)" << endl;
    cout << "------------------------------------" << endl;

    // Test Case 2
    string s2 = "zaza";
    int result2 = solution.reverseDegree(s2);
    cout << "Test Case 2:" << endl;
    cout << "Input: s = \"" << s2 << "\"" << endl;
    cout << "Output: " << result2 << " (Expected: 160)" << endl;
    cout << "------------------------------------" << endl;

    return 0;
}
```
