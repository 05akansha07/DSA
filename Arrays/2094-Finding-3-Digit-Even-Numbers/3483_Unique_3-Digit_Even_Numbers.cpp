#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }

        int count = 0;
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            vector<int> req(10, 0);
            req[d1]++;
            req[d2]++;
            req[d3]++;

            if (freq[d1] >= req[d1] && freq[d2] >= req[d2] && freq[d3] >= req[d3]) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution solver;

    // Test Case 1
    vector<int> digits1 = {1, 2, 3, 4};
    cout << "Test Case 1: " << solver.totalNumbers(digits1) << endl;

    // Test Case 2
    vector<int> digits2 = {0, 2, 2};
    cout << "Test Case 2: " << solver.totalNumbers(digits2) << endl;

    // Test Case 3
    vector<int> digits3 = {6, 6, 6};
    cout << "Test Case 3: " << solver.totalNumbers(digits3) << endl;

    // Test Case 4
    vector<int> digits4 = {1, 3, 5};
    cout << "Test Case 4: " << solver.totalNumbers(digits4) << endl;

    return 0;
}