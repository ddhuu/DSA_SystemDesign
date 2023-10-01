/*
 Given an array in which all numbers except two are repeated once. (i.e. we have 2n+2 numbers and n numbers are occurring twice and the remaining two have occurred 
once). Find those two numbers in the most efficient way.
----------------------------------------------------------------
Using  XOR and Masking

*/



//github.com/ddhuu
#include <iostream>
#include <vector>

std::vector<int> singleNumber(std::vector<int>& nums) {
    long x = 0;
    std::vector<int> res(2, 0); // Initialize the result vector with 2 zeros
    for (int i : nums) {
        x ^= i;
    }
    long most_rightBit = x & ~(x - 1);
    for (int i : nums) {
        if (i & most_rightBit) {
            res[0] ^= i;
        } else {
            res[1] ^= i;
        }
    }
    return res;
}

int main() {
    std::vector<int> nums = {1, 2, 1, 3, 2, 5};
    std::vector<int> result = singleNumber(nums);
    
    std::cout << "Single numbers are: " << result[0] << " and " << result[1] << std::endl;

    return 0;
}
