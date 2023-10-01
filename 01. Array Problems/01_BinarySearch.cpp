//Binary Search is most widely used search algorhitm when array is sorted.
//Time : O(logn)

//github.com/ddhuu
#include <iostream>

int binarySearch(const int* array, int key, int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;
    if (array[mid] == key) {
        return mid;
    } else if (key < array[mid]) {
        return binarySearch(array, key, low, mid - 1);
    } else {
        return binarySearch(array, key, mid + 1, high);
    }
}

int main() {
    int array[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int arraySize = sizeof(array) / sizeof(array[0]);

    // Test cases
    int key1 = 7;
    int result1 = binarySearch(array, key1, 0, arraySize - 1);
    std::cout << "Index of " << key1 << " is: " << result1 << std::endl;

    int key2 = 13;
    int result2 = binarySearch(array, key2, 0, arraySize - 1);
    std::cout << "Index of " << key2 << " is: " << result2 << std::endl;

    int key3 = 6;
    int result3 = binarySearch(array, key3, 0, arraySize - 1);
    std::cout << "Index of " << key3 << " is: " << result3 << std::endl;

    return 0;
}
