 /*Given an array nums, write a function to move all 0's to the end of it 
while maintaining the relative order of the non-zero elements
----------------------------------------------------------------
Time :  O(n)
Space:  O(1)
*/

//github.com/ddhuu
#include <iostream>

void moveZeros(int arr[], int n) {
    int count = 0;
    
    // Move non-zero elements to the beginning of the array
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }

    // Fill the remaining positions with zeros
    while (count < n) {
        arr[count++] = 0;
    }
}

int main() {
    int arr[] = {0, 3, 0, 5, 9, 0, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZeros(arr, n);

    std::cout << "Array after moving zeros to the end: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
