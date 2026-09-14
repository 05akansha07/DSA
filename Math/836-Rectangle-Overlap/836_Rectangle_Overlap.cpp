#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec = [x1, y1, x2, y2]
        // An overlap with positive area exists iff both 1D intervals overlap
        bool overlapX = max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]);
        bool overlapY = max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);

        return overlapX && overlapY;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Standard overlap
    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};
    cout << "Test 1: " << (solver.isRectangleOverlap(rec1, rec2) ? "true" : "false") << endl;

    // Test Case 2: Touching along an edge (Area = 0)
    vector<int> rec3 = {0, 0, 1, 1};
    vector<int> rec4 = {1, 0, 2, 1};
    cout << "Test 2: " << (solver.isRectangleOverlap(rec3, rec4) ? "true" : "false") << endl;

    // Test Case 3: Completely disjoint
    vector<int> rec5 = {0, 0, 1, 1};
    vector<int> rec6 = {2, 2, 3, 3};
    cout << "Test 3: " << (solver.isRectangleOverlap(rec5, rec6) ? "true" : "false") << endl;

    return 0;
}