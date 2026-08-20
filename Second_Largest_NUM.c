#include <stdio.h>
#include <limits.h> // Required for INT_MIN

// Function to find the second largest element
int findSecondLargest(int* arr, int n) {
    int largest = arr[0];
    int secondLargest = INT_MIN; // Initialize to the smallest possible integer
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            // Old largest becomes second largest, then update largest
            secondLargest = largest;
            largest = arr[i];
        } 
        // If it's smaller than largest but strictly greater than second largest
        else if (arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main() {
    int arr[] = {1, 2, 4, 7, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int secondMax = findSecondLargest(arr, n);
    
    if (secondMax == INT_MIN) {
        printf("There is no second largest element.\n");
    } else {
        printf("The second largest element is: %d\n", secondMax); // Output: 5
    }
    
    return 0;
}
