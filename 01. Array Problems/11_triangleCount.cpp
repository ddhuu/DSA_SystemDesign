/*
Counting the number of triplets chosen from the array that can make triangles if we take them as side 
lengths of a triangle 
----------------------------------------------------------------
Time : O(n^2)
Space: O(1)

*/

//github.com/ddhuu
#include <iostream>
#include <algorithm>

int trianglesCount(int arr[], int n) {
    std::sort(arr, arr + n);
    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        int k = i + 2;
        for (int j = i + 1; j < n && arr[i] != 0; j++) {
            while (k < n && arr[i] + arr[j] > arr[k]) {
                k++;
            }
            count += k - j - 1;
        }
    }

    return count;
}

int main() {
    int arr[] = {4, 3, 7, 8, 10, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = trianglesCount(arr, n);

    std::cout << "Number of valid triangles that can be formed: " << result << std::endl;

    return 0;
}
