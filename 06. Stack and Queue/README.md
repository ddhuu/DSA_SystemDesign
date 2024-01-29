# Stack and Queue
## 01. Circular Queue implementation
Circular queue is a linear data structure in which operations are performed based on the FIFO (First In First Out) principle; The last position is connected back to the first position to make a circle.
## 02. Histogram Problem
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the this histogram.
## 03. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.An input string is valid if:Open brackets must be closed by the same type of brackets.Open brackets must be closedthe correct order.
## 04. Stack that Supports getMin() in O(1)
Design a data structure which support push()/pop()/findminimum() operation in O(1) time.
## 05. Reverse Words in a String
 Given an input string, reverse the string word by word.
## 06. Find Maximum size rectangle in Binary Sub-matrix
Given a binary matrix, find the maximum size rectangle binary-submatrix with all 1’s.
## 07. Next Greater Element
 Given an array, print the Next Greater Element for every element. The Next greater Element for an element a is the first greater element on the right side of a in array. Elements for which no greater element exist, consider next greater element as -1 .
 ```java
//java
//if next number is less then we store it
//if next number is more, we got NGE and check with stored num

public static void printNextGreaterElement(int[] array)
{
Stack<Integer> stack = new Stack <Integer>();
int arraySize = array.length;
stack.push(array[0]);
for(int i = 1 ; i < arraySize; i++)
	while(!stak.isEmpty() && stack.peek() < array[i])
			System.out.println("Next Greater Element" + stack.pop() + "\t= " + array[i]);
	stack.push(array[i]);
}
while (!stack.isEmpty())
	int top = (int) stack.pop();
	System.out.println("Next Greater Element for"+ top + "\t = " + null);
 ```
## 08. Sliding Window Problem using deque Data Structure
Given an array and an integer K, find the maximum for each and every contiguous subarray of size k Asked in : Google, Facebook, DE-Shaw.
