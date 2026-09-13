# 141. Linked List Cycle

**Difficulty:** Easy  
**Topics:** Hash Table, Linked List, Two Pointers  
**Language:** C++

---

## Problem Statement

Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. **Note that `pos` is not passed as a parameter.**

Return `true` if there is a cycle in the linked list. Otherwise, return `false`.

---

## Examples

### Example 1:

```text
3 ---> 2 ---> 0 ---> -4
       ^               |
       |---------------|
```

- **Input:** `head = [3, 2, 0, -4]`, `pos = 1`
- **Output:** `true`
- **Explanation:** There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

### Example 2:

```text
1 ---> 2
^      |
|------|
```

- **Input:** `head = [1, 2]`, `pos = 0`
- **Output:** `true`
- **Explanation:** There is a cycle in the linked list, where the tail connects to the 0th node.

### Example 3:

```text
1 ---> nullptr
```

- **Input:** `head = [1]`, `pos = -1`
- **Output:** `false`
- **Explanation:** There is no cycle in the linked list.

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^4]$.
- $-10^5 \le \text{Node.val} \le 10^5$
- `pos` is `-1` or a valid index in the linked list.

---

## Follow-up

Can you solve it using $\mathcal{O}(1)$ (i.e., constant) memory?

---

## Intuition & Approach

### Floyd's Cycle-Finding Algorithm (Tortoise and Hare)

A brute-force solution uses a hash set to store visited node pointers, requiring $\mathcal{O}(N)$ extra space. To achieve the follow-up requirement of $\mathcal{O}(1)$ memory, we use **Floyd's Cycle Detection Algorithm**:

1. **Two Pointers:**
   - Initialize two pointers at `head`: `slow` and `fast`.
   - In each step:
     - `slow` moves forward by **1 node**: `slow = slow->next`.
     - `fast` moves forward by **2 nodes**: `fast = fast->next->next`.

2. **Cycle Collision:**
   - If there is **no cycle**, `fast` (or `fast->next`) will eventually reach `nullptr`, terminating the traversal.
   - If there is a **cycle**, `fast` enters the loop first, followed by `slow`. Because `fast` gains on `slow` by exactly 1 node per iteration, the relative distance between them decreases by 1 in each step. Consequently, `fast` is guaranteed to catch up to `slow` without jumping over it.

3. **Termination Condition:**
   - If `slow == fast`, a cycle is detected $\rightarrow$ return `true`.
   - If `fast == nullptr || fast->next == nullptr`, list end reached $\rightarrow$ return `false`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  - If there is no cycle, `fast` reaches the end in $N/2$ iterations $\rightarrow \mathcal{O}(N)$.  
  - If there is a cycle of length $C$, `fast` catches `slow` within $\mathcal{O}(N)$ steps.
- **Space Complexity:** $\mathcal{O}(1)$  
  Only two pointer variables (`slow` and `fast`) are maintained, satisfying the constant memory constraint.

---

## C++ Implementation

```cpp
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            // Pointers collided: cycle confirmed
            if (slow == fast) {
                return true;
            }
        }

        // Fast reached a dead end: no cycle exists
        return false;
    }
};

int main() {
    Solution sol;

    // Test Case 1: List with a cycle [3 -> 2 -> 0 -> -4 -> (back to 2)]
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Cycle back to node2

    cout << "Test 1 (Has Cycle): " << (sol.hasCycle(node1) ? "true" : "false") << endl;

    // Test Case 2: List without a cycle [1 -> 2 -> nullptr]
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    a->next = b;

    cout << "Test 2 (No Cycle): " << (sol.hasCycle(a) ? "true" : "false") << endl;

    return 0;
}
```
