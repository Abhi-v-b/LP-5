#include <iostream>
#include <vector>
#include <omp.h>
#include <climits>
using namespace std;

void min_reduction(vector<int>& arr) {
    double start_time = omp_get_wtime(); // Start time measurement
    int min_value = INT_MAX;
    #pragma omp parallel for reduction(min: min_value)
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }
    double end_time = omp_get_wtime(); // End time measurement
    cout << "Minimum value: " << min_value << endl;
    cout << "Time taken for min_reduction: " << end_time - start_time << " seconds" << endl;
}

void max_reduction(vector<int>& arr) {
    double start_time = omp_get_wtime(); // Start time measurement
    int max_value = INT_MIN;
    #pragma omp parallel for reduction(max: max_value)
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    double end_time = omp_get_wtime(); // End time measurement
    cout << "Maximum value: " << max_value << endl;
    cout << "Time taken for max_reduction: " << end_time - start_time << " seconds" << endl;
}

void sum_reduction(vector<int>& arr) {
    double start_time = omp_get_wtime(); // Start time measurement
    int sum = 0;
    #pragma omp parallel for reduction(+: sum)
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    double end_time = omp_get_wtime(); // End time measurement
    cout << "Sum: " << sum << endl;
    cout << "Time taken for sum_reduction: " << end_time - start_time << " seconds" << endl;
}

void average_reduction(vector<int>& arr) {
    double start_time = omp_get_wtime(); // Start time measurement
    int sum = 0;
    #pragma omp parallel for reduction(+: sum)
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    double end_time = omp_get_wtime(); // End time measurement
    cout << "Average: " << (double)sum / arr.size() << endl;
    cout << "Time taken for average_reduction: " << end_time - start_time << " seconds" << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    min_reduction(arr);
    max_reduction(arr);
    sum_reduction(arr);
    average_reduction(arr);
    return 0;
}

















#Enter the number of elements: 9
#Enter 9 elements: 5 2 9 1 7 6 8 3 4
#Minimum value: 1
#Maximum value: 9
#Sum: 45
#Average: 5


