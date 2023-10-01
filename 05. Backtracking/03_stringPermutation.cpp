#include <iostream>
#include <string>

using namespace std;

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void stringPermutation(string word, int start, int end) {
    if (start == end) {
        cout << word << endl;
    } else {
        for (int index = start; index <= end; index++) {
            swap(word[start], word[index]);
            stringPermutation(word, start + 1, end);
            swap(word[start], word[index]);
        }
    }
}

int main() {
    string word = "abc";
    stringPermutation(word, 0, word.length() - 1);
    return 0;
}
