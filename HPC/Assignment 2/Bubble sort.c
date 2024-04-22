#include <stdio.h>
#include <omp.h>

void sequentialBubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place, so only iterate till n-i-1
        for (j = 0; j < n-i-1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void parallelBubbleSort(int arr[], int n) {
    int i, j;
    #pragma omp parallel for private(i, j) shared(arr)
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place, so only iterate till n-i-1
        for (j = 0; j < n-i-1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Unsorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sequential version
    double start_time = omp_get_wtime(); // Start timing
    sequentialBubbleSort(arr, n);
    double end_time = omp_get_wtime(); // End timing
    printf("Sorted array (sequential): \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time taken (sequential): %f seconds\n", end_time - start_time);

    // Parallel version
    start_time = omp_get_wtime(); // Start timing
    parallelBubbleSort(arr, n);
    end_time = omp_get_wtime(); // End timing
    printf("Sorted array (parallel): \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time taken (parallel): %f seconds\n", end_time - start_time);

    return 0;
}





















OUTPUT:
Enter the number of elements: 9
Enter 9 elements:
5
2
9
1
7
6
8
3
4
Unsorted array: 
5 2 9 1 7 6 8 3 4 
Sorted array (sequential): 
1 2 3 4 5 6 7 8 9 
Time taken (sequential): 0.000001 seconds
Sorted array (parallel): 
1 2 3 4 5 6 7 8 9 
Time taken (parallel): 0.000218 seconds
