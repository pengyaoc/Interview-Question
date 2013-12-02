#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > ret;
    int size = num.size();
    int begin, end;
    sort(num.begin(), num.end());
    for (int i=0; i<size-3; i++)
    {
        if (i != 0 && num[i] == num[i-1])
            continue;
        for (int j=i+1; j<size-2; j++)
        {
            if (j != i+1 && num[j] == num[j-1])
                continue;
                
            begin = j+1;
            end = size-1;
            // two pointers
            while (begin < end)
            {
                int sum = num[i]+num[j]+num[begin]+num[end];
                if (begin != j+1 && num[begin] == num[begin-1])
                {
                    begin++;
                }
                else if (end != size-1 && num[end] == num[end+1])
                {
                    end--;
                }              
                else if (sum == target)
                {
                    vector<int> nums = {num[i], num[j], num[begin], num[end]};
                    ret.push_back(nums);
                    begin++; end--;
                }
                else if (sum < target)
                {
                    begin++;
                }
                else
                {
                    end--;
                }
            }
        }
    }
    return ret;
}

int main()
{
    vector<int> num = {1,0,-1,0,-2,2};
    vector<vector<int> > ret = fourSum(num, 0);
    for (int i=0; i<ret.size(); i++)
    {
        for (int j=0; j<ret[i].size(); j++)
            cout << ret[i][j] << " ";
        cout << endl;
    }
}
