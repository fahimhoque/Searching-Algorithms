/*
Algorithm:
1.Compare x with the middle element.
2.If x matches with middle element, we return the mid index.
3.Else If x is greater than the mid element, then x can only lie in right half subarray after the mid element. 
    So we recur for right half.
4.Else (x is smaller) recur for the left half.


Scenario:
Time Complexity:
The time complexity of Binary Search can be written as

T(n) = T(n/2) + c 
The above recurrence can be solved either using Recurrence T ree method or Master method. 
    It falls in case II of Master Method and solution of the recurrence is Theta(Logn).

Auxiliary Space: O(1) in case of iterative implementation. 
    In case of recursive implementation, O(Logn) recursion call stack space.

*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}