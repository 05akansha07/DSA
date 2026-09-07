/**
 * Problem: LeetCode 876 - Middle of the Linked List
 * Source: https://leetcode.com/problems/middle-of-the-linked-list/
 * 
 * Problem Statement:
 * Given the head of a singly linked list, return the middle node of the linked list.
 * If there are two middle nodes, return the second middle node.
 * 
 * Approach: Fast and Slow Pointers (Floyd's Tortoise and Hare)
 * - Initialize two pointers, `slow` and `fast`, both starting at `head`.
 * - In each iteration of the loop:
 *     - Advance `slow` by 1 node: slow = slow->next
 *     - Advance `fast` by 2 nodes: fast = fast->next->next
 * - Because `fast` moves at double the speed of `slow`, when `fast` reaches 
 *   the end of the list (or moves past it), `slow` will be positioned at the exact middle.
 * - Loop Termination:
 *     - `fast != nullptr` prevents null pointer dereferencing on even-length lists.
 *     - `fast->next != nullptr` prevents null pointer dereferencing on odd-length lists.
 * 
 * Complexity Analysis:
 * - Time Complexity:  O(N) - A single pass over the linked list; `fast` reaches the end in N/2 steps.
 * - Space Complexity: O(1) - Constant auxiliary space, using only two pointer references.
 */

#include <iostream>

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

// Helper function to build a linked list from an array
ListNode* createList(const initializer_list<int>& values) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int val : values) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

// Helper function to print linked list from a given node
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
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