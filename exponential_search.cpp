/*
Algorithm:
1.Find range where element is present
2.Do Binary Search in above found range.
Scenario:
Time Complexity : O(Log n) 
Auxiliary Space : The above implementation of Binary Search is recursive and requires O(Log n) space. 
    With iterative Binary Search, we need only O(1) space.
*/

#include <iostream>
using namespace std;
int binarySearch(int arr[], int, int, int);
int exponentialSearch(int arr[], int n, int x)
{

    if (arr[0] == x)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= x)
        i = i * 2;

    return binarySearch(arr, i / 2,
                        min(i, n - 1), x);
}
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = exponentialSearch(arr, n, x);
    if (result == -1)
    {
        cout << "Element is not found";
    }
    else
    {
        cout << "Element is found at: " << result;
    }

    return 0;
}