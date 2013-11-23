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
        cout <<  A[start] << " " << A[mid] << " " << A[end] << endl;
        if (A[mid] == target)
        {
            return mid;
        }
        if (start == mid)
        {
            start++;
        }
        else if (end == mid)
        {
            end--;
        }
        else if (A[start] <= target && target < A[mid]) 
        {
            end = mid-1;
        }
        else if (A[mid] < target && target <= A[end])
        {
            start = mid+1;
        }
        else if (A[start] <= target && target > A[mid] && A[start] < A[mid])
        {
            start = mid+1;            
        }
        else if (A[mid] < target && target >= A[end] && A[mid] < A[end])
        {
            end = mid-1;
        }
        else if (A[start] >= target && target < A[mid] && A[start] < A[mid])
        {
            start = mid+1;            
        }
        else if (A[mid] > target && target <= A[end] && A[mid] < A[end])
        {
            end = mid-1;
        }
        else
        {
            return -1;
        }
    }
    return -1;
}

int main()
{
    int A[] = {3,5,1};
    cout << search(A, 3, 1) << endl;
}

