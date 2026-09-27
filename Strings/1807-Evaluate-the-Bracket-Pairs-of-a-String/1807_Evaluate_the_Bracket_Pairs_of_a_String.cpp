#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        dict.reserve(knowledge.size());
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }

        string result = "";
        string currentKey = "";
        bool inBracket = false;

        for (char ch : s) {
            if (ch == '(') {
                inBracket = true;
                currentKey.clear();
            } 
            else if (ch == ')') {
                inBracket = false;
                auto it = dict.find(currentKey);
                if (it != dict.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
            } 
            else {
                if (inBracket) {
                    currentKey += ch;
                } else {
                    result += ch;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Standard replacement
    string s1 = "(name)is(age)yearsold";
    vector<vector<string>> k1 = {{"name", "bob"}, {"age", "two"}};
    cout << "Test 1: " << solver.evaluate(s1, k1) << "\n";

    // Test Case 2: Missing key -> '?'
    string s2 = "hi(name)";
    vector<vector<string>> k2 = {{"a", "b"}};
    cout << "Test 2: " << solver.evaluate(s2, k2) << "\n";

    // Test Case 3: Repeated key and literal suffix
    string s3 = "(a)(a)(a)aaa";
    vector<vector<string>> k3 = {{"a", "yes"}};
    cout << "Test 3: " << solver.evaluate(s3, k3) << "\n";

    return 0;
}