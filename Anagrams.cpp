#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

vector<string> anagrams(vector<string> &strs) {
    // map sorted string to its index
    // If already in the output, set index to -1
    unordered_map<string, int> stringMap;
    string temp;
    vector<string> ret;
    for (int i=0; i<strs.size(); i++)
    {
        temp = strs[i];
        sort(temp.begin(), temp.end());
        auto itr = stringMap.find(temp);
        if (itr != stringMap.end())
        {
            // if already in the output
            if (itr->second != -1)
            {
                ret.push_back(strs[itr->second]);
                itr->second = -1;
            }
            ret.push_back(strs[i]);
        }
        else
        {
            stringMap.insert(make_pair(temp, i));
        }
    }
    return ret;
}

int main()
{
    
    
}
