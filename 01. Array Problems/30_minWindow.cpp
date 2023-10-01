/*
Given two string string1 and string2, return the minimum window in string1  which contain all the characters iin string2
----------------------------------------------------------------
Time : O(n)
Space: O(1)
*/



#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

string findMinWindow(string str, string ptr) {
    int str_len = str.length();
    int ptr_len = ptr.length();
    int ascii_str[256] = {0};
    int ascii_ptr[256] = {0};
    int start = 0, start_index = -1, min_len = INT_MAX;
    int count = 0;

    for (char c : ptr) {
        ascii_ptr[c]++;
    }

    for (int i = 0; i < str_len; i++) {
        ascii_str[str[i]]++;
        if (ascii_ptr[str[i]] != 0 && ascii_str[str[i]] <= ascii_ptr[str[i]]) {
            count++;
        }
        if (count == ptr_len) {
            while (ascii_str[str[start]] > ascii_ptr[str[start]] || ascii_ptr[str[start]] == 0) {
                if (ascii_str[str[start]] > ascii_ptr[str[start]]) {
                    ascii_str[str[start]]--;
                }
                start++;
            }
            int len_window = i - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }

    if (start_index == -1) {
        return "";
    }

    return str.substr(start_index, min_len);
}

int main() {
    string str = "ADOBECODEBANC";
    string ptr = "ABC";
    
    string minWindow = findMinWindow(str, ptr);

    cout << "Minimum window: " << minWindow << endl;

    return 0;
}
