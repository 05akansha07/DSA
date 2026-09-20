#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            int charWeight = 26 - (s[i] - 'a');
            int StringPos = i + 1;
            total += charWeight * StringPos;
        }
        return total;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    string s1 = "abc";
    int result1 = solution.reverseDegree(s1);
    cout << "Test Case 1:" << endl;
    cout << "Input: s = \"" << s1 << "\"" << endl;
    cout << "Output: " << result1 << endl;
    cout << "------------------------------------" << endl;

    // Test Case 2
    string s2 = "zaza";
    int result2 = solution.reverseDegree(s2);
    cout << "Test Case 2:" << endl;
    cout << "Input: s = \"" << s2 << "\"" << endl;
    cout << "Output: " << result2 << endl;
    cout << "------------------------------------" << endl;

    return 0;
}