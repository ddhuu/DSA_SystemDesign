/*
Design a DataStructure which performs the following operations in O(1) time : Push,Pop,findMiddle, deleteMiddle
----------------------------------------------------------------
*/

//github.com/ddhuu
#include<iostream>
using namespace std;
class DLL {
public:
    DLL* next;
    DLL* prev;
    int val;
    DLL(int data) {
        val = data;
        prev = next = nullptr;
    }
};

class FindMiddleVal {
private:
    DLL* head;
    DLL* middle;
    int size;

public:
    FindMiddleVal() {
        head = middle = nullptr;
        size = 0;
    }

    void push(int data) {
        size++;
        if (!head) {
            head = new DLL(data);
            middle = head;
        } else {
            DLL* node = new DLL(data);
            node->next = head;
            head->prev = node;
            head = node;
            if (size % 2 == 0)
                middle = middle->prev;
        }
    }

    int pop() {
        if (!head)
            return -1;
        size--;
        int ret = head->val;
        if (size == 0) {
            head = nullptr;
            middle = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
            if (size % 2)
                middle = middle->next;
        }
        return ret;
    }

    int getMiddle() {
        return middle->val;
    }

    void deleteMiddle() {
        size--;
        if (middle->prev)
            middle->prev->next = middle->next;
        if (middle->next)
            middle->next->prev = middle->prev;
        if (size % 2 == 1)
            middle = middle->next;
        else
            middle = middle->prev;
    }
};

int main() {
    FindMiddleVal dll;

    dll.push(1);
    dll.push(2);
    dll.push(3);
    dll.push(4);
    dll.push(5);
    dll.push(6);

    cout << "Middle: " << dll.getMiddle() << endl;

    dll.deleteMiddle();

    cout << "Middle after deletion: " << dll.getMiddle() << endl;

    return 0;
}
