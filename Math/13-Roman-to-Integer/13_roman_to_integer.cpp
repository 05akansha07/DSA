#include <iostream>
#include <string>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
private:
    inline int charToValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default:  return 0;
        }
    }

public:
    int romanToInt(const string& s) {
        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int currentVal = charToValue(s[i]);

            // If a smaller value precedes a larger value, subtract it
            if (i + 1 < n && currentVal < charToValue(s[i + 1])) {
                total -= currentVal;
            } else {
                total += currentVal;
            }
        }

        return total;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "III" -> Expected: 3
    cout << "Test 1: " << solver.romanToInt("III") << endl;

    // Test Case 2: "LVIII" -> Expected: 58
    cout << "Test 2: " << solver.romanToInt("LVIII") << endl;

    // Test Case 3: "MCMXCIV" -> Expected: 1994
    cout << "Test 3: " << solver.romanToInt("MCMXCIV") << endl;

    return 0;
}