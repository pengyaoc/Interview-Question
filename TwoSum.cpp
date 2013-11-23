#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct numberIndex
{
    numberIndex(int n, int i) : number(n), index(i) {};
    int number;
    int index;
};

static bool compare(numberIndex A, numberIndex B)
{
    return A.number < B.number;
}

// Here we create a new data structure to support look up for the index
// Can also do lookup for index afterwards
vector<int> twoSum(vector<int> &numbers, int target) {
    vector<numberIndex> numberIndexes;
    for (int i=0; i<numbers.size(); i++)
    {
        numberIndexes.push_back(numberIndex(numbers[i], i+1));
    } 
    sort(numberIndexes.begin(), numberIndexes.end(), compare);
    int begin = 0;
    int end = numberIndexes.size()-1;
    vector<int> ret;
    int sum;
    while (begin < end)
    {
        sum = numberIndexes[begin].number + numberIndexes[end].number;
        if (sum == target)
        {
            int a = numberIndexes[begin].index;
            int b = numberIndexes[end].index;
            ret.push_back((a>b)?b:a);
            ret.push_back((a>b)?a:b);
            break;    
        }
        else if (sum > target)
        {
            end--;
        }
        else // sum < target
        {
            begin++;
        }
    }
    return ret;
}

int main()
{
    vector<int> in = {10,5,9,8};
    vector<int> ret = twoSum(in, 15);
    cout << ret[0] << " " << ret[1] << endl;
}
