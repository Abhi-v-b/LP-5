#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void merge_sort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void parallel_merge_sort(vector<int>& arr) {
    #pragma omp parallel
    {
        #pragma omp single
        merge_sort(arr, 0, arr.size() - 1);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    double start, end;

    // Measure performance of sequential merge sort
    start = omp_get_wtime();
    merge_sort(arr, 0, arr.size() - 1);
    end = omp_get_wtime();
    cout << "Sequential merge sort time: " << end - start << " seconds" << endl;

    // Measure performance of parallel merge sort
    start = omp_get_wtime();
    parallel_merge_sort(arr);
    end = omp_get_wtime();
    cout << "Parallel merge sort time: " << end - start << " seconds" << endl;

    cout << "Sorted array:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}



















OUTPUT:
Enter the number of elements in the array: 9
Enter the elements of the array:
5
2
9
1
7
6
8
3
4
Sequential merge sort time: 1.0822e-05 seconds
Parallel merge sort time: 0.000220803 seconds
Sorted array:
1 2 3 4 5 6 7 8 9 
