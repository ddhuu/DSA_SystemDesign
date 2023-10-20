#include <iostream>
#include <vector>

using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    vector<vector<int>> matrix(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else if (word1[i - 1] == word2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]));
            }
        }
    }

    return matrix[m][n];
}

int main() {
    string word1 = "horse";
    string word2 = "ros";

    int minEditDistance = minDistance(word1, word2);

    cout << "Minimum Edit Distance: " << minEditDistance << endl;

    return 0;
}
