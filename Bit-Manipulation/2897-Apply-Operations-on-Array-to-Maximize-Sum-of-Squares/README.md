# 2897. Apply Operations on Array to Maximize Sum of Squares

**Difficulty:** Hard  
**Topics:** Array, Hash Table, Math, Greedy, Bit Manipulation  
**Language:** C++

---

## Problem Statement

You are given a **0-indexed** integer array `nums` and a positive integer `k`.

You can do the following operation on the array any number of times:
- Choose any two distinct indices `i` and `j` and simultaneously update the values of `nums[i]` to `(nums[i] AND nums[j])` and `nums[j]` to `(nums[i] OR nums[j])`.

You have to choose `k` elements from the final array and calculate the sum of their squares.

Return the **maximum sum of squares** you can achieve. Since the answer can be very large, return it modulo $10^9 + 7$.

---

## Examples

### Example 1:
- **Input:** `nums = [2, 6, 5, 8]`, `k = 2`
- **Output:** `261`
- **Explanation:**
  - Choose $i = 0$ and $j = 3$: `nums[0] = (2 AND 8) = 0`, `nums[3] = (2 OR 8) = 10`. Array becomes `[0, 6, 5, 10]`.
  - Choose $i = 2$ and $j = 3$: `nums[2] = (5 AND 10) = 0`, `nums[3] = (5 OR 10) = 15`. Array becomes `[0, 6, 0, 15]`.
  - Choose the two elements $15$ and $6$:
    $$15^2 + 6^2 = 225 + 36 = 261$$

### Example 2:
- **Input:** `nums = [4, 5, 4, 7]`, `k = 3`
- **Output:** `90`
- **Explanation:**
  - No operations needed. Choose elements $7, 5, 4$:
    $$7^2 + 5^2 + 4^2 = 49 + 25 + 16 = 90$$

---

## Constraints

- $1 \le k \le \text{nums.length} \le 10^5$
- $1 \le \text{nums}[i] \le 10^9$

---

## Intuition & Approach

### Bit Shift Conservation & Greedy Aggregation

1. **Invariance of Bit Counts:**  
   Notice what the operation $(a, b) \to (a \text{ AND } b, a \text{ OR } b)$ actually does to the bits:
   - For every bit position $b$, if both numbers had bit $b$, both retain it.
   - If neither had bit $b$, neither gets it.
   - If exactly one number had bit $b$, the bit is moved exclusively to the $\text{OR}$ result ($a \text{ OR } b$), while the $\text{AND}$ result gets a $0$.
   
   Therefore, **bits are never created or destroyed**; they simply migrate toward larger numbers. The total count of set bits at each bit position across the entire array remains strictly constant.

2. **Maximizing Sum of Squares:**  
   By the convexity of $f(x) = x^2$, for any positive integers $x > y$ and $\Delta > 0$:
   $$(x + \Delta)^2 + (y - \Delta)^2 > x^2 + y^2$$
   To maximize the sum of squares, we should make the largest numbers as large as possible by concentrating as many set bits into them as we can.

3. **Algorithm:**  
   - Count the total occurrences of each bit position across all numbers: `bitCount[b]` for $0 \le b < 30$ (since $\text{nums}[i] \le 10^9 < 2^{30}$).
   - Greedily construct the $k$ largest possible numbers:
     - For each of the $k$ numbers, turn on bit $b$ if `bitCount[b] > 0`, and decrement `bitCount[b]`.
   - Square each constructed number modulo $10^9 + 7$ and accumulate the total sum.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \log(\max(\text{nums})) + k \log(\max(\text{nums})))$  
  With $\approx 30$ bits, counting takes $30N$ operations, and constructing $k$ elements takes $30k$ operations. This is strictly $\mathcal{O}(N)$ and runs in under 40 ms.
- **Space Complexity:** $\mathcal{O}(1)$  
  Uses a fixed-size array of 31 elements to store bit counts.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxSumSquares(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> bitCount(31, 0);

        // Step 1: Count frequency of each bit position across the array
        for (int num : nums) {
            for (int b = 0; b < 30; b++) {
                if ((num >> b) & 1) {
                    bitCount[b]++;
                }
            }
        }

        long long totalSum = 0;

        // Step 2: Greedily construct the k largest possible numbers
        for (int i = 0; i < k; i++) {
            long long currentVal = 0;
            for (int b = 0; b < 30; b++) {
                if (bitCount[b] > 0) {
                    currentVal |= (1LL << b);
                    bitCount[b]--;
                }
            }
            long long squareVal = (currentVal % MOD) * (currentVal % MOD) % MOD;
            totalSum = (totalSum + squareVal) % MOD;
        }

        return totalSum;
    }
};

int main() {
    Solution solver;

    // Test Case 1: nums = [2, 6, 5, 8], k = 2 -> Expected: 261
    vector<int> t1 = {2, 6, 5, 8};
    cout << "Test 1 Output: " << solver.maxSumSquares(t1, 2) << endl;

    // Test Case 2: nums = [4, 5, 4, 7], k = 3 -> Expected: 90
    vector<int> t2 = {4, 5, 4, 7};
    cout << "Test 2 Output: " << solver.maxSumSquares(t2, 3) << endl;

    // Test Case 3: nums = [1, 1, 1], k = 1 -> Expected: 1
    vector<int> t3 = {1, 1, 1};
    cout << "Test 3 Output: " << solver.maxSumSquares(t3, 1) << endl;

    return 0;
}
```
