// Finding an element in Rotated Sorted Array
// Time : O(logn)  , Space : O(1)

//github.com/ddhuu
#include <iostream>

int findNumber(int arr[], int start, int end, int value) {
    if (start > end) {
        return -1;
    }

    int mid = (start + end) / 2;
    if (arr[mid] == value) {
        return mid;
    }

    if (arr[start] <= arr[mid]) {
        if (value >= arr[start] && value <= arr[mid]) {
            return findNumber(arr, start, mid - 1, value);
        }
        return findNumber(arr, mid + 1, end, value);
    }

    if (value >= arr[start] && value <= arr[mid]) {
        return findNumber(arr, mid + 1, end, value);
    }
    return findNumber(arr, start, mid - 1, value);
}

int main() {
    int arr[] = {3,4,5,6,7,8,9,1,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value = 1;

    int index = findNumber(arr, 0, n - 1, value);
    if (index != -1) {
        std::cout << "Number " << value << " found at index " << index << std::endl;
    } else {
        std::cout << "Number " << value << " not found in the array." << std::endl;
    }

    return 0;
}
