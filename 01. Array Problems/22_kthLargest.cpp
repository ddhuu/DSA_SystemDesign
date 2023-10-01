/*
QuickSelect Algorithm to find the Kth Smallest Element in array
*/




//github.com/ddhuu
#include <iostream>

int partition(int* nums, int low, int high) {
    int pivot = nums[high], i = low;
    for (int j = low; j <= high - 1; j++) {
        if (nums[j] <= pivot) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }
    int temp = nums[i];
    nums[i] = nums[high];
    nums[high] = temp;
    return i;
}

int findKthSmallest(int* nums, int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int index = partition(nums, low, high);
        if (index - low + 1 == k) {
            return nums[index];
        }
        if (index - low + 1 > k) {
            return findKthSmallest(nums, low, index - 1, k);
        } else {
            return findKthSmallest(nums, index + 1, high, low + k - index - 1);
        }
    }
    return -1; // Return a default value if k is out of range
}

int main() {
    int nums[] = {3, 2, 1, 5, 6, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    int result = findKthSmallest(nums, 0, numsSize - 1, k);

    std::cout <<k<< "th Smallest element is: " << result << std::endl;

    return 0;
}
