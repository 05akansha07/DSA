# 1807. Evaluate the Bracket Pairs of a String

**Difficulty:** Medium  
**Topics:** Hash Table, String  
**Language:** C++

---

## Problem Statement

You are given a string `s` that contains some bracket pairs, with each pair containing a non-empty key.

For example, in the string `"(name)is(age)yearsold"`, there are two bracket pairs that contain the keys `"name"` and `"age"`.

You know the values of a wide range of keys. This is represented by a 2D string array `knowledge` where each `knowledge[i] = [key_i, value_i]` indicates that key `key_i` has a value of `value_i`.

You are tasked to evaluate all of the bracket pairs. When you evaluate a bracket pair that contains some key `key_i`, you will:
- Replace `key_i` and the bracket pair with the key's corresponding `value_i`.
- If you do not know the value of the key, you will replace `key_i` and the bracket pair with a question mark `"?"` (without the quotation marks).

Each key will appear at most once in your `knowledge`. There will not be any nested brackets in `s`.

Return the resulting string after evaluating all of the bracket pairs.

---

## Examples

### Example 1:
- **Input:** `s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]`
- **Output:** `"bobistwoyearsold"`
- **Explanation:**
  - The key `"name"` has a value of `"bob"`, so replace `"(name)"` with `"bob"`.
  - The key `"age"` has a value of `"two"`, so replace `"(age)"` with `"two"`.

### Example 2:
- **Input:** `s = "hi(name)", knowledge = [["a","b"]]`
- **Output:** `"hi?"`
- **Explanation:** As you do not know the value of the key `"name"`, replace `"(name)"` with `"?"`.

### Example 3:
- **Input:** `s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]`
- **Output:** `"yesyesyesaaa"`
- **Explanation:** The same key can appear multiple times. The key `"a"` has a value of `"yes"`, so replace all occurrences of `"(a)"` with `"yes"`. Literal `'a'` characters outside brackets remain unaffected.

---

## Constraints

- $1 \le \text{s.length} \le 10^5$
- $0 \le \text{knowledge.length} \le 10^5$
- $\text{knowledge}[i].\text{length} == 2$
- $1 \le \text{key}_i.\text{length}, \text{value}_i.\text{length} \le 10$
- `s` consists of lowercase English letters and round brackets `'('` and `')'`.
- Every open bracket `'('` in `s` has a corresponding close bracket `')'`.
- The key in each bracket pair of `s` will be non-empty.
- There will not be any nested bracket pairs in `s`.
- $\text{key}_i$ and $\text{value}_i$ consist of lowercase English letters.
- Each $\text{key}_i$ in `knowledge` is unique.

---

## Intuition & Approach

### Hash Map Lookup with Linear String Parsing

The problem requires single-pass string parsing combined with constant-time dictionary lookups:

1. **Preprocess Knowledge into a Hash Map:**  
   Convert `knowledge` into an `unordered_map<string, string>` for $\mathcal{O}(1)$ average key lookups. Using `dict.reserve(knowledge.size())` prevents rehashing overhead during insertion.

2. **Parsing with State Tracking:**  
   Iterate through characters of `s` maintaining a boolean flag `inBracket`:
   - Encounter `'('`: Set `inBracket = true` and reset `currentKey`.
   - Inside brackets: Append characters to `currentKey`.
   - Encounter `')'`: Set `inBracket = false`. Query `dict` for `currentKey`:
     - If found: append `dict[currentKey]` to `result`.
     - If not found: append `'?'` to `result`.
   - Regular characters outside brackets: Append directly to `result`.

Because brackets are guaranteed to be non-nested and valid, this straightforward state machine processes the string cleanly in $\mathcal{O}(|s|)$ time.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(|s| + K \cdot L)$  
  Where $|s|$ is the length of string `s`, $K$ is the number of pairs in `knowledge`, and $L \le 10$ is the maximum key/value length. Building the hash map takes $\mathcal{O}(K \cdot L)$ time, and iterating through `s` with map lookups takes $\mathcal{O}(|s|)$ average time.
- **Space Complexity:** $\mathcal{O}(K \cdot L)$  
  Storing $K$ key-value pairs in the `unordered_map`.

---

## C++ Implementation

```cpp
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
```
