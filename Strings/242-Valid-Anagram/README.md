# 242. Valid Anagram

**Difficulty:** Easy  
**Topics:** Hash Table, String, Sorting  
**Language:** C++  

---

## Problem Statement

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

An **anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

---

## Examples

### Example 1:
- **Input:** `s = "anagram"`, `t = "nagaram"`
- **Output:** `true`

### Example 2:
- **Input:** `s = "rat"`, `t = "car"`
- **Output:** `false`

---

## Constraints

- $1 \le s.\text{length}, t.\text{length} \le 5 \times 10^4$
- `s` and `t` consist of lowercase English letters.

---

## Intuition & Approach

### Frequency Balance Array (Single-Pass Tracking)

1. **Length Check:**
   - Two strings of different lengths cannot have identical character distributions. If `s.length() != t.length()`, immediately return `false`.

2. **Fixed-Size Direct Address Table:**
   - Both strings are constrained to lowercase English letters (`'a'` through `'z'`), so a fixed-size integer array of length $26$ (`freq[26]`) is sufficient.
   - Hash maps (`std::unordered_map`) introduce unnecessary hashing and heap allocation overhead; an array indexed via `c - 'a'` provides direct $\mathcal{O}(1)$ random access.

3. **Combined Increment/Decrement Pass:**
   - Iterate through both strings simultaneously up to length $N$:
     - Increment `freq[s[i] - 'a']++`
     - Decrement `freq[t[i] - 'a']--`
   - If `t` is a valid permutation of `s`, every increment will be cancelled out by a corresponding decrement.

4. **Balance Verification:**
   - Traverse the $26$-element frequency array. If any count is non-zero (`count != 0`), the characters do not match in frequency $\to$ return `false`.
   - If all counts remain `0`, return `true`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  Where $N$ is the length of the string $s$. The strings are scanned in a single linear pass $\mathcal{O}(N)$, followed by a constant scan of $26$ entries ($\mathcal{O}(1)$).
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space  
  Uses an array of fixed size $26$ regardless of input size $N$.

---

## C++ Implementation

```cpp
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
```
