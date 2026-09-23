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
        // Dele node simplifies edge cases like removing the head itself
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