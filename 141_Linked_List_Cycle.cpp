/**
 * Problem: LeetCode 141 - Linked List Cycle
 * Source: https://leetcode.com/problems/linked-list-cycle/
 * 
 * Problem Statement:
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 * 
 * Approach: Floyd's Cycle-Finding Algorithm (Tortoise and Hare)
 * - Use two pointers, `slow` and `fast`, both starting at `head`.
 * - `slow` advances 1 step at a time; `fast` advances 2 steps at a time.
 * - If there is no cycle, `fast` (or `fast->next`) will eventually reach nullptr.
 * - If a cycle exists, `fast` will enter the loop and reduce the gap to `slow`
 *   by 1 node per iteration until `slow == fast`.
 * 
 * Complexity Analysis:
 * - Time Complexity:  O(N) - If no cycle, fast reaches end in N/2 steps. 
 *                            If cycle exists, fast catches slow within one full loop cycle.
 * - Space Complexity: O(1) - Constant memory overhead using only two pointer variables.
 */

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