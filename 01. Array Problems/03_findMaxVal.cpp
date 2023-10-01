/*One array of integers is given as input, which  is intitially increasing and
then decreasing or it can be only decreasing or increasing.Find the maximum value in the array
----------------------------------------------------------------
Time: O(logn)
Space: O(1)
*/


//github.com/ddhuu
#include <iostream>

int findMaximumVal(int arr[], int start, int end)
{
  if (start == end)
  {
    return arr[start];
  }
  if (end == start + 1)
  {
    if (arr[start] >= arr[end])
    {
      return arr[start];
    }
    else
    {
      return arr[end];
    }
  }

  int mid = (start + end) / 2;
  if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
  {
    return arr[mid];
  }
  if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
  {
    return findMaximumVal(arr, start, mid - 1);
  }
  else
  {
    return findMaximumVal(arr, mid + 1, end);
  }
}

int main()
{
  int arr[] = {5, 10, 15, 20, 19, 18, 17};
  int n = sizeof(arr) / sizeof(arr[0]);
  int maxVal = findMaximumVal(arr, 0, n - 1);

  std::cout << "Maximum value: " << maxVal << std::endl;

  return 0;
}
