#include <iostream>
#include <algorithm>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1 == 0 && need2 == 0) return 0;
        if(costBoth >= cost1 + cost2){
            return (1LL * cost1 * need1 + 1LL * cost2 * need2);
        }
        else {
            long long minimum = min(need1,need2);
            long long maximum = max(need1,need2);
            long long left = maximum - minimum;
            if(need1 > need2){
                return min(maximum * costBoth, minimum * costBoth + left * cost1);
            }
            else {
                return min(maximum * costBoth,minimum * costBoth + left * cost2);
            }
            
        }
    }
};

int main() {
    Solution solver;

    // Test Case 1: Expected: 3
    cout << "Test 1: " << solver.minimumCost(3, 2, 1, 3, 2) << endl;

    // Test Case 2: Expected: 22
    cout << "Test 2: " << solver.minimumCost(5, 4, 15, 2, 3) << endl;

    // Test Case 3: Expected: 0
    cout << "Test 3: " << solver.minimumCost(5, 4, 15, 0, 0) << endl;

    return 0;
}