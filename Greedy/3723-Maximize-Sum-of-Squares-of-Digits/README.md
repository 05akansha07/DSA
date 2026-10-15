# 3723. Maximize Sum of Squares of Digits

**Difficulty:** Medium  
**Topics:** Math, String, Greedy  
**Language:** C++

---

## Problem Statement

You are given two positive integers `num` and `sum`.

A positive integer $n$ is **good** if it satisfies both of the following:
- The number of digits in $n$ is exactly `num`.
- The sum of digits in $n$ is exactly `sum`.

The score of a good integer $n$ is the sum of the squares of digits in $n$.

Return a string denoting the good integer $n$ that achieves the **maximum score**. If there are multiple possible integers, return the **maximum one**. If no such integer exists, return an empty string `""`.

---

## Examples

### Example 1:
- **Input:** `num = 2, sum = 3`
- **Output:** `"30"`
- **Explanation:**
  There are 3 good integers: $12$, $21$, and $30$.
  - Score of $12$: $1^2 + 2^2 = 5$.
  - Score of $21$: $2^2 + 1^2 = 5$.
  - Score of $30$: $3^2 + 0^2 = 9$.
  - The maximum score is $9$, which is achieved by $30$. Therefore, the answer is `"30"`.

### Example 2:
- **Input:** `num = 2, sum = 17`
- **Output:** `"98"`
- **Explanation:**
  There are 2 good integers: $89$ and $98$.
  - Score of $89$: $8^2 + 9^2 = 145$.
  - Score of $98$: $9^2 + 8^2 = 145$.
  - The maximum score is $145$. The maximum good integer that achieves this score is $98$. Therefore, the answer is `"98"`.

### Example 3:
- **Input:** `num = 1, sum = 10`
- **Output:** `""`
- **Explanation:**
  There are no integers that have exactly 1 digit and whose digits sum to 10. Therefore, the answer is `""`.

---

## Constraints

- $1 \le \text{num} \le 2 \times 10^5$
- $1 \le \text{sum} \le 2 \times 10^6$

---

## Intuition & Approach

### Strict Convexity & Greedy Digit Concentration

1. **Convexity of $f(d) = d^2$:**  
   For any two digits $a \ge b$, transferring $1$ unit from $b$ to $a$ strictly increases the sum of squares:
   $$(a + 1)^2 + (b - 1)^2 = a^2 + 2a + 1 + b^2 - 2b + 1 = (a^2 + b^2) + 2(a - b + 1) > a^2 + b^2$$
   To maximize $\sum d_i^2$, we must make the digits as unequal as possible by pushing them toward their maximum ($9$) and minimum ($0$) values.

2. **Multiset of Digits:**  
   Given a target digit sum `sum` distributed over `num` digits:
   - **Feasibility:**
     - `sum < 1` (a positive integer must have at least one non-zero digit)
     - `(long long)sum > 9LL * num` (even setting all digits to 9 cannot reach `sum`)
   - **Greedy Partition:**
     - Take as many `9`s as possible: $\text{count9} = \lfloor \text{sum} / 9 \rfloor$.
     - At most one remainder digit: $\text{rem} = \text{sum} \pmod 9$.
     - The remaining positions are filled with `0`s:
       $$\text{count0} = \text{num} - \text{count9} - [\text{rem} > 0]$$

3. **Maximizing the Integer Value:**  
   Any rearrangement of these multiset digits results in the exact same sum of squares. To obtain the largest integer numerically, place the largest digits at the most significant positions:
   1. Place all `9`s first.
   2. Place the remainder digit `rem` (if `rem > 0`).
   3. Place all `0`s at the end.

   Since `sum >= 1`, the first digit is always non-zero ($9$ or `rem`), making the resulting number a valid integer without leading zeros.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(\text{num})$  
  String construction with `.reserve(num)` and chunk-appending runs in linear time relative to the number of digits.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Only the output string of length `num` is allocated.

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
public:
    string maxSumOfSquares(int num, int sum) {
        // Feasibility check:
        // A positive integer of 'num' digits has a digit sum between 1 and 9 * num.
        if (sum < 1 || (long long)sum > 9LL * num) {
            return "";
        }

        int count9 = sum / 9;
        int rem = sum % 9;
        int count0 = num - count9 - (rem > 0 ? 1 : 0);

        string result = "";
        result.reserve(num);

        // Maximize number: place 9's first, then remainder, then 0's
        result.append(count9, '9');
        if (rem > 0) {
            result.push_back('0' + rem);
        }
        result.append(count0, '0');

        return result;
    }
};

int main() {
    Solution solver;

    // Test Case 1: num = 2, sum = 3 -> Expected: "30"
    cout << "Test 1: " << solver.maxSumOfSquares(2, 3) << endl;

    // Test Case 2: num = 2, sum = 17 -> Expected: "98"
    cout << "Test 2: " << solver.maxSumOfSquares(2, 17) << endl;

    // Test Case 3: num = 1, sum = 10 -> Expected: ""
    cout << "Test 3: \"" << solver.maxSumOfSquares(1, 10) << "\"" << endl;

    // Test Case 4: num = 4, sum = 18 -> Expected: "9900"
    cout << "Test 4: " << solver.maxSumOfSquares(4, 18) << endl;

    return 0;
}
```
