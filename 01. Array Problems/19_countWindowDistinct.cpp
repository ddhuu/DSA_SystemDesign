/*
Give an array of integers and a number K . Find the count of distinct elements in every window of
size K in the array.
----------------------------------------------------------------
Time : O(n)
Space: O(n)
*/

//github.com/ddhuu
#include <iostream>
#include <unordered_map>

void countWindowDistinct(int arr[], int n, int k) {
    std::unordered_map<int, int> map;
    int count = 0;

    for (int i = 0; i < k; i++) {
        if (map.find(arr[i]) == map.end()) {
            map[arr[i]] = 1;
            count++;
        } else {
            int currentCount = map[arr[i]];
            map[arr[i]] = currentCount + 1;
        }
    }

    std::cout << count << std::endl;

    for (int i = k; i < n; i++) {
        if (map[arr[i - k]] == 1) {
            map.erase(arr[i - k]);
            count--;
        } else {
            int currentCount = map[arr[i - k]];
            map[arr[i - k]] = currentCount - 1;
        }

        if (map.find(arr[i]) == map.end()) {
            map[arr[i]] = 1;
            count++;
        } else {
            int currentCount = map[arr[i]];
            map[arr[i]] = currentCount + 1;
        }

        std::cout << count << std::endl;
    }
}

int main() {
    int arr[] = {1, 2, 1, 3, 4, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    countWindowDistinct(arr, n, k);

    return 0;
}
