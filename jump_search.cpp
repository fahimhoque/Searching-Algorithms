/*
Algorithm:
suppose we have an array arr[] of size n and block (to be jumped) size m. 
Then we search at the indexes arr[0], arr[m], arr[2m]…..arr[km] and so on. 
Once we find the interval (arr[km] < x < arr[(k+1)m]), we perform a linear search operation from the index km to find the element x.


Scenario:
Time Complexity : O(√n)
Auxiliary Space : O(1)

Important Notes:
Binary Search is better than Jump Search, but Jump search has an advantage that we 
    traverse back only once (Binary Search may require up to O(Log n) jumps, 
    consider a situation where the element to be searched is the smallest element or smaller than the smallest). 
    So in a system where binary search is costly, we use Jump Search.

*/
#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[], int x, int n)
{

    int step = sqrt(n);

    int prev = 0;
    while (arr[min(step, n) - 1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x)
    {
        prev++;

        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}

int main()
{
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21,
                 34, 55, 89, 144, 233, 377, 610};
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = jumpSearch(arr, x, n);
    cout << "\nNumber " << x << " is at index " << index;
    return 0;
}