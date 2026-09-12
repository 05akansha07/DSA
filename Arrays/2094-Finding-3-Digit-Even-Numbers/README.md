# Distinct 3-Digit Even Numbers

**Difficulty:** Easy / Medium  
**Topics:** Array, Hash Table, Enumeration  
**Language:** C++

---

## Problem Statement

You are given an array of digits called `digits`. Your task is to determine the number of **distinct** three-digit even numbers that can be formed using these digits.

**Note:**
- Each copy of a digit can only be used once per number.
- There may **not** be leading zeros (i.e., numbers must be in the range $[100, 998]$).

---

## Examples

### Example 1:
- **Input:** `digits = [1, 2, 3, 4]`
- **Output:** `12`
- **Explanation:** The 12 distinct 3-digit even numbers are:  
  `124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, 432`.  
  *(Note that 222 cannot be formed because there is only one copy of digit 2).*

### Example 2:
- **Input:** `digits = [0, 2, 2]`
- **Output:** `2`
- **Explanation:** The only valid numbers are `202` and `220`. `022` is invalid because of the leading zero.

### Example 3:
- **Input:** `digits = [6, 6, 6]`
- **Output:** `1`
- **Explanation:** Only `666` can be formed.

### Example 4:
- **Input:** `digits = [1, 3, 5]`
- **Output:** `0`
- **Explanation:** No even 3-digit numbers can be formed.

---

## Constraints

- $3 \le \text{digits.length} \le 10$
- $0 \le \text{digits}[i] \le 9$

---

## Intuition & Approach

Instead of generating permutations from the array (which requires handling duplicates and leading zeros manually), we can iterate over the finite search space of candidates:

1. **Fixed Search Space:**  
   Any valid 3-digit even number must fall in the range $[100, 998]$. Stepping by 2 from 100 ensures only even candidates are evaluated (exactly 450 values).

2. **Frequency Matching:**
   - Precompute the frequencies of all digits available in `digits`.
   - For every candidate even number:
     - Extract its digits: hundreds ($d_1$), tens ($d_2$), units ($d_3$).
     - Track the required digit frequencies in a frequency vector `req`.
     - Check whether the available `freq` has enough counts for $d_1$, $d_2$, and $d_3$.
     - Increment the match counter if all counts are satisfied.

This avoids duplicate generation and guarantees distinct numbers without allocating additional hash sets.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N + K)$  
  Where $N$ is the length of `digits` (to populate `freq`) and $K = 450$ is the constant number of 3-digit even numbers checked. Overall time complexity is $\mathcal{O}(N)$.
- **Space Complexity:** $\mathcal{O}(1)$  
  Fixed-size frequency vectors of length 10 are used.

---

## C++ Implementation

```cpp
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }

        int count = 0;
        for (int num = 100; num <= 999; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            vector<int> req(10, 0);
            req[d1]++;
            req[d2]++;
            req[d3]++;

            if (d3 % 2 == 0 && freq[d1] >= req[d1] && freq[d2] >= req[d2] && freq[d3] >= req[d3]) {
                count++;
            }
        }

        return count;
    }
};
```
