
/*
Write an algorithm to find out next greater number to given number with 
the same set of digits.

*/


//github.com/ddhuu 
#include <iostream>
#include<string>
#include <algorithm>

int nextGreaterElement(int n) {
    // Convert the number to an array of its digits
    std::string numStr = std::to_string(n);
    int length = numStr.length();
    int arr[length];
    for (int i = 0; i < length; i++) {
        arr[i] = numStr[i] - '0';
    }

    // Find the index 'i' where the decreasing sequence starts
    int i;
    for (i = length - 1; i > 0; i--) {
        if (arr[i] > arr[i - 1]) {
            break;
        }
    }

    // If no such number is found, return -1
    if (i == 0) {
        return -1;
    }

    // Find the smallest digit larger than 'element' and to its right
    int element = arr[i - 1], min = i;
    for (int j = i + 1; j < length; j++) {
        if (arr[j] > element && arr[j] < arr[min]) {
            min = j;
        }
    }

    // Swap 'element' and 'arr[min]'
    std::swap(arr[i - 1], arr[min]);

    // Sort the digits to the right of 'i'
    std::sort(arr + i, arr + length);

    // Convert the modified digits back to an integer
    int result = 0;
    for (int k = 0; k < length; k++) {
        result = result * 10 + arr[k];
    }

    return result;
}

int main() {
    int n = 1234;
    int result = nextGreaterElement(n);

    std::cout << "The smallest integer greater than " << n << " with the same digits: " << result << std::endl;

    return 0;
}
