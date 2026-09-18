#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_counts;
        
        // Base case: a prefix sum of 0 has occurred once (before considering any elements)
        prefix_counts[0] = 1;

        int current_sum = 0;
        int total_count = 0;

        for (int num : nums) {
            current_sum += num;

            // Check if (current_sum - k) exists in our map
            int needed = current_sum - k;
            if (prefix_counts.find(needed) != prefix_counts.end()) {
                total_count += prefix_counts[needed];
            }

            // Record this current prefix sum in the frequency map
            prefix_counts[current_sum]++;
        }

        return total_count;
    }
};

int main() {
    Solution solver;

    vector<int> nums1 = {1, 1, 1};
    cout << "Test 1: " << solver.subarraySum(nums1, 2) << endl;

    vector<int> nums2 = {1, 2, 3};
    cout << "Test 2: " << solver.subarraySum(nums2, 3) << endl;

    vector<int> nums3 = {1, -1, 0};
    cout << "Test 3: " << solver.subarraySum(nums3, 0) << endl;

    return 0;
}