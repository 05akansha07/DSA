#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int currentDepth = 0;
        int maxDepthVal = 0;

        for (char ch : s) {
            if (ch == '(') {
                currentDepth++;
                maxDepthVal = max(maxDepthVal, currentDepth);
            } else if (ch == ')') {
                currentDepth--;
            }
        }

        return maxDepthVal;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "(1+(2*3)+((8)/4))+1" -> Expected: 3
    string s1 = "(1+(2*3)+((8)/4))+1";
    cout << "Test 1 Output: " << solver.maxDepth(s1)<< endl;

    // Test Case 2: "(1)+((2))+(((3)))" -> Expected: 3
    string s2 = "(1)+((2))+(((3)))";
    cout << "Test 2 Output: " << solver.maxDepth(s2)<< endl;

    // Test Case 3: "()(())((()()))" -> Expected: 3
    string s3 = "()(())((()()))";
    cout << "Test 3 Output: " << solver.maxDepth(s3)<< endl;

    // Test Case 4: No parentheses "1+2*3" -> Expected: 0
    string s4 = "1+2*3";
    cout << "Test 4 Output: " << solver.maxDepth(s4)<< endl;

    return 0;
}