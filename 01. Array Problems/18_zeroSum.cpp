/*
Array of both positive and negative numbers.
Let find out the  sub array whose sum is Zero
----------------------------------------------------------------
Time : O(n)
Space: O(n)
*/


//github.com/ddhuu
#include <iostream>
#include <vector>
#include <unordered_map>

class SubArray {
public:
    int start, end;
    SubArray(int a, int b) : start(a), end(b) {}
};

std::vector<SubArray> findSubArray(int array[], int n) {
    std::unordered_map<int, std::vector<int>> map;
    std::vector<SubArray> result;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += array[i];
        if (sum == 0) {
            result.push_back(SubArray(0, i));
        }
        if (map.find(sum) != map.end()) {
            std::vector<int>& list = map[sum];
            for (int j = 0; j < list.size(); j++) {
                result.push_back(SubArray(list[j] + 1, i));
            }
            list.push_back(i);
        } else {
            map[sum] = std::vector<int>{i};
        }
    }

    return result;
}

int main() {
    int array[] = {4, 2, -3, -1, 0, 4};
    int n = sizeof(array) / sizeof(array[0]);

    std::vector<SubArray> subArrays = findSubArray(array, n);

    for (const SubArray& subArray : subArrays) {
        std::cout << "Subarray found: [" << subArray.start << ", " << subArray.end << "]" << std::endl;
    }

    return 0;
}
