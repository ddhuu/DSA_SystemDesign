/*
Given a sorted array, remove the duplicates in place such that each 
element appear only once and return the new length. Do not allocate extra space for another 
array.
----------------------------------------------------------------
Time : O(n)
Space: O(1)

*/

//github.com/ddhuu
#include <iostream>

int removeDuplicates(int arr[], int n) {
    if (n == 1 || n == 0) {
        return n;
    }

    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n - 1];
    return j;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int newSize = removeDuplicates(arr, n);

    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
