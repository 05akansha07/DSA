/*
Question:
Given an array of daily stock prices, find the span of each day's price.

The span of a stock price is the maximum number of consecutive days
before the current day (including the current day) for which the
stock price was less than or equal to the current day's price.

Example:
Input:  [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]

Approach:
Use a stack to store the indices of useful previous prices.

Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(arr)/sizeof(arr[0]);

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        int ans;

        while (!st.empty() && arr[i] >= arr[st.top()])
        {
            st.pop();
        }

        if (st.empty())
            ans = i + 1;
        else
            ans = i - st.top();

        cout << arr[i] << " -> " << ans << endl;

        st.push(i);
    }

    return 0;
}