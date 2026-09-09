# LeetCode - Number of Commas in Number Formatting

## Problem Statement
You are given an integer `n`. Return the total number of commas used when writing all integers from `[1, n]` (inclusive) in standard number formatting.

In standard formatting:
- A comma is inserted after every three digits from the right.
- Numbers with fewer than 4 digits contain no commas.

---

## Examples

### Example 1
```text
Input: n = 1002
Output: 3
Explanation: The numbers "1,000", "1,001", and "1,002" each contain one comma, giving a total of 3.
```

### Example 2
```text
Input: n = 998
Output: 0
Explanation: All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.
```

---

## Constraints
- `1 <= n <= 10^5`

---

## Approach & Intuition

### 1. Direct Constraint Analysis (O(1))
Given $1 \le n \le 10^5 = 100,000$:
- Numbers from `1` to `999` (fewer than 4 digits) have **0 commas**.
- Numbers from `1,000` to `100,000` have **1 comma** each.
- Numbers with 2 commas only start at `1,000,000` ($10^6$), which exceeds the upper bound constraint ($10^5$).

Therefore:
- If `n < 1000`, the answer is `0`.
- If `n >= 1000`, every integer in the inclusive range `[1000, n]` contributes exactly 1 comma:
  $$\text{Count} = n - 1000 + 1 = n - 999$$

---

## C++ Implementation

```cpp
/**
 * Problem: Number of Commas in Standard Number Formatting
 * Complexity:
 *   - Time: O(1)
 *   - Space: O(1)
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) {
            return 0;
        }
        return n - 999;
    }
};

// --- Follow-up: Generalized Solution for any n (up to 10^18) ---
class SolutionFollowUp {
public:
    long long countTotalCommas(long long n) {
        long long total = 0;
        long long threshold = 1000;

        while (n >= threshold) {
            total += (n - threshold + 1);
            threshold *= 1000;
        }
        return total;
    }
};

int main() {
    Solution sol;
    cout << "Test 1 (n = 1002): " << sol.countCommas(1002) << " (Expected: 3)" << endl;
    cout << "Test 2 (n = 998):  " << sol.countCommas(998) << " (Expected: 0)" << endl;
    cout << "Test 3 (n = 100000): " << sol.countCommas(100000) << " (Expected: 99001)" << endl;
    return 0;
}
```

---

## Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time Complexity** | $\mathcal{O}(1)$ | Simple arithmetic evaluation executes in constant time. |
| **Auxiliary Space** | $\mathcal{O}(1)$ | Operates using no extra heap or stack space. |
