/*
You have an array of non-negative integers,you are initially positioned at 
the first index of the array.Each element in the array represents your maximum jump length at 
that position.Determine 
----------------------------------------------------------------
Time:  O(n)
Space : O(1)

*/


//github.com/ddhuu
#include <iostream>

int jumpGame(int arr[], int n) {
    int a = arr[0];
    int b = arr[0];
    int jump = 0;

    for (int i = 1; i < n; i++) {
        if (i == n - 1) {
            return jump;
        }
        a--;
        b--;

        if (arr[i] > b) {
            b = arr[i];
        }
        if (a == 0) {
            a = b;
            jump++;
        }
    }

    return jump;
}

int main() {
    int arr[] = {2, 3, 1, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int minJumps = jumpGame(arr, n);

    std::cout << "Minimum number of jumps required: " << minJumps << std::endl;

    return 0;
}
