#include <iostream>

using namespace std;

//Ternary 00,01,10

int singleNumber(int A[], int n) {
    int ones = 0;
    int twos = 0;
    int temp;
    for (int i=0; i<n; i++)
    {
        twos ^= ones & A[i];
        ones ^= A[i];
        temp = ~(twos & ones);
        ones &= temp;
        twos &= temp;
    }
    return ones;
}
