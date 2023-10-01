/*
List of arrival and departure time is given, Find the minimum number of 
platforms are required for the railway as no train waits
----------------------------------------------------------------
Using Greedy Techniques
*/



//github.com/ddhuu
#include<iostream>
#include <algorithm>

int minPlatforms(int arrival[], int departure[], int n) {
    std::sort(departure, departure + n);

    int platform_needed = 1;
    int maxPlatforms = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platform_needed++;
            i++;

            if (platform_needed > maxPlatforms) {
                maxPlatforms = platform_needed;
            }
        } else {
            platform_needed--;
            j++;
        }
    }

    return maxPlatforms;
}

int main() {
    int arrival[] = {900, 940, 950, 1100, 1500, 1800};
    int departure[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arrival) / sizeof(arrival[0]);

    int result = minPlatforms(arrival, departure, n);

    // Output the minimum number of platforms required
    std::cout << "Minimum number of platforms required: " << result << std::endl;

    return 0;
}
