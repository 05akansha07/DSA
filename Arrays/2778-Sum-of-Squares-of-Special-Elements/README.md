# 2778. Sum of Squares of Special Elements

**Difficulty:** Easy  
**Topics:** Array, Simulation, Math  
**Language:** C++

---

## Problem Statement

You are given a **1-indexed** integer array `nums` of length `n`.

An element `nums[i]` of `nums` is called **special** if `i` divides `n`, i.e. `n % i == 0`.

Return the sum of the squares of all special elements of `nums`.

---

## Examples

### Example 1:
- **Input:** `nums = [1, 2, 3, 4]`
- **Output:** `21`
- **Explanation:** 
  There are exactly 3 special elements in `nums`:
  - `nums[1]` since $4 \pmod 1 == 0$
  - `nums[2]` since $4 \pmod 2 == 0$
  - `nums[4]` since $4 \pmod 4 == 0$
  
  $$\text{Sum of squares} = 1^2 + 2^2 + 4^2 = 1 + 4 + 16 = 21$$

### Example 2:
- **Input:** `nums = [2, 7, 1, 19, 18, 3]`
- **Output:** `63`
- **Explanation:** 
  There are exactly 4 special elements in `nums`:
  - `nums[1]` since $6 \pmod 1 == 0$
  - `nums[2]` since $6 \pmod 2 == 0$
  - `nums[3]` since $6 \pmod 3 == 0$
  - `nums[6]` since $6 \pmod 6 == 0$

  $$\text{Sum of squares} = 2^2 + 7^2 + 1^2 + 3^2 = 4 + 49 + 1 + 9 = 63$$

---

## Constraints

- $1 \le \text{nums.length} == n \le 50$
- $1 \le \text{nums}[i] \le 50$

---

## Intuition & Approach

### 1-Based Index Divisibility Check

The problem requires summing the squares of elements at 1-based indices $i$ that are divisors of the total array length $n$.

1. **Iteration:**  
   Loop through 1-based indices $i$ from $1$ up to $n$.
2. **Divisibility Condition:**  
   Check if $n \pmod i == 0$.
3. **Square & Accumulate:**  
   Because C++ vectors are 0-indexed, the element corresponding to 1-based index $i$ is located at `nums[i - 1]`. If $i$ divides $n$, add `nums[i - 1] * nums[i - 1]` to the running sum.

Given $n \le 50$, this linear scan performs at most 50 modulo operations, which runs instantaneously.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single loop from $1$ to $N$, with $\mathcal{O}(1)$ arithmetic operations at each iteration.
- **Space Complexity:** $\mathcal{O}(1)$  
  Uses only scalar integer variables (`n`, `sum`, `i`).

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                sum += nums[i - 1] * nums[i - 1];
            }
        }
        return sum;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1, 2, 3, 4] -> Expected: 21
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Test 1 Output: " << solver.sumOfSquares(nums1) << endl;

    // Test Case 2: [2, 7, 1, 19, 18, 3] -> Expected: 63
    vector<int> nums2 = {2, 7, 1, 19, 18, 3};
    cout << "Test 2 Output: " << solver.sumOfSquares(nums2) << endl;

    // Test Case 3: Single element [5] -> Expected: 25
    vector<int> t3 = {5};
    cout << "Test 3 Output: " << solver.sumOfSquares(t3) << endl;

    return 0;
}
```
