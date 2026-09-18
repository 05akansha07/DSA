#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Remainder frequency array for remainders 0 to k - 1
        vector<int> remainder_count(k, 0);
        
        // Base case: prefix sum of 0 has remainder 0 occurring once
        remainder_count[0] = 1;

        int current_sum = 0;
        int total_subarrays = 0;

        for (int num : nums) {
            current_sum += num;

            // Normalize negative remainders in C++: ((val % k) + k) % k
            int rem = ((current_sum % k) + k) % k;

            // Every time this remainder was seen before, it forms a valid subarray
            total_subarrays += remainder_count[rem];
            
            // Increment the occurrence of the current remainder
            remainder_count[rem]++;
        }

        return total_subarrays;
    }
};

int main() {
    Solution solver;

    // Test Case 1
    vector<int> nums1 = {4, 5, 0, -2, -3, 1};
    int k1 = 5;
    cout << "Test 1: " << solver.subarraysDivByK(nums1, k1)<< endl;

    // Test Case 2
    vector<int> nums2 = {5};
    int k2 = 9;
    cout << "Test 2: " << solver.subarraysDivByK(nums2, k2)<< endl;

    // Test Case 3: Handling negatives
    vector<int> nums3 = {-1, 2, 9};
    int k3 = 2;
    cout << "Test 3: " << solver.subarraysDivByK(nums3, k3)<< endl;

    return 0;
}