# 3789. Minimum Cost to Acquire Required Items

**Difficulty:** Medium

**Topics:** Math, Greedy

**Language:** C++

## Problem Statement

You are given five integers `cost1`, `cost2`, `costBoth`, `need1`, and `need2`.

There are three types of items available:

* An item of **type 1** costs `cost1` and contributes $1$ unit to the type 1 requirement only.

* An item of **type 2** costs `cost2` and contributes $1$ unit to the type 2 requirement only.

* An item of **type 3** costs `costBoth` and contributes $1$ unit to **both** type 1 and type 2 requirements.

You must collect enough items so that the total contribution toward type 1 is at least `need1` and the total contribution toward type 2 is at least `need2`.

Return an integer representing the **minimum possible total cost** to achieve these requirements.

## Examples

### Example 1:

* **Input:** `cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2`

* **Output:** `3`

* **Explanation:**
  After buying three type 3 items, which cost $3 \times 1 = 3$, the total contribution to type 1 is $3 \ (\ge \text{need1} = 3)$ and to type 2 is $3 \ (\ge \text{need2} = 2)$.
  Any other valid combination would cost more, so the minimum total cost is `3`.

### Example 2:

* **Input:** `cost1 = 5, cost2 = 4, costBoth = 15, need1 = 2, need2 = 3`

* **Output:** `22`

* **Explanation:**
  We buy $\text{need1} = 2$ items of type 1 and $\text{need2} = 3$ items of type 2: $2 \times 5 + 3 \times 4 = 10 + 12 = 22$.

### Example 3:

* **Input:** `cost1 = 5, cost2 = 4, costBoth = 15, need1 = 0, need2 = 0`

* **Output:** `0`

* **Explanation:**
  Since no items are required ($\text{need1} = \text{need2} = 0$), we buy nothing and pay `0`.

## Constraints

* $1 \le \text{cost1}, \text{cost2}, \text{costBoth} \le 10^6$

* $0 \le \text{need1}, \text{need2} \le 10^9$

## Intuition & Approach

### Case Analysis & Greedy Cost Comparison

The problem asks for the minimum cost to fulfill both `need1` and `need2`. We can analyze the optimal decision by comparing the cost efficiency of individual items versus combo items:

1. **Base Check:**
   If $\text{need1} = 0$ and $\text{need2} = 0$, no items are needed, so the minimum cost is $0$.

2. **Case 1: Combo Item is Inefficient ($\text{costBoth} \ge \text{cost1} + \text{cost2}$)**
   If buying a type 3 item costs as much as or more than buying a type 1 and a type 2 item separately, buying combo items never offers a cost advantage.
   We fulfill each requirement independently using individual items:
   

   $$
   \text{Total Cost} = (1\text{LL} \times \text{cost1} \times \text{need1}) + (1\text{LL} \times \text{cost2} \times \text{need2})
   $$

3. **Case 2: Combo Item is Cheaper than Separate Items ($\text{costBoth} < \text{cost1} + \text{cost2}$)**
   In this scenario, type 3 items offer a discount for overlap.
   Let $\text{minimum} = \min(\text{need1}, \text{need2})$ and $\text{maximum} = \max(\text{need1}, \text{need2})$.
   The shared requirement ($\text{minimum}$) should be fulfilled using $\text{minimum}$ type 3 items at cost $\text{minimum} \times \text{costBoth}$.
   
   For the remaining excess requirement $\text{left} = \text{maximum} - \text{minimum}$, we compare two options:
   * **Option A:** Fulfill the remaining $\text{left}$ using individual items of the larger requirement's type ($\text{left} \times \text{cost1}$ or $\text{left} \times \text{cost2}$).
   * **Option B:** Continue buying type 3 items up to $\text{maximum}$ count ($\text{maximum} \times \text{costBoth}$), which over-satisfies the smaller requirement if $\text{costBoth}$ is cheaper than even the single individual item cost.

   We return $\min(\text{Option A}, \text{Option B})$.

### Integer Overflow Prevention

With $\text{need1}, \text{need2} \le 10^9$ and costs up to $10^6$, intermediate multiplications can reach $10^{15}$, which exceeds standard 32-bit `int` ranges. Converting inputs/intermediate values to `long long` (or using `1LL` cast) ensures no overflow occurs.

## Complexity Analysis

* **Time Complexity:** $\mathcal{O}(1)$
  Executes constant time arithmetic calculations and basic condition branches.

* **Space Complexity:** $\mathcal{O}(1)$ auxiliary space
  Uses a fixed set of scalar variables.

## C++ Implementation

```
#include <iostream>
#include <algorithm>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (need1 == 0 && need2 == 0) return 0;
        
        if (costBoth >= cost1 + cost2) {
            return (1LL * cost1 * need1 + 1LL * cost2 * need2);
        } else {
            long long minimum = min(need1, need2);
            long long maximum = max(need1, need2);
            long long left = maximum - minimum;
            
            if (need1 > need2) {
                return min(maximum * costBoth, minimum * costBoth + left * cost1);
            } else {
                return min(maximum * costBoth, minimum * costBoth + left * cost2);
            }
        }
    }
};

int main() {
    Solution solver;

    // Test Case 1: Expected: 3
    cout << "Test 1: " << solver.minimumCost(3, 2, 1, 3, 2) << endl;

    // Test Case 2: Expected: 22
    cout << "Test 2: " << solver.minimumCost(5, 4, 15, 2, 3) << endl;

    // Test Case 3: Expected: 0
    cout << "Test 3: " << solver.minimumCost(5, 4, 15, 0, 0) << endl;

    return 0;
}

```
