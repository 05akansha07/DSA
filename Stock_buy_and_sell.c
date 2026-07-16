#include <stdio.h>

int main()
{

    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxprofit = 0;
    int profit;
    int min = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

        profit = arr[i] - min;

        if (profit > maxprofit)
        {
            maxprofit = profit;
        }

        printf("Day %d \nProfit %d \nMax profit %d \n\n", i, profit, maxprofit);
    }
}