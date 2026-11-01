# 453. Minimum Moves to Equal Array Elements

**Difficulty:** Medium  
**Topics:** Array, Math  
**Language:** C++

---

## Problem Statement

Given an integer array `nums` of size $n$, return the minimum number of moves required to make all array elements equal.

In one move, you can increment $n - 1$ elements of the array by $1$.

---

## Examples

### Example 1:
- **Input:** `nums = [1, 2, 3]`
- **Output:** `3`
- **Explanation:** Only three moves are needed (each move increments two elements):
  `[1, 2, 3]` $\to$ `[2, 3, 3]` $\to$ `[3, 4, 3]` $\to$ `[4, 4, 4]`

### Example 2:
- **Input:** `nums = [1, 1, 1]`
- **Output:** `0`

---

## Constraints

- $n == \text{nums.length}$
- $1 \le \text{nums.length} \le 10^5$
- $-10^9 \le \text{nums}[i] \le 10^9$
- The answer is guaranteed to fit in a 32-bit integer.

---

## Intuition & Approach

### Relative Invariant: Incrementing $n - 1$ vs. Decrementing 1

Incrementing $n - 1$ elements by $1$ increases the sum of the array by $n - 1$, while leaving exactly one element unchanged. 

In terms of **relative differences between elements**, incrementing $n - 1$ elements by $1$ is completely equivalent to **decrementing a single element by $1$**:
- If all elements except element $x$ increase by $1$, then relative to the rest of the array, element $x$ has decreased by $1$.
- To make all elements equal by decrementing one element at a time, the optimal target value is the global minimum of the array, $\min(\text{nums})$.
- Reducing any element down below $\min(\text{nums})$ would require strictly more operations.

Therefore, the minimum number of moves is simply the sum of differences between each element and the minimum element in the array:

$$\text{moves} = \sum_{i=0}^{n-1} (\text{nums}[i] - \min(\text{nums})) = \sum_{i=0}^{n-1} \text{nums}[i] - n \times \min(\text{nums})$$

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass through the array to find the minimum element and accumulate the deviations.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Uses scalar variables without auxiliary arrays.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minVal = INT_MAX;
        long long sum = 0; 
        for(int i = 0; i < n; i++){
            if(nums[i] < minVal){
                minVal = nums[i];
            }
            sum += nums[i];
        }
        return static_cast<int> (sum - 1LL*n*minVal); 
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1, 2, 3] -> Expected: 3
    vector<int> t1 = {1, 2, 3};
    cout << "Test 1: " << solver.minMoves(t1) << endl;

    // Test Case 2: [1, 1, 1] -> Expected: 0
    vector<int> t2 = {1, 1, 1};
    cout << "Test 2: " << solver.minMoves(t2) << endl;

    // Test Case 3: [-100, 0, 100] -> Expected: 300
    vector<int> t3 = {-100, 0, 100};
    cout << "Test 3: " << solver.minMoves(t3) << endl;

    return 0;
}
```
