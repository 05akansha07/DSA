# 3483. Unique 3-Digit Even Numbers

**Difficulty:** Easy  
**Topics:** Array, Hash Table, Enumeration  
**Language:** C++

---

## Problem Statement

You are given an array of digits called `digits`. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.

**Note:**
- Each copy of a digit can only be used once per number.
- There may not be leading zeros (numbers must be in the range [100, 998]).
- The number must be even.

---

## Examples

### Example 1:
```text
Input: digits = [1, 2, 3, 4]
Output: 12
Explanation: The 12 distinct 3-digit even numbers are:
124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432.
(Note: 222 cannot be formed because there is only one copy of digit 2).
```

### Example 2:
```text
Input: digits = [0, 2, 2]
Output: 2
Explanation: The only valid numbers are 202 and 220. 022 is invalid because of the leading zero.
```

### Example 3:
```text
Input: digits = [6, 6, 6]
Output: 1
Explanation: Only 666 can be formed.
```

### Example 4:
```text
Input: digits = [1, 3, 5]
Output: 0
Explanation: No even 3-digit numbers can be formed.
```

---

## Constraints

3 <= digits.length <= 10
0 <= digits[i] <= 9

---

## Intuition & Approach

Instead of generating index permutations from the array (which generates duplicates and forces using a hash set to clean them up), we **enumerate the output target space**:

1. **Fixed Search Space:**  
   Any valid 3-digit even number must lie strictly in the range $[100, 998]$. Stepping by 2 from 100 guarantees:
   - No leading zero (starts at 100).
   - Every candidate is guaranteed to be even (step size is 2).
   - Exactly $450$ fixed iterations: $\frac{998 - 100}{2} + 1 = 450$.

2. **Frequency Verification:**
   - Count available digit occurrences in a frequency array `freq` of size 10.
   - For each candidate number, extract its hundreds (`d1`), tens (`d2`), and units (`d3`) digits.
   - Count the required frequencies in `req`.
   - Check if `freq[d] >= req[d]` for all three digits.
   - If satisfied, increment `count++`.

This guarantees unique numbers are evaluated without needing dynamic allocations, sorting, or hash sets.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N + 450) = \mathcal{O}(N)$  
  Where $N$ is the length of `digits`. Populating the frequency array takes $\mathcal{O}(N)$, and checking the 450 candidate numbers takes constant $\mathcal{O}(1)$ time.
- **Space Complexity:** $\mathcal{O}(1)$  
  Fixed-size frequency vectors of length 10 are used.

---

## C++ Implementation

```cpp
#include <vector>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }

        int count = 0;
        // Search space: exactly 450 even 3-digit candidates
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            vector<int> req(10, 0);
            req[d1]++;
            req[d2]++;
            req[d3]++;

            if (freq[d1] >= req[d1] && freq[d2] >= req[d2] && freq[d3] >= req[d3]) {
                count++;
            }
        }

        return count;
    }
};
```
};
```
