# 2089. Find Target Indices After Sorting Array

**Difficulty:** Easy  
**Topics:** Array, Binary Search, Sorting  
**Language:** C++

---

## Problem Statement

You are given a **0-indexed** integer array `nums` and a target element `target`.

A **target index** is an index `i` such that `nums[i] == target` after sorting `nums` in **non-decreasing** order.

Return a list of the target indices of `nums` sorted in **increasing** order. If there are no target indices, return an empty list.

---

## Examples

### Example 1:
- **Input:** `nums = [1, 2, 5, 2, 3]`, `target = 2`
- **Output:** `[1, 2]`
- **Explanation:** After sorting, `nums` is `[1, 2, 2, 3, 5]`. The indices where `nums[i] == 2` are `1` and `2`.

### Example 2:
- **Input:** `nums = [1, 2, 5, 2, 3]`, `target = 3`
- **Output:** `[3]`
- **Explanation:** After sorting, `nums` is `[1, 2, 2, 3, 5]`. The index where `nums[i] == 3` is `3`.

### Example 3:
- **Input:** `nums = [1, 2, 5, 2, 3]`, `target = 4`
- **Output:** `[]`
- **Explanation:** There are no occurrences of `4` in `nums`.

---

## Constraints

- $1 \le \text{nums.length} \le 100$
- $1 \le \text{nums}[i], \text{target} \le 100$

---

## Intuition & Approach

### Counting (O(N) without Sorting)

Instead of explicitly sorting the array in $\mathcal{O}(N \log N)$ time, we can determine the final indices directly using the definition of sorted order:

1. **Rank of Elements:**
   - Any element strictly smaller than `target` must appear before all instances of `target` in the sorted array.
   - Let `lessCount` be the number of elements in `nums` where `num < target`. In 0-indexed terms, the first instance of `target` will sit precisely at index `lessCount`.

2. **Frequency of Target:**
   - Let `targetCount` be the total occurrences of `num == target`.
   - All occurrences of `target` will occupy contiguous indices starting from `lessCount` up to `lessCount + targetCount - 1`.

3. **Construction:**
   - If `targetCount == 0`, return an empty array.
   - Otherwise, append indices `lessCount + i` for each $i \in [0, \text{targetCount} - 1]$.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single linear pass over `nums` of length $N$ to compute `lessCount` and `targetCount`, followed by $\mathcal{O}(\text{targetCount})$ index generation.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Excluding the result vector, only scalar counters are maintained.

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
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lessCount = 0;
        int targetCount = 0;

        for (int num : nums) {
            if (num < target) {
                lessCount++;
            } else if (num == target) {
                targetCount++;
            }
        }

        vector<int> result;
        result.reserve(targetCount);

        for (int i = 0; i < targetCount; i++) {
            result.push_back(lessCount + i);
        }

        return result;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1,2,5,2,3], target = 2 -> Expected: [1, 2]
    vector<int> t1 = {1, 2, 5, 2, 3};
    vector<int> res1 = solver.targetIndices(t1, 2);
    cout << "Test 1: ";
    for (int idx : res1) cout << idx << " ";
    cout << "\n";

    // Test Case 2: [1,2,5,2,3], target = 3 -> Expected: [3]
    vector<int> t2 = {1, 2, 5, 2, 3};
    vector<int> res2 = solver.targetIndices(t2, 3);
    cout << "Test 2: ";
    for (int idx : res2) cout << idx << " ";
    cout << "\n";

    // Test Case 3: [1,2,5,2,3], target = 4 -> Expected: []
    vector<int> t3 = {1, 2, 5, 2, 3};
    vector<int> res3 = solver.targetIndices(t3, 4);
    cout << "Test 3: ";
    for (int idx : res3) cout << idx << " ";
    cout << "(empty)\n";

    return 0;
}
```
