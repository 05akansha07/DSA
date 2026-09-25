# 3550. Smallest Index With Digit Sum Equal to Index

**Difficulty:** Easy  
**Topics:** Array, Math, Simulation  
**Language:** C++

---

## Problem Statement

You are given an integer array `nums`.

Return the **smallest index** `i` such that the sum of the digits of `nums[i]` is equal to `i`. If no such index exists, return `-1`.

---

## Examples

### Example 1:
- **Input:** `nums = [1, 3, 2]`
- **Output:** `2`
- **Explanation:**
  - For `i = 0`: `nums[0] = 1` $\to$ digit sum = $1 \ne 0$.
  - For `i = 1`: `nums[1] = 3` $\to$ digit sum = $3 \ne 1$.
  - For `i = 2`: `nums[2] = 2` $\to$ digit sum = $2 = 2$.
  - Smallest valid index is `2`.

### Example 2:
- **Input:** `nums = [1, 10, 11]`
- **Output:** `1`
- **Explanation:**
  - For `i = 1`: `nums[1] = 10` $\to$ digit sum = $1 + 0 = 1$.
  - For `i = 2`: `nums[2] = 11` $\to$ digit sum = $1 + 1 = 2$.
  - Since index `1` is the smallest valid index, return `1`.

### Example 3:
- **Input:** `nums = [1, 2, 3]`
- **Output:** `-1`
- **Explanation:** No index satisfies the condition.

---

## Constraints

- $1 \le \text{nums.length} \le 100$
- $0 \le \text{nums}[i] \le 1000$

---

## Intuition & Approach

### Linear Scan with Early Exit

Because we need to return the **smallest** index that satisfies the condition:
1. **Sequential Traversal:**  
   Iterate from left to right through the array using index $i = 0, 1, \dots, N - 1$.
2. **Digit Sum Helper:**  
   For each element `nums[i]`, compute its digit sum by repeatedly taking `n % 10` and dividing by $10$.
3. **Early Termination:**  
   The first index $i$ where $\text{digitSum}(\text{nums}[i]) == i$ is guaranteed to be the smallest valid index. Returning immediately avoids redundant calculations.
4. **Fallback:**  
   If the loop finishes without finding any match, return `-1`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \log_{10} M)$  
  Where $N$ is the number of elements in `nums` ($N \le 100$) and $M$ is the maximum value in `nums` ($M \le 1000$, so at most $4$ digits per number). This runs well within $400$ operations.
- **Space Complexity:** $\mathcal{O}(1)$  
  Only uses a few scalar variables for division and summation.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            if (getDigitSum(nums[i]) == i) {
                return i; // First match is guaranteed to be the smallest index
            }
        }
        return -1;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1, 3, 2] -> Expected: 2
    vector<int> nums1 = {1, 3, 2};
    cout << "Test 1 Output: " << solver.smallestIndex(nums1) << endl;

    // Test Case 2: [1, 10, 11] -> Expected: 1
    vector<int> nums2 = {1, 10, 11};
    cout << "Test 2 Output: " << solver.smallestIndex(nums2) << endl;

    // Test Case 3: [1, 2, 3] -> Expected: -1
    vector<int> nums3 = {1, 2, 3};
    cout << "Test 3 Output: " << solver.smallestIndex(nums3) << endl;

    // Test Case 4: Element 0 at index 0 -> Expected: 0
    vector<int> nums4 = {0, 5, 9};
    cout << "Test 4 Output: " << solver.smallestIndex(nums4) << endl;

    return 0;
}
```
