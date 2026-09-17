# 206. Reverse Linked List

**Difficulty:** Easy  
**Topics:** Linked List, Recursion  
**Language:** C++

---

## Problem Statement

Given the `head` of a singly linked list, reverse the list, and return the reversed list.

---

## Examples

### Example 1:

```text
Original:  [1] ---> [2] ---> [3] ---> [4] ---> [5] ---> NULL
Reversed:  [5] ---> [4] ---> [3] ---> [2] ---> [1] ---> NULL
```

- **Input:** `head = [1, 2, 3, 4, 5]`
- **Output:** `[5, 4, 3, 2, 1]`

### Example 2:

```text
Original:  [1] ---> [2] ---> NULL
Reversed:  [2] ---> [1] ---> NULL
```

- **Input:** `head = [1, 2]`
- **Output:** `[2, 1]`

### Example 3:

- **Input:** `head = []`
- **Output:** `[]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 5000]$.
- $-5000 \le \text{Node.val} \le 5000$

---

## Follow-up

A linked list can be reversed either iteratively or recursively. Could you implement both?

---

## Intuition & Approach

### Three-Pointer Iterative Reversal

To reverse a singly linked list in-place without auxiliary memory, we reorient the `next` pointer of each node toward its predecessor:

1. **Pointers Maintained:**
   - `prev`: Tracks the previously processed node (initialized to `nullptr` because the original head becomes the tail pointing to `nullptr`).
   - `curr`: Tracks the node currently being processed (starts at `head`).
   - `nextNode`: Temporarily caches `curr->next` before breaking the forward connection.

2. **Step-by-Step State Transition:**
   For each iteration while `curr != nullptr`:
   - Store the next node: `nextNode = curr->next`
   - Invert pointer direction: `curr->next = prev`
   - Advance `prev`: `prev = curr`
   - Advance `curr`: `curr = nextNode`

3. **Termination:**
   When `curr` reaches `nullptr`, traversal is complete, and `prev` points to the new head of the reversed list.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  Traverses the linked list of $N$ nodes exactly once.
- **Space Complexity:** $\mathcal{O}(1)$  
  In-place reversal using pointer manipulation requires constant extra memory.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};

// Helper function to build a linked list from a vector
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

// Helper function to print a linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) cout << " -> ";
        curr = curr->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    Solution sol;

    // Test Case: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* head = buildList(nums);

    cout << "Original List: ";
    printList(head);

    ListNode* reversedHead = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead);

    return 0;
}
```
