# 2409. Count Days Spent Together

**Difficulty:** Easy  
**Topics:** Math, String  
**Language:** C++

---

## Problem Statement

Alice and Bob are traveling to Rome for separate business meetings.

You are given 4 strings `arriveAlice`, `leaveAlice`, `arriveBob`, and `leaveBob`. Alice will be in the city from the dates `arriveAlice` to `leaveAlice` (inclusive), while Bob will be in the city from the dates `arriveBob` to `leaveBob` (inclusive). Each will be a 5-character string in the format `"MM-DD"`, corresponding to the month and day of the date.

Return the **total number of days** that Alice and Bob are in Rome together.

You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: `[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]`.

---

## Examples

### Example 1:
- **Input:** `arriveAlice = "08-15"`, `leaveAlice = "08-18"`, `arriveBob = "08-16"`, `leaveBob = "08-19"`
- **Output:** `3`
- **Explanation:** Alice is in Rome from August 15 to August 18. Bob is in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is `3`.

### Example 2:
- **Input:** `arriveAlice = "10-01"`, `leaveAlice = "10-31"`, `arriveBob = "11-01"`, `leaveBob = "12-31"`
- **Output:** `0`
- **Explanation:** There is no day when Alice and Bob are in Rome together, so we return `0`.

---

## Constraints

- All dates are provided in the format `"MM-DD"`.
- Alice and Bob's arrival dates are earlier than or equal to their leaving dates.
- The given dates are valid dates of a non-leap year.

---

## Intuition & Approach

### 1D Interval Intersection via Day of Year Mapping

1. **Prefix Sum Mapping to 1D Space:**  
   Because months have varying lengths, comparing calendar dates directly can be error-prone. Instead, convert each `"MM-DD"` date into an absolute day of the year $[1..365]$:
   $$\text{dayOfYear} = \text{day} + \sum_{m=0}^{\text{month}-2} \text{daysInMonth}[m]$$

2. **1D Interval Intersection:**  
   Alice's trip is represented by $[\text{startAlice}, \text{endAlice}]$, and Bob's by $[\text{startBob}, \text{endBob}]$.  
   The overlapping interval is given by:
   $$\text{overlapStart} = \max(\text{startAlice}, \text{startBob})$$
   $$\text{overlapEnd} = \min(\text{endAlice}, \text{endBob})$$

3. **Counting Overlap Days:**  
   - If $\text{overlapStart} \le \text{overlapEnd}$, the number of shared days is $\text{overlapEnd} - \text{overlapStart} + 1$.
   - Otherwise, there is no intersection, yielding $0$ days.
   - This can be cleanly written as $\max(0, \text{overlapEnd} - \text{overlapStart} + 1)$.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$  
  Fixed string parsing of 5-character dates and at most 12 month lookups.
- **Space Complexity:** $\mathcal{O}(1)$  
  Uses a fixed 12-element lookup array and scalar integers.

---

## C++ Implementation

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
private:
    const vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int toDayOfYear(const string& date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int totalDays = day;
        for (int m = 0; m < month - 1; m++) {
            totalDays += daysInMonth[m];
        }
        return totalDays;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startAlice = toDayOfYear(arriveAlice);
        int endAlice = toDayOfYear(leaveAlice);
        int startBob = toDayOfYear(arriveBob);
        int endBob = toDayOfYear(leaveBob);

        int overlapStart = max(startAlice, startBob);
        int overlapEnd = min(endAlice, endBob);

        return max(0, overlapEnd - overlapStart + 1);
    }
};

int main() {
    Solution solver;

    // Test Case 1: "08-15" to "08-18" and "08-16" to "08-19" -> Expected: 3
    cout << "Test 1: " 
         << solver.countDaysTogether("08-15", "08-18", "08-16", "08-19") << endl;

    // Test Case 2: "10-01" to "10-31" and "11-01" to "12-31" -> Expected: 0
    cout << "Test 2: " 
         << solver.countDaysTogether("10-01", "10-31", "11-01", "12-31") << endl;

    return 0;
}
```
