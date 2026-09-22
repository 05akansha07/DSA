# 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

**Difficulty:** Medium  
**Topics:** Linked List  
**Language:** C++

---

## Problem Statement

A **critical point** in a linked list is defined as either a **local maxima** or a **local minima**.

- A node is a **local maxima** if the current node has a value strictly greater than the previous node and the next node.
- A node is a **local minima** if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list `head`, return an array of length 2 containing `[minDistance, maxDistance]` where `minDistance` is the minimum distance between any two distinct critical points and `maxDistance` is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return `[-1, -1]`.

---

## Examples

### Example 1:
- **Input:** `head = [3, 1]`
- **Output:** `[-1, -1]`
- **Explanation:** There are no critical points in `[3, 1]`.

### Example 2:
- **Input:** `head = [5, 3, 1, 2, 5, 1, 2]`
- **Output:** `[1, 3]`
- **Explanation:** There are three critical points:
  - Node with value `1` at position 3: Local minima (`1 < 3` and `1 < 2`).
  - Node with value `5` at position 5: Local maxima (`5 > 2` and `5 > 1`).
  - Node with value `1` at position 6: Local minima (`1 < 5` and `1 < 2`).
  - $\text{minDistance} = 6 - 5 = 1$ (between position 5 and position 6).
  - $\text{maxDistance} = 6 - 3 = 3$ (between position 3 and position 6).

### Example 3:
- **Input:** `head = [1, 3, 2, 2, 3, 2, 2, 2, 7]`
- **Output:** `[3, 3]`
- **Explanation:** 
  - Position 2 (value `3`) is a local maxima (`3 > 1` and `3 > 2`).
  - Position 5 (value `3`) is a local maxima (`3 > 2` and `3 > 2`).
  - Since only two critical points exist, both `minDistance` and `maxDistance` equal $5 - 2 = 3$.

---

## Constraints

- The number of nodes in the list is in the range $[2, 10^5]$.
- $1 \le \text{Node.val} \le 10^5$

---

## Intuition & Approach

### One-Pass Tracking with Index Pointers

To calculate the minimum and maximum distances between any two critical points:
1. **Critical Point Identification:**  
   Maintain `prev`, `curr`, and inspect `curr->next`. A node qualifies as:
   - **Local Maxima:** `curr->val > prev->val && curr->val > curr->next->val`
   - **Local Minima:** `curr->val < prev->val && curr->val < curr->next->val`

2. **Distance Properties:**
   - **Maximum Distance:** The maximum distance between any two critical points is always between the **first critical point** and the **last critical point** discovered:
     $$\text{maxDistance} = \text{lastCritical} - \text{firstCritical}$$
   - **Minimum Distance:** Because critical point positions are strictly increasing, the minimum distance must occur between two **consecutively occurring** critical points:
     $$\text{minDistance} = \min(\text{minDistance}, \text{currentCritical} - \text{previousCritical})$$

3. **Space Optimization:**  
   Instead of storing all critical point indices in a vector ($\mathcal{O}(N)$ memory), keep only:
   - `firstCritical`: Position of the very first critical point encountered.
   - `lastCritical`: Position of the most recently visited critical point.
   - `minDistance`: Running minimum difference between adjacent critical points.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass through the linked list of length $N$.
- **Space Complexity:** $\mathcal{O}(1)$  
  Uses constant auxiliary space with scalar variables.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        int ids = 1;

        int firstCritical = -1;
        int lastCritical = -1;
        int minDistance = INT_MAX;

        while (curr->next != nullptr) {
            bool isLocalMaxima = (curr->val > prev->val && curr->val > curr->next->val);
            bool isLocalMinima = (curr->val < prev->val && curr->val < curr->next->val);

            if (isLocalMaxima || isLocalMinima) {
                if (firstCritical == -1) {
                    firstCritical = ids;
                } else {
                    minDistance = min(minDistance, ids - lastCritical);
                }
                lastCritical = ids;
            }

            prev = curr;
            curr = curr->next;
            ids++;
        }

        if (firstCritical == -1 || firstCritical == lastCritical) {
            return {-1, -1};
        }

        int maxDistance = lastCritical - firstCritical;
        return {minDistance, maxDistance};
    }
};

// Helper function to build a linked list
ListNode* buildList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < values.size(); i++) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Test Case: [5, 3, 1, 2, 5, 1, 2] -> Critical at pos 2, pos 4, pos 5 (0-indexed)
    vector<int> nums = {5, 3, 1, 2, 5, 1, 2};
    ListNode* head = buildList(nums);

    vector<int> result = sol.nodesBetweenCriticalPoints(head);
    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
```
