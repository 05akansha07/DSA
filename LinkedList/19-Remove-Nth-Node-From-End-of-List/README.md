# 19. Remove Nth Node From End of List

**Difficulty:** Medium  
**Topics:** Linked List, Two Pointers  
**Language:** C++

---

## Problem Statement

Given the `head` of a linked list, remove the $n^{\text{th}}$ node from the end of the list and return its head.

---

## Examples

### Example 1:

```text
Original:  [1] ---> [2] ---> [3] ---> [4] ---> [5] ---> nullptr
                                       ^ (2nd from end)
Result:    [1] ---> [2] ---> [3] -------------> [5] ---> nullptr
```

- **Input:** `head = [1, 2, 3, 4, 5]`, `n = 2`
- **Output:** `[1, 2, 3, 5]`

### Example 2:

- **Input:** `head = [1]`, `n = 1`
- **Output:** `[]`

### Example 3:

- **Input:** `head = [1, 2]`, `n = 1`
- **Output:** `[1]`

---

## Constraints

- The number of nodes in the list is `sz`.
- $1 \le \text{sz} \le 30$
- $0 \le \text{Node.val} \le 100$
- $1 \le n \le \text{sz}$

---

## Intuition & Approach

### Two Pointers with a Dummy Node (One-Pass)

A two-pass approach first counts the length $L$ of the list and then deletes the $(L - n + 1)^{\text{th}}$ node from the start. We can achieve this in a **single pass** using two pointers spaced $n$ nodes apart:

1. **Dummy / Sentinel Node:**  
   Using a dummy node pointing to `head` simplifies edge cases (such as deleting the head node itself). It eliminates the need for separate conditional branches for `head` reassignment.

2. **Pointer Separation:**  
   - Position both `fast` and `slow` at the dummy node.
   - Advance `fast` forward by $n + 1$ steps.
   - The gap between `fast` and `slow` is now exactly $n$ nodes.

3. **Simultaneous Advance:**  
   - Move both `fast` and `slow` forward one node at a time until `fast` reaches `nullptr`.
   - When `fast` reaches `nullptr`, `slow` lands directly **before** the node to be removed.

4. **Deletion & Cleanup:**  
   - Update `slow->next = slow->next->next`.
   - Free the target node memory via `delete` to prevent memory leaks.
   - Return `dummy.next` as the updated list head.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(L)$  
  Where $L$ is the number of nodes in the list. The list is traversed once in a single pass.
- **Space Complexity:** $\mathcal{O}(1)$  
  Uses only two pointers and a stack-allocated sentinel node.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node simplifies edge cases like removing the head itself
        ListNode dele(0, head);
        ListNode* fast = &dele;
        ListNode* slow = &dele;

        // Move fast pointer n + 1 steps forward so that
        // the distance between fast and slow is exactly n nodes
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches nullptr
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow is now sitting right before the node to delete
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // Clean up allocated memory

        return dele.next;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
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
    cout << "[";
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) cout << ", ";
        curr = curr->next;
    }
    cout << "]" << endl;
}

int main() {
    Solution solver;

    // Test Case 1: [1, 2, 3, 4, 5], n = 2 -> Expected: [1, 2, 3, 5]
    ListNode* list1 = createList({1, 2, 3, 4, 5});
    cout << "Test 1 Original: ";
    printList(list1);
    list1 = solver.removeNthFromEnd(list1, 2);
    cout << "Test 1 After Removal: ";
    printList(list1);
    cout << "\n";

    // Test Case 2: [1], n = 1 -> Expected: []
    ListNode* list2 = createList({1});
    cout << "Test 2 Original: ";
    printList(list2);
    list2 = solver.removeNthFromEnd(list2, 1);
    cout << "Test 2 After Removal: ";
    printList(list2);
    cout << "\n";

    // Test Case 3: [1, 2], n = 1 -> Expected: [1]
    ListNode* list3 = createList({1, 2});
    cout << "Test 3 Original: ";
    printList(list3);
    list3 = solver.removeNthFromEnd(list3, 1);
    cout << "Test 3 After Removal: ";
    printList(list3);
    cout << "\n";

    return 0;
}
```
