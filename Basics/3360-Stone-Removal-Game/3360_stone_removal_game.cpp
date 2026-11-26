#include <iostream>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool canAliceWin(int n) {
        int stonesToRemove = 10;
        bool aliceTurn = true;

        while (n >= stonesToRemove) {
            n -= stonesToRemove;
            stonesToRemove--;
            aliceTurn = !aliceTurn;
        }

        // The player whose turn it is when n < stonesToRemove loses
        return !aliceTurn;
    }
};

int main() {
    Solution solver;

    // Test Case 1: n = 12 -> Expected: 1 (true)
    cout << "Test 1: " << solver.canAliceWin(12) << " | Expected: 1\n";

    // Test Case 2: n = 1 -> Expected: 0 (false)
    cout << "Test 2: " << solver.canAliceWin(1) << " | Expected: 0\n";

    // Test Case 3: n = 19 (10 + 9) -> Alice takes 10 (9 left), Bob takes 9 (0 left), Alice needs 8 -> Expected: 0 (false)
    cout << "Test 3: " << solver.canAliceWin(19) << " | Expected: 0\n";

    return 0;
}
