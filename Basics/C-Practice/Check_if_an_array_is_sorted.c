#include <stdio.h>

// Function to check if array is sorted (Non-descending)
int isSorted(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0; // Array breaks sorting order, return false immediately
        }
    }
    return 1; // Completed loop cleanly, return true
}

int main() {
    int sortedArr[] = {1, 2, 2, 3, 4};
    int n1 = sizeof(sortedArr) / sizeof(sortedArr[0]);
    
    int unsortedArr[] = {1, 2, 1, 3, 4};
    int n2 = sizeof(unsortedArr) / sizeof(unsortedArr[0]);
    
    printf("Is sortedArr sorted? %s\n", isSorted(sortedArr, n1) ? "True" : "False"); // Output: True
    printf("Is unsortedArr sorted? %s\n", isSorted(unsortedArr, n2) ? "False" : "True"); // Output: False
    
    return 0;
}
