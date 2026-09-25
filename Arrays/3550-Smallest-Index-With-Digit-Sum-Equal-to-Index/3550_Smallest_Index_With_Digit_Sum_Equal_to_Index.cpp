#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            if (getDigitSum(nums[i]) == i) {
                return i; // First match is guaranteed to be the smallest index
            }
        }
        return -1;
    }
};
int main()
{
    Solution solver;

    // Test Case 1: [1, 3, 2] -> Expected: 2
    vector<int> nums1 = {1, 3, 2};
    cout << "Test 1 Output: " << solver.smallestIndex(nums1)<< endl;

    // Test Case 2: [1, 10, 11] -> Expected: 1
    vector<int> nums2 = {1, 10, 11};
    cout << "Test 2 Output: " << solver.smallestIndex(nums2)<< endl;

    // Test Case 3: [1, 2, 3] -> Expected: -1
    vector<int> nums3 = {1, 2, 3};
    cout << "Test 3 Output: " << solver.smallestIndex(nums3)<< endl;

    // Test Case 4: Element 0 at index 0 -> Expected: 0
    vector<int> nums4 = {0, 5, 9};
    cout << "Test 4 Output: " << solver.smallestIndex(nums4)<< endl;

    return 0;
}