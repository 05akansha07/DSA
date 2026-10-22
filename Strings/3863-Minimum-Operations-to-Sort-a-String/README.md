# 3863. Minimum Operations to Sort a String

**Difficulty:** Medium  
**Topics:** String, Greedy, Sorting  
**Language:** C++

---

## Problem Statement

You are given a string `s` consisting of lowercase English letters.

In one operation, you can select any **proper substring** of `s` (a substring that is not the entire string, i.e., length $< n$) and sort it in non-descending alphabetical order.

Return the **minimum number of operations** required to make `s` sorted in non-descending order. If it is not possible, return `-1`.

---

## Examples

### Example 1:
- **Input:** `s = "dog"`
- **Output:** `1`
- **Explanation:**
  - Sort substring `"og"` (indices 1 to 2) to `"go"`.
  - Result is `"dgo"`, which is sorted. Thus, 1 operation.

### Example 2:
- **Input:** `s = "card"`
- **Output:** `2`
- **Explanation:**
  - Sort substring `"car"` (indices 0 to 2) to `"acr"`, yielding `"acrd"`.
  - Sort substring `"rd"` (indices 2 to 3) to `"dr"`, yielding `"acdr"`. Thus, 2 operations.

### Example 3:
- **Input:** `s = "gf"`
- **Output:** `-1`
- **Explanation:**
  - Any proper substring has length 1, which cannot change the string. It is impossible to sort `s`. Thus, `-1`.

---

## Constraints

- $1 \le s.\text{length} \le 10^5$
- `s` consists of only lowercase English letters.

---

## Intuition & Approach

### Case Analysis on Boundary Elements

Since we can sort any proper substring of length up to $n - 1$:

1. **0 Operations:**  
   If `s` is already sorted, return `0`.

2. **Impossible Case ($n = 2$):**  
   If $n = 2$ and `s` is unsorted, the only proper substrings have length 1, which do not change the order. Thus, sorting is impossible $\to$ return `-1`.

3. **1 Operation:**  
   - If the first character is already a global minimum (`s[0] == minChar`), sorting the suffix $s[1..n-1]$ (length $n - 1$) sorts the entire string.
   - If the last character is already a global maximum (`s[n - 1] == maxChar`), sorting the prefix $s[0..n-2]$ (length $n - 1$) sorts the entire string.
   - In either case, 1 operation suffices.

4. **3 Operations (Worst Case):**  
   - This occurs when the first character is strictly greater than all elements in the middle (`s[0] > maxMid`) **and** the last character is strictly smaller than all elements in the middle (`s[n - 1] < minMid`).
   - In this state, neither $s[0]$ can be moved into the middle by sorting $s[0..n-2]$ (it stays at index 0 because it is the local maximum of that prefix), nor can $s[n - 1]$ be moved into the middle by sorting $s[1..n-1]$ (it stays at index $n - 1$ because it is the local minimum of that suffix).
   - Thus, an extra operation is needed to disrupt this deadlock before sorting can proceed in 2 subsequent steps:
     1. Sort $s[0..n-2]$ (or $s[1..n-1]$) to move other elements.
     2. Sort the other boundary substring.
     3. Sort again to finalize.
   - Total operations $= 3$.

5. **2 Operations:**  
   If neither 1 nor 3 operations apply, 2 operations are always sufficient:
   - Sort one prefix/suffix to place a global minimum at index 0 or a global maximum at index $n - 1$, then sort the opposite side.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass or standard library linear scans (`is_sorted`, `min_element`, `max_element`) run in $\mathcal{O}(N)$ time.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Only scalar character variables are maintained.

---

## C++ Implementation

```cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        if (n == 2) {
            return -1;
        }

        char minChar = *min_element(s.begin(), s.end());
        char maxChar = *max_element(s.begin(), s.end());

        // Can finish in 1 operation using a suffix or prefix sort
        if (s[0] == minChar || s[n - 1] == maxChar) {
            return 1;
        }

        // Check if s[0] is the sole global maximum AND s[n-1] is the sole global minimum
        char minMid = *min_element(s.begin() + 1, s.end() - 1);
        char maxMid = *max_element(s.begin() + 1, s.end() - 1);

        if (s[0] > maxMid && s[n - 1] < minMid) {
            return 3;
        }

        return 2;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "dog" -> Expected: 1
    cout << "Test 1: " << solver.minOperations("dog") << endl;

    // Test Case 2: "card" -> Expected: 2
    cout << "Test 2: " << solver.minOperations("card") << endl;

    // Test Case 3: "gf" -> Expected: -1
    cout << "Test 3: " << solver.minOperations("gf") << endl;

    return 0;
}
```
