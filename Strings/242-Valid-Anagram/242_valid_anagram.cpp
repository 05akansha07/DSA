#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        // Strings of unequal length cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Frequency counter for 26 lowercase English letters
        int freq[26] = {0};

        // Single pass: increment for s, decrement for t
        for (size_t i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        // Verify balance
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "anagram", "nagaram" -> Expected: true (1)
    cout << "Test 1: " << boolalpha << solver.isAnagram("anagram", "nagaram") << endl;

    // Test Case 2: "rat", "car" -> Expected: false (0)
    cout << "Test 2: " << boolalpha << solver.isAnagram("rat", "car") << endl;

    return 0;
}