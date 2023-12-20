# Hashing/Heap 
## 01. Find first non-repeating character from a stream of characters
Given  a stream of characters find the first non-repeating character from stream. You need to tell the first non-reachable character in O(1) time.
## 02. Design and implement LRU
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get(key)and set(key,value). 
## 03. Four Sum Problem
Given an array of n integer target. Find if there elements a,b,c  and d in integers present in array such that a + b + c + d  = target. Find unique quadruplet in the array which gives the sum of target.
## 04. Convert number  to words problem
Write an efficient algorithm to convert a number into word.
```cpp
//digig1[] = ["Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"]
/*digit[2] = ["One","Two","Three","Four","Five","Six","Seven","Eight","Night","Ten","Eleven","twelve",
"thirteen","fourteen","fifteen","sixteen","seventeen","eightteen","nighteen"]*/
/*
Digit1 is use for 2nd digit is more than 1
Digit2 for rest all case
*/
#include <vector>
#include <string>

class Solution {
public:
    std::string numberToWords(int num) {
        if (num == 0) return "Zero";
        int i = 0;
        std::string words = "";
        
        while (num > 0) {
            if (num % 1000 != 0)
                words = helper(num % 1000) + thousands[i] + " " + words;
            num /= 1000;
            i++;
        }
        
        while (words.back() == ' ') words.pop_back(); // trim trailing spaces
        return words;
    }

private:
    std::vector<std::string> below20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    std::vector<std::string> below100 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    std::vector<std::string> thousands = {"", "Thousand", "Million", "Billion"};

    std::string helper(int num) {
        if (num == 0)
            return "";
        else if (num < 20)
            return below20[num] + " ";
        else if (num < 100)
            return below100[num / 10] + " " + helper(num % 10);
        else
            return below20[num / 100] + " Hundred " + helper(num % 100);
    }
};
```
## 05. Given k sorted array, write an efficient algorithm to merge them into one sorted array.
```cpp
// Merge k sorted array
/*
class MinHeapNode{
int i,j,val;
}
1. Add element at last, perculate up
2. Extract min element using Perculate down
Note: check if (MinNodeHeap[(i-1)/2].val < MinNodeHeap[i].val )*/
#include <queue>
#include <vector>

struct CompareNode {
    bool operator()(ListNode* const & p1, ListNode* const & p2) {
        // priority queue is a max heap by default, we need to provide a comparison function for min heap
        return p1->val > p2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;

        // Initialize the min heap with the first node from each list
        for (auto list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        // Create a new dummy head for the result list
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Extract the minimum node from the min heap and add it to the result list
        while (!minHeap.empty()) {
            ListNode* minNode = minHeap.top();
            minHeap.pop();
            tail->next = minNode;
            tail = tail->next;

            // Add the next node from the same list to the min heap
            if (minNode->next) {
                minHeap.push(minNode->next);
            }
        }

        return dummy.next;
    }
};
```
