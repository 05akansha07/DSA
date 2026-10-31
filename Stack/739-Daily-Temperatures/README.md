# 739. Daily Temperatures

**Difficulty:** Medium  
**Topics:** Array, Stack, Monotonic Stack  
**Language:** C++  

---

## Problem Statement

Given an array of integers `temperatures` represents the daily temperatures, return an array `answer` such that `answer[i]` is the number of days you have to wait after the $i^{\text{th}}$ day to get a warmer temperature. If there is no future day for which this is possible, keep `answer[i] == 0` instead.

---

## Examples

### Example 1:
- **Input:** `temperatures = [73, 74, 75, 71, 69, 72, 76, 73]`
- **Output:** `[1, 1, 4, 2, 1, 1, 0, 0]`

### Example 2:
- **Input:** `temperatures = [30, 40, 50, 60]`
- **Output:** `[1, 1, 1, 0]`

### Example 3:
- **Input:** `temperatures = [30, 60, 90]`
- **Output:** `[1, 1, 0]`

---

## Constraints

- $1 \le \text{temperatures.length} \le 10^5$
- $30 \le \text{temperatures}[i] \le 100$

---

## Intuition & Approach

### Monotonic Decreasing Stack

The problem asks for the distance to the **Next Greater Element** for each index in the array. A monotonic decreasing stack is well-suited for this:

1. **Stack Representation:**  
   Maintain a stack storing indices of days whose next warmer day has not yet been determined. Because elements waiting in the stack are strictly ordered by non-increasing temperatures, temperatures decrease from bottom to top.

2. **Processing Each Day ($i$):**  
   - Whenever the current day's temperature `temperatures[i]` exceeds the temperature at the index stored at `st.top()`, the current day $i$ is the closest warmer day for `prevDay = st.top()`.
   - Calculate days waited: `result[prevDay] = i - prevDay`.
   - Pop `prevDay` from the stack.
   - Continue resolving previous days until the stack is empty or `temperatures[i] <= temperatures[st.top()]`.

3. **Pushing Current Day:**  
   - Push index $i$ onto the stack to await a future warmer day.

4. **Default Unresolved Values:**  
   - Initializing `result` with zeros handles all days with no subsequent warmer day without extra cleanup passes.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  Each index is pushed onto the stack exactly once and popped at most once across the entire traversal, resulting in amortized $\mathcal{O}(1)$ operations per element.
- **Space Complexity:** $\mathcal{O}(N)$  
  In the worst-case scenario (e.g., strictly decreasing temperatures), the stack can hold up to $N$ indices.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st; // stores indices of unresolved days

        for (int i = 0; i < n; i++) {
            // While current day is warmer than the day waiting at stack top
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevDay = st.top();
                st.pop();
                result[prevDay] = i - prevDay; // days waited
            }
            // Current day waits for a warmer day in the future
            st.push(i);
        }

        return result;
    }
};

int main() {
    Solution solver;

    // Test Case 1 Expected: 1 1 4 2 1 1 0 0
    vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
    auto res1 = solver.dailyTemperatures(t1);
    cout << "Test 1: ";
    for (int x : res1) cout << x << " ";
    cout << "\n";

    // Test Case 2 Expected: 1 1 1 0
    vector<int> t2 = {30, 40, 50, 60};
    auto res2 = solver.dailyTemperatures(t2);
    cout << "Test 2: ";
    for (int x : res2) cout << x << " ";
    cout << "\n";

    return 0;
}
```
