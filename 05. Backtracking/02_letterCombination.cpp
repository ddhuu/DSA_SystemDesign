#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Lecture {
public:
    unordered_map<string, string> map = {
        {"2", "abc"},
        {"3", "def"},
        {"4", "ghi"},
        {"5", "jkl"},
        {"6", "mno"},
        {"7", "pqrs"},
        {"8", "tuv"},
        {"9", "wxyz"}
    };

    vector<string> output;

    void findSequence(string curList, string digits) {
        if (digits.length() == 0) {
            output.push_back(curList);
            return;
        } else {
            string digit = digits.substr(0, 1);
            string letters = map[digit];
            for (int i = 0; i < letters.length(); i++) {
                string letter = map[digit].substr(i, 1);
                findSequence(curList + letter, digits.substr(1));
            }
        }
    }
};

int main() {
    Lecture lecture;

    string digits = "23";
    lecture.findSequence("", digits);

    for (const string& sequence : lecture.output) {
        cout << sequence << endl;
    }

    return 0;
}
