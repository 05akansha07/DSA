/**
 * Problem: LeetCode 206 - Reverse Linked List
 * Description: Given the head of a singly linked list, reverse the list, 
 *              and return the reversed list.
 * 
 * Approach: Iterative 3-Pointer Technique
 * 1. Initialize 'prev' to nullptr and 'curr' to head.
 * 2. Traverse while curr is not nullptr:
 *    - Save curr->next into nextNode (prevents losing the rest of the list).
 *    - Reverse the link: curr->next = prev.
 *    - Move prev to curr.
 *    - Move curr to nextNode.
 * 3. Return 'prev' as the new head of the reversed list.
 * 
 * Time Complexity:  O(N) - Single pass through the list.
 * Space Complexity: O(1) - In-place reversal using constant extra space.
 */

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
