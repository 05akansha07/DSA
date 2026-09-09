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
- `1 <= n <= 10^15`

---

## Approach & Intuition

### Threshold Accumulation Pattern
Instead of determining how many commas each individual number requires, we count how many numbers reach or exceed each comma milestone:

- Every number $\ge 1,000$ earns its **1st comma**.
- Every number $\ge 1,000,000$ earns its **2nd comma**.
- Every number $\ge 1,000,000,000$ earns its **3rd comma**, and so on.

For each milestone threshold $T \in \{10^3, 10^6, 10^9, \dots\}$:
- The count of integers in the inclusive range $[T, n]$ is:
  $$	ext{Count} = n - T + 1$$
- By summing $(n - T + 1)$ across all valid thresholds where $n \ge T$, numbers crossing multiple thresholds automatically accumulate the correct total count of commas without mutual-exclusion logic.

### 64-bit Overflow Prevention
Because $n \le 10^{15}$, computations must use 64-bit signed integers (`long long`). When updating the milestone (`threshold *= 1000`), an overflow check (`threshold > LLONG_MAX / 1000`) prevents undefined arithmetic behavior on signed integer limits.

---

## C++ Implementation

```cpp
/**
 * Problem: Number of Commas in Standard Number Formatting
 * Complexity:
 *   - Time: O(log_{1000}(n)) ‚âà O(1)
 *   - Space: O(1)
 */

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long threshold = 1000;

        while (n >= threshold) {
            total += (n - threshold + 1);

            // Guard against signed 64-bit overflow before multiplication
            if (threshold > LLONG_MAX / 1000) {
                break;
            }
            threshold *= 1000;
        }

        return total;
    }
};

int main() {
    Solution sol;
    cout << "Test 1 (n = 1002): " << sol.countCommas(1002) << " (Expected: 3)" << endl;
    cout << "Test 2 (n = 998):  " << sol.countCommas(998) << " (Expected: 0)" << endl;
    cout << "Test 3 (n = 1000000000000000): " << sol.countCommas(1000000000000000LL) << endl;
    return 0;
}
```

---

## Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time Complexity** | $\mathcal{O}(\log_{1000} n)$ | The loop runs at most $ pprox 5$ times for $n \le 10^{15}$, effectively executing in constant time $\mathcal{O}(1)$. |
| **Auxiliary Space** | $\mathcal{O}(1)$ | Uses only two scalar 64-bit integer variables (`total`, `threshold`). |
