# 876. Middle of the Linked List

**Difficulty:** Easy  
**Topics:** Linked List, Two Pointers  
**Language:** C++

---

## Problem Statement

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the **second middle node**.

---

## Examples

### Example 1:
- **Input:** `head = [1, 2, 3, 4, 5]`
- **Output:** `[3, 4, 5]`
- **Explanation:** The middle node of the list is node 3.

### Example 2:
- **Input:** `head = [1, 2, 3, 4, 5, 6]`
- **Output:** `[4, 5, 6]`
- **Explanation:** Since the list has two middle nodes with values 3 and 4, we return the second one (node 4).

---

## Constraints

- The number of nodes in the list is in the range $[1, 100]$.
- $1 \le \text{Node.val} \le 100$

---

## Intuition & Approach

### Two Pointers: Floyd's Tortoise and Hare

Instead of counting nodes in a first pass and traversing half the count in a second pass, we can locate the target middle node in a **single pass** using two pointers moving at different speeds:

1. **Pointer Speed Difference:**
   - Both `slow` and `fast` pointers start at `head`.
   - In each cycle of the traversal:
     - `slow = slow->next` (moves $1$ step forward)
     - `fast = fast->next->next` (moves $2$ steps forward)
   - Because `fast` moves at twice the rate of `slow`, by the time `fast` reaches the end of the linked list, `slow` will naturally be positioned at the middle.

2. **Parity Analysis:**
   - **Odd Length ($2k + 1$ nodes):**
     - `fast` begins at index $0$ and advances through indices $0 \to 2 \to 4 \dots \to 2k$.
     - When `fast` reaches index $2k$ (the last valid node, so `fast->next == nullptr`), `slow` has advanced $k$ times to index $k$.
     - Index $k$ is the exact unique middle node.
   - **Even Length ($2k$ nodes):**
     - `fast` advances through indices $0 \to 2 \to 4 \dots \to 2k$.
     - When `fast` advances past the last node ($2k - 1$) and lands on `nullptr` (`fast == nullptr`), `slow` has taken $k$ steps to index $k$.
     - Index $k$ is precisely the **second middle node** (0-indexed).

3. **Termination Condition:**
   - Continue iterating while `fast != nullptr && fast->next != nullptr`.
   - Returning `slow` immediately yields the desired middle node.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  A single pass over the linked list. The loop executes $\lfloor N / 2 \rfloor$ times.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Only two pointer references (`slow` and `fast`) are maintained.

---

## C++ Implementation

```cpp
#include <iostream>
#include <initializer_list>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse while fast can take two full forward steps
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

// Helper function to build a linked list from an initializer list
ListNode* createList(const initializer_list<int>& values) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int val : values) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

// Helper function to print linked list starting from a given node
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << "\n";
}

int main() {
    Solution sol;

    // Test Case 1: Odd number of nodes [1, 2, 3, 4, 5]
    ListNode* list1 = createList({1, 2, 3, 4, 5});
    ListNode* mid1 = sol.middleNode(list1);
    cout << "Test 1 (Odd Length) Output from middle: ";
    printList(mid1); // Expected: 3 -> 4 -> 5

    // Test Case 2: Even number of nodes [1, 2, 3, 4, 5, 6]
    ListNode* list2 = createList({1, 2, 3, 4, 5, 6});
    ListNode* mid2 = sol.middleNode(list2);
    cout << "Test 2 (Even Length) Output from middle: ";
    printList(mid2); // Expected: 4 -> 5 -> 6

    return 0;
}
```
