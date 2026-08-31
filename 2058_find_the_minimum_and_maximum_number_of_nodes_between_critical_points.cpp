/**
 * Problem: LeetCode 2058 - Find the Minimum and Maximum Number of Nodes Between Critical Points
 * Description: Given a singly linked list, a critical point is defined as either a local maxima 
 *              or a local minima. Return an array of length 2 containing [minDistance, maxDistance].
 *              If there are fewer than 2 critical points, return [-1, -1].
 * 
 * Approach: Single-Pass Pointer Traversal (O(N) Time, O(1) Space)
 * 1. Maintain 'prev' (starts at head) and 'curr' (starts at head->next) with 1-based index 'ids = 1'.
 * 2. Traverse while curr->next != nullptr:
 *    - Check for local maxima: curr->val > prev->val && curr->val > curr->next->val
 *    - Check for local minima: curr->val < prev->val && curr->val < curr->next->val
 * 3. On critical point:
 *    - If first critical point found, record 'firstCritical = ids'.
 *    - If subsequent critical point, update minDistance = min(minDistance, ids - lastCritical).
 *    - Update lastCritical = ids.
 * 4. Advance prev = curr, curr = curr->next, and increment ids.
 * 5. Return [-1, -1] if fewer than 2 critical points exist, else [minDistance, lastCritical - firstCritical].
 * 
 * Time Complexity:  O(N) - Single pass through the linked list.
 * Space Complexity: O(1) - Constant extra space used.
 */

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

    // Test Case: [5, 3, 1, 2, 5, 1, 2] -> Critical at index 3 (val 1), index 5 (val 5), index 6 (val 1)
    // Expected: [1, 3]
    vector<int> nums = {5, 3, 1, 2, 5, 1, 2};
    ListNode* head = buildList(nums);

    vector<int> result = sol.nodesBetweenCriticalPoints(head);
    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}