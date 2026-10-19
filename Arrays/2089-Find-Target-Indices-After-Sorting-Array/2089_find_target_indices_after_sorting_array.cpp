#include <iostream>
#include <vector>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lessCount = 0;
        int targetCount = 0;

        for (int num : nums) {
            if (num < target) {
                lessCount++;
            } else if (num == target) {
                targetCount++;
            }
        }

        vector<int> result;
        result.reserve(targetCount);

        for (int i = 0; i < targetCount; i++) {
            result.push_back(lessCount + i);
        }

        return result;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1,2,5,2,3], target = 2 -> Expected: [1, 2]
    vector<int> t1 = {1, 2, 5, 2, 3};
    vector<int> res1 = solver.targetIndices(t1, 2);
    cout << "Test 1: ";
    for (int idx : res1) cout << idx << " ";
    cout << "\n";

    // Test Case 2: [1,2,5,2,3], target = 3 -> Expected: [3]
    vector<int> t2 = {1, 2, 5, 2, 3};
    vector<int> res2 = solver.targetIndices(t2, 3);
    cout << "Test 2: ";
    for (int idx : res2) cout << idx << " ";
    cout << "\n";

    // Test Case 3: [1,2,5,2,3], target = 4 -> Expected: []
    vector<int> t3 = {1, 2, 5, 2, 3};
    vector<int> res3 = solver.targetIndices(t3, 4);
    cout << "Test 3: ";
    for (int idx : res3) cout << idx << " ";
    cout << "(empty)\n";

    return 0;
}