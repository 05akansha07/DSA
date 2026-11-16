1524. Number of Sub-arrays With Odd Sum

Difficulty: Medium

Topics: Array, Math, Dynamic Programming, Prefix Sum

Language: C++

Problem Statement

Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo $10^9 + 7$.

Examples

Example 1:

Input: arr = [1, 3, 5]

Output: 4

Explanation:

All subarrays are [[1], [1, 3], [1, 3, 5], [3], [3, 5], [5]].

Their respective sums are [1, 4, 9, 3, 8, 5].

The odd sums are [1, 9, 3, 5], so the answer is 4.

Example 2:

Input: arr = [2, 4, 6]

Output: 0

Explanation: All subarrays consist solely of even integers, so every subarray sum is even.

Example 3:

Input: arr = [1, 2, 3, 4, 5, 6, 7]

Output: 16

Constraints

$1 \le \text{arr.length} \le 10^5$

$1 \le \text{arr}[i] \le 100$

Intuition & Approach

Prefix Sum Parity Tracking

Let $P[i]$ denote the prefix sum of the first $i$ elements ($P[0] = 0$). The sum of a subarray from index $l + 1$ to $r$ is:

$$\text{sum}(l+1 \dots r) = P[r] - P[l]$$

Parity Condition for Odd Subarray Sums:

The difference $P[r] - P[l]$ is odd if and only if $P[r]$ and $P[l]$ have opposite parities:

If $P[r]$ is odd, we must pair it with any previous prefix $P[l]$ ($l < r$) that is even.

If $P[r]$ is even, we must pair it with any previous prefix $P[l]$ ($l < r$) that is odd.

Single-Pass State Counters:

Maintain two running frequency counters:

evenCount: Number of prefix sums seen so far with even parity (initialized to 1 to represent the empty prefix $P[0] = 0$).

oddCount: Number of prefix sums seen so far with odd parity (initialized to 0).

Track the current prefix parity using bitwise XOR:


$$\text{prefixParity} \oplus= (\text{num} \ \& \ 1)$$

At each step:

If prefixParity == 1 (odd): add evenCount to the total and increment oddCount.

If prefixParity == 0 (even): add oddCount to the total and increment evenCount.

Subtract $\text{MOD} = 10^9 + 7$ whenever totalOddSubarrays >= MOD to avoid expensive modulo division instructions inside the loop.

Complexity Analysis

Time Complexity: $\mathcal{O}(N)$

A single linear pass over the array of length $N$, performing $\mathcal{O}(1)$ bitwise and arithmetic operations per element.

Space Complexity: $\mathcal{O}(1)$ auxiliary space

Uses only scalar variables (evenCount, oddCount, prefixParity, totalOddSubarrays).

C++ Implementation

#include <iostream>
#include <vector>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int numOfSubarrays(const vector<int>& arr) {
        constexpr int MOD = 1e9 + 7;
        long long totalOddSubarrays = 0;
        
        int evenCount = 1; // Empty prefix sum (0) is even
        int oddCount = 0;
        int prefixParity = 0; // 0 = even, 1 = odd

        for (int num : arr) {
            prefixParity ^= (num & 1);

            if (prefixParity == 1) {
                totalOddSubarrays += evenCount;
                oddCount++;
            } else {
                totalOddSubarrays += oddCount;
                evenCount++;
            }

            if (totalOddSubarrays >= MOD) {
                totalOddSubarrays -= MOD;
            }
        }

        return static_cast<int>(totalOddSubarrays);
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1, 3, 5] -> Expected: 4
    vector<int> arr1 = {1, 3, 5};
    cout << "Test 1: " << solver.numOfSubarrays(arr1) << " | Expected: 4\n";

    // Test Case 2: [2, 4, 6] -> Expected: 0
    vector<int> arr2 = {2, 4, 6};
    cout << "Test 2: " << solver.numOfSubarrays(arr2) << " | Expected: 0\n";

    // Test Case 3: [1, 2, 3, 4, 5, 6, 7] -> Expected: 16
    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7};
    cout << "Test 3: " << solver.numOfSubarrays(arr3) << " | Expected: 16\n";

    return 0;
}
