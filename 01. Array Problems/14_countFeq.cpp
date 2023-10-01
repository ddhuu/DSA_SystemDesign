/*
Array of length n having integers 1 to n with some elements being 
repeated. Count frequencies of all elements from 1 to n .
----------------------------------------------------------------
Time : O(n)
Space: O(1)

*/


#include <iostream>
using namespace std;

void countFrequencies(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i]--;

    for (int i = 0; i < n; i++)
        arr[arr[i] % n] += n;

    for (int i = 0; i < n; i++)
        cout << "Element " << i + 1 << " appears " << arr[i] / n << " times" << endl;
}

int main() {
    // Sample array with elements from 1 to n
    int arr[] = {2, 4, 6, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    countFrequencies(arr, n);

    return 0;
}
