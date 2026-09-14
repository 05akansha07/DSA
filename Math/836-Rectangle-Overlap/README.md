# 836. Rectangle Overlap

**Difficulty:** Easy  
**Topics:** Math, Geometry  
**Language:** C++

---

## Problem Statement

An axis-aligned rectangle is represented as a list `[x1, y1, x2, y2]`, where `(x1, y1)` is the coordinate of its bottom-left corner, and `(x2, y2)` is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.

Two rectangles overlap if the area of their intersection is **positive**. To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two axis-aligned rectangles `rec1` and `rec2`, return `true` if they overlap, otherwise return `false`.

---

## Examples

### Example 1:

```text
        Y
        |
      3 |           +-------+ (3,3)
        |           | rec2  |
      2 |   +-------+-------+ (2,2)
        |   | rec1  |///////|
      1 |   |       +-------+ (1,1)
        |   |       |
      0 +---+-------+---------> X
        0   1       2       3
```

- **Input:** `rec1 = [0, 0, 2, 2]`, `rec2 = [1, 1, 3, 3]`
- **Output:** `true`
- **Explanation:** The intersection rectangle has dimensions $[1, 2] \times [1, 2]$ with positive area $1 \times 1 = 1 > 0$.

### Example 2:

- **Input:** `rec1 = [0, 0, 1, 1]`, `rec2 = [1, 0, 2, 1]`
- **Output:** `false`
- **Explanation:** The rectangles share a boundary along the vertical line $x = 1$, but their intersection area is $0$.

### Example 3:

- **Input:** `rec1 = [0, 0, 1, 1]`, `rec2 = [2, 2, 3, 3]`
- **Output:** `false`
- **Explanation:** The rectangles are completely disjoint.

---

## Constraints

- `rec1.length == 4`
- `rec2.length == 4`
- $-10^9 \le \text{rec1}[i], \text{rec2}[i] \le 10^9$
- `rec1` and `rec2` represent valid rectangles with a non-zero area (i.e., $x_1 < x_2$ and $y_1 < y_2$).

---

## Intuition & Approach

### 1D Interval Overlap Reduction

A 2D rectangle can be decomposed into two independent 1D intervals along the coordinate axes:
- **X-projection:** $[x_1, x_2]$
- **Y-projection:** $[y_1, y_2]$

Two rectangles overlap with **positive area** if and only if their projections overlap simultaneously along both dimensions with a positive length:

1. **X-Axis Overlap Condition:**  
   The intersection interval on the X-axis starts at $\max(\text{rec1}[0], \text{rec2}[0])$ and ends at $\min(\text{rec1}[2], \text{rec2}[2])$.  
   For positive width:
   $$\max(\text{rec1}[0], \text{rec2}[0]) < \min(\text{rec1}[2], \text{rec2}[2])$$

2. **Y-Axis Overlap Condition:**  
   Similarly, the intersection interval on the Y-axis starts at $\max(\text{rec1}[1], \text{rec2}[1])$ and ends at $\min(\text{rec1}[3], \text{rec2}[3])$.  
   For positive height:
   $$\max(\text{rec1}[1], \text{rec2}[1]) < \min(\text{rec1}[3], \text{rec2}[3])$$

Using strict inequality (`<`) instead of non-strict (`<=`) guarantees that boundary-sharing (touching edges or corners) resolves to `false`, satisfying the problem condition.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$  
  Computing `max` and `min` over 4 scalar coordinates executes in constant time.
- **Space Complexity:** $\mathcal{O}(1)$  
  No extra memory or auxiliary data structures are allocated.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec = [x1, y1, x2, y2]
        // An overlap with positive area exists iff both 1D intervals overlap
        bool overlapX = max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]);
        bool overlapY = max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);

        return overlapX && overlapY;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Standard overlap
    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};
    cout << "Test 1: " << (solver.isRectangleOverlap(rec1, rec2) ? "true" : "false") << endl;

    // Test Case 2: Touching along an edge (Area = 0)
    vector<int> rec3 = {0, 0, 1, 1};
    vector<int> rec4 = {1, 0, 2, 1};
    cout << "Test 2: " << (solver.isRectangleOverlap(rec3, rec4) ? "true" : "false") << endl;

    // Test Case 3: Completely disjoint
    vector<int> rec5 = {0, 0, 1, 1};
    vector<int> rec6 = {2, 2, 3, 3};
    cout << "Test 3: " << (solver.isRectangleOverlap(rec5, rec6) ? "true" : "false") << endl;

    return 0;
}
