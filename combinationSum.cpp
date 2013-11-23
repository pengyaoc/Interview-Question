#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 
    Similar to all problems related to print out all possible path,
    we use a current and a return. When hit the end, we push current
    (which contains the path) into ret.
    Similar problem: palindrome partitioning
*/
void combinationSum(vector<int> &candidates, int target, int start,
                    vector<vector<int> >& ret, vector<int> current) 
{
    int length = candidates.size();
    //if (start >= length)
    //    return;
    for (int i=start; i<length; i++)
    {
        if (candidates[i] <= target/2)
        {
            current.push_back(candidates[i]);
            combinationSum(candidates, target-candidates[i], i, ret, current);
            current.pop_back();
        }
        else if (candidates[i] == target)
        {
            current.push_back(candidates[i]);
            ret.push_back(current);
            current.pop_back();
        }
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > ret;
    vector<int> current;
    sort(candidates.begin(), candidates.end());
    combinationSum(candidates, target, 0, ret, current);
    return ret;
}

int main()
{
    vector<int> can = {2,3,6,7};
    int target = 7;
    vector<vector<int> > ret = combinationSum(can, target);
    for (int i=0; i<ret.size(); i++)
    {
        for (int j=0; j<ret[i].size(); j++)
        {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
}
