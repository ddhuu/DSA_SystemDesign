/*
A 2-D array of 1's and 0's is given. Find the row with max 1's 
----------------------------------------------------------------
Time : O(m*logn)
Space : O(1)
*/



#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(std::vector<int> &v, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || v[mid - 1] == 0) && v[mid] == 1) {
            return mid;
        } else if (v[mid] == 0) {
            return binarySearch(v, mid + 1, high);
        } else {
            return binarySearch(v, low, mid - 1);
        }
    }
    return -1;
}

int  rowAndMaxOnes(std::vector<std::vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    int j = 0;
    int max = 0;
    for (int i = 0; i < m; i++) 
    {
        int index = binarySearch(mat[i], 0, n - 1);
        if (index != -1 && n - index > max) {
            max = n - index;
            j = i;
        }
    }
    
    return  j + 1;
}

int main() {
    std::vector<std::vector<int>> mat = {
        {0,0,1,1},
        {0, 1, 1,1},
        {1,1,1,1}
    };

    int result = rowAndMaxOnes(mat);

    std::cout << "Row with maximum ones: " << result<< std::endl;
    

    return 0;
}
