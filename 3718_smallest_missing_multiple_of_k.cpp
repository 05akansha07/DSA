/**
 * Problem: LeetCode 3718 - Smallest Missing Multiple of K
 * Description: Given an array of integers 'nums' and an integer 'k', return the 
 *              smallest positive multiple of 'k' that is missing from 'nums'.
 * 
 * Approach:
 * 1. Insert all elements of 'nums' into an unordered_set for O(1) lookups.
 * 2. Generate positive multiples of k (k, 2k, 3k, ...).
 * 3. Return the first multiple not found in the set.
 * 
 * Time Complexity:  O(N + M), where N is the size of nums and M is the number of multiples checked.
 * Space Complexity: O(N) to store the elements in the hash set.
 */
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(),nums.end());
        int target=k;
        while(s.count(target)){
            target+=k;
        }
        return target;
    }
};
int main(){
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {8, 2, 3, 4, 6};
    int k1 = 2;
    cout << "Test 1 Output: " << sol.missingMultiple(nums1, k1) << " (Expected: 10)" << endl;

    // Test Case 2
    vector<int> nums2 = {1, 4, 7, 10, 15};
    int k2 = 5;
    cout << "Test 2 Output: " << sol.missingMultiple(nums2, k2) << " (Expected: 5)" << endl;

    return 0;
}