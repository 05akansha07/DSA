#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n, 0);
        int depth = 0;

        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                depth++;
                ans[i] = depth % 2;
            } else {
                ans[i] = depth % 2;
                depth--;
            }
        }

        return ans;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "(()())"
    string seq1 = "(()())";
    vector<int> res1 = solver.maxDepthAfterSplit(seq1);
    cout << "Test 1 Output: [";
    for (size_t i = 0; i < res1.size(); i++) {
        cout << res1[i] << (i + 1 < res1.size() ? ", " : "");
    }
    cout << "]\n";

    // Test Case 2: "()(())()"
    string seq2 = "()(())()";
    vector<int> res2 = solver.maxDepthAfterSplit(seq2);
    cout << "Test 2 Output: [";
    for (size_t i = 0; i < res2.size(); i++) {
        cout << res2[i] << (i + 1 < res2.size() ? ", " : "");
    }
    cout << "]\n";

    return 0;
}