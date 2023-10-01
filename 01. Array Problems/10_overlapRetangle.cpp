// Retangle Overlap 
// --------------------------------
// Time: O(1) 
// Space:O(1)




//github.com/ddhuu
#include <iostream>

struct Point {
    int x, y;
};

bool overlapRectangle(Point S, Point P, Point S_prime, Point P_prime) {
    if (S.x > P_prime.x || S_prime.x > P.x || S.y < P_prime.y || S_prime.y < P.y) {
        return false;
    }
    return true;
}

int main() {
    Point S = {2,2};
    Point P = {3, 3};
    Point S_prime = {4, 0};
    Point P_prime = {4, 1};

    if (overlapRectangle(S, P, S_prime, P_prime)) {
        std::cout << "Rectangles overlap." << std::endl;
    } else {
        std::cout << "Rectangles do not overlap." << std::endl;
    }

    return 0;
}
