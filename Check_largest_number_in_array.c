#include <stdio.h>

// Function to find the largest element
int findLargest(int* arr, int n) {
    int largest = arr[0]; // Assume first element is the largest
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i]; // Update largest
        }
    }
    return largest;
}

int main() {
    int arr[] = {3, 2, 1, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int maxVal = findLargest(arr, n);
    printf("The largest element is: %d\n", maxVal); // Output: 5
    
    return 0;
}
