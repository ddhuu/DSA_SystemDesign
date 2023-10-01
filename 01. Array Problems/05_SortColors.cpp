// Array consist of only 0's, 1's and 2's. Write an algorithm to sort this 
// Time : O(n), Space : O(1)



//github.com/ddhuu
#include <iostream>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sortColor(int arr[], int n) {
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr, mid, low);
            low++;
            mid++;
        } else if (arr[mid] == 2) {
            swap(arr, mid, high);
            high--;
        } else {
            mid++;
        }
    }
}

int main() {
    int arr[] = {2, 0, 1, 2, 1, 0, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    sortColor(arr, n);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}

