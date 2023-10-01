/*
There are two sorted arrays of size m and n respectively. Find the median of the two sorted arrays.
----------------------------------------------------------------
Time : O(logn)
Space: O(1)

*/


//github.com/ddhuu
#include <iostream>
#include <algorithm>

using namespace std;

int getMedian(int arr[], int start, int end) {
    int n = end - start + 1;
    if (n % 2 == 0) {
        return (arr[start + n / 2] + arr[start + n / 2 - 1]) / 2;
    } else {
        return arr[start + n / 2];
    }
}

float findMedianSortedArrays(int first[], int start_f, int end_f, int second[], int start_s, int end_s) {
    if (end_f - start_f + 1 == 2 && end_s - start_s + 1 == 2) {
        float x = max(first[start_f], second[start_s]);
        float y = min(first[end_f], second[end_s]);
        return (x + y) / 2;
    }

    int m1 = getMedian(first, start_f, end_f);
    int m2 = getMedian(second, start_s, end_s);

    int mid_f = (end_f - start_f) / 2;
    int mid_s = (end_s - start_s) / 2;

    if (m1 > m2) {
        return findMedianSortedArrays(first, start_f, mid_f, second, mid_s, end_s);
    } else {
        return findMedianSortedArrays(first, mid_f, end_f, second, start_s, mid_s);
    }
}

int main() {
    int first[] = {1, 3, 5};
    int second[] = {2, 4, 6};
    int n1 = sizeof(first) / sizeof(first[0]);
    int n2 = sizeof(second) / sizeof(second[0]);

    float median = findMedianSortedArrays(first, 0, n1 - 1, second, 0, n2 - 1);

    cout << "Median: " << median << endl;

    return 0;
}
