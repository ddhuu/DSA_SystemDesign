/*
Design a data structure which performs the following operations : Insert,Delete,Search,Find Random in O(1)
----------------------------------------------------------------
#Combination of  vector and Hashmap
*/

//github.com/ddhuu
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib> // For rand()

using namespace std;

class RandomizedDataStructure {
private:
    vector<int> data;
    unordered_map<int, int> indexMap;

public:
    void insert(int num) {
        if (indexMap.find(num) != indexMap.end()) {
            return;
        }
        int size = data.size();
        data.push_back(num);
        indexMap[num] = size;
    }

    void remove(int num) {
        if (indexMap.find(num) == indexMap.end()) {
            return;
        }
        int index = indexMap[num];
        indexMap.erase(num);
        int size = data.size();
        int last = data[size - 1];
        swap(data[index], data[size - 1]);
        data.pop_back();
        indexMap[last] = index;
    }

    bool search(int num) {
        return indexMap.find(num) != indexMap.end();
    }

    int getRandom() {
        int index = rand() % data.size();
        return data[index];
    }
};

int main() {
    RandomizedDataStructure dataStructure;

    dataStructure.insert(1);
    dataStructure.insert(2);
    dataStructure.insert(3);

    cout << "Random: " << dataStructure.getRandom() << endl;

    dataStructure.remove(2);

    cout << "Random: " << dataStructure.getRandom() << endl;

    cout << "Search 3: " << (dataStructure.search(3) ? "Found" : "Not Found") << endl;
    cout << "Search 2: " << (dataStructure.search(2) ? "Found" : "Not Found") << endl;

    return 0;
}
