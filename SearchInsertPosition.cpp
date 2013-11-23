#include <iostream>

using namespace std;

void searchInsert(int A[], int start, int end, int target, int& ret) {
    if (start > end)
        return;
    int mid = (start + end)/2;
    if (A[mid] == target)
    {
        ret = mid;
    }
    else if (A[mid] > target)
    {
        ret = mid;
        searchInsert(A, start, mid-1, target, ret);
    }
    else // A[mid] < target
    {
        ret = mid+1;
        searchInsert(A, mid+1, end, target, ret);
    }
}

int searchInsert(int A[], int n, int target) {
    int ret = 0;
    searchInsert(A, 0, n-1, target, ret);
    return ret;
}

int main()
{
    int A[] = {1,3,5,6};
    cout << searchInsert(A, 4, 5) << endl;
    cout << searchInsert(A, 4, 2) << endl;
    cout << searchInsert(A, 4, 7) << endl;
    cout << searchInsert(A, 4, 0) << endl;
}
