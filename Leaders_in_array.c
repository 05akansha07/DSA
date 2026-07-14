#include <stdio.h>

int main()
{
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int largest = arr[n - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= largest)
        {
            printf("%d ", arr[i]);
            largest = arr[i];
        }
    }
}