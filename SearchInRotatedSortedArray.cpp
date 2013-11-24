/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

#include <iostream>

using namespace std;

int search(int A[], int n, int target) {
    int start = 0;
    int end = n-1;
    int mid;
    while (start <= end)
    {
        mid = start - (start - end)/2;
        // Either first half (from index start to mid) is sorted or
        // the second half is sorted.
        // When first half is sorted, two cases:
        // 1. target is in range (between A[start] and A[mid])
        // 2. target is out of range
        // If (1), in this half. If (2), in the other half.
        if (A[mid] == target)
        {
            return mid;
        }
        // first half is sorted
        else if (A[start] <= A[mid])
        {
            if (A[start] <= target && target < A[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        // second half is sorted
        else // if (A[mid] <= A[end])
        {
            if (A[mid] < target && target <= A[end])
            {
                start = mid + 1; 
            }
            else
            {
                end = mid - 1;   
            }
        }
    }
    return -1;
}

int main()
{
    int A[] = {3,5,1};
    cout << search(A, 3, 1) << endl;
}

