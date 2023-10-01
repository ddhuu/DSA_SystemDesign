//Merge Sort
//Time: O(nlogn)


//github.com/ddhuu
#include <iostream>

void merge(int arr[], int result[], int low, int mid, int high) {
    int k = low, i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            result[k++] = arr[i++];
        } else {
            result[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        result[k++] = arr[i++];
    }
    while (j <= high) {
        result[k++] = arr[j++];
    }
    for (int i = low; i <= high; i++) {
        arr[i] = result[i];
    }
}

void mergeSort(int arr[], int result[], int low, int high) {
    if (high == low) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, result, low, mid);
    mergeSort(arr, result, mid + 1, high);
    merge(arr, result, low, mid, high);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int* result = new int[n];

    mergeSort(arr, result, 0, n - 1);

    // Print sorted array
    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] result;
    return 0;
}
