/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

int singleNumber(int A[], int n) {
    int ret = 0;
    for (int i=0; i<n; i++)
    {
        ret = ret ^ A[i];
    }
    return ret;
}
