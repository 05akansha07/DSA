# 1401. Circle and Rectangle Overlapping

**Difficulty:** Medium  
**Topics:** Math, Geometry  
**Language:** C++

---

## Problem Statement

You are given a circle represented as `(radius, xCenter, yCenter)` and an axis-aligned rectangle represented as `(x1, y1, x2, y2)`, where `(x1, y1)` are the coordinates of the bottom-left corner, and `(x2, y2)` are the coordinates of the top-right corner of the rectangle.

Return `true` if the circle and rectangle overlap, otherwise return `false`. In other words, check if there is any point $(x_i, y_i)$ that belongs to the circle and the rectangle at the same time.

---

## Examples

### Example 1:
- **Input:** `radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1`
- **Output:** `true`
- **Explanation:** The circle and rectangle share the boundary point `(1, 0)`.

### Example 2:
- **Input:** `radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1`
- **Output:** `false`
- **Explanation:** The minimum distance from the circle center `(1, 1)` to the rectangle is 2 units (to `y = -1`), which exceeds `radius = 1`.

### Example 3:
- **Input:** `radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1`
- **Output:** `true`

---

## Constraints

- $1 \le \text{radius} \le 2000$
- $-10^4 \le \text{xCenter}, \text{yCenter} \le 10^4$
- $-10^4 \le x_1 < x_2 \le 10^4$
- $-10^4 \le y_1 < y_2 \le 10^4$

---

## Intuition & Approach

### Closest Point Clamping

To determine if the circle and the axis-aligned rectangle intersect, find the point $(x_{\text{closest}}, y_{\text{closest}})$ on or within the rectangle that is closest to the circle's center $(x_{\text{Center}}, y_{\text{Center}})$.

1. **Clamping to 1D Intervals:**  
   Because the rectangle is axis-aligned, we can independently project and clamp the circle's center onto each coordinate interval:
   $$x_{\text{closest}} = \max(x_1, \min(x_{\text{Center}}, x_2))$$
   $$y_{\text{closest}} = \max(y_1, \min(y_{\text{Center}}, y_2))$$

2. **Distance Comparison:**  
   Compute the squared Euclidean distance between the center and this closest point:
   $$dx = x_{\text{Center}} - x_{\text{closest}}$$
   $$dy = y_{\text{Center}} - y_{\text{closest}}$$
   $$\text{dist}^2 = dx^2 + dy^2$$

3. **Overlap Condition:**  
   If $\text{dist}^2 \le \text{radius}^2$, the closest point lies within or on the boundary of the circle, meaning the shapes overlap. Using squared distances avoids floating-point precision issues from square root computations.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$  
  Performs only constant arithmetic, clamping, and comparison operations.
- **Space Complexity:** $\mathcal{O}(1)$  
  Operates entirely in-place with primitive variables.

---

## C++ Implementation

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point on the rectangle to the circle's center
        // by clamping the center coordinates to the rectangle boundaries
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Calculate horizontal and vertical distances
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        // Check if Euclidean distance squared is within radius squared
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};

int main() {
    Solution solver;

    // Test Case 1: Circle and rectangle share point (1, 0)
    int radius1 = 1, xCenter1 = 0, yCenter1 = 0;
    int x1_1 = 1, y1_1 = -1, x2_1 = 3, y2_1 = 1;
    cout << "Test 1: " << (solver.checkOverlap(radius1, xCenter1, yCenter1, x1_1, y1_1, x2_1, y2_1) ? "true" : "false")
         << endl;

    // Test Case 2: Completely separated
    int radius2 = 1, xCenter2 = 1, yCenter2 = 1;
    int x1_2 = 1, y1_2 = -3, x2_2 = 2, y2_2 = -1;
    cout << "Test 2: " << (solver.checkOverlap(radius2, xCenter2, yCenter2, x1_2, y1_2, x2_2, y2_2) ? "true" : "false")
         << endl;

    // Test Case 3: Overlapping corner/edge
    int radius3 = 1, xCenter3 = 0, yCenter3 = 0;
    int x1_3 = -1, y1_3 = 0, x2_3 = 0, y2_3 = 1;
    cout << "Test 3: " << (solver.checkOverlap(radius3, xCenter3, yCenter3, x1_3, y1_3, x2_3, y2_3) ? "true" : "false")
         << endl;

    return 0;
}
