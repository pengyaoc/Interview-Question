#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, int index, unordered_set<string> &dict, vector<int>& mem)
{
    bool ret = false;
    for (int i=index; i<s.size(); i++)
    {
        if (dict.find(s.substr(index, i-index+1)) != dict.end())
        {
            if (i+1 == s.size())
            {
                ret = true;
                break;
            }
            if (mem[i+1] == -1)
            {
                wordBreak(s, i+1, dict, mem);
            }
            if (mem[i+1] == 1)
            {
                ret = true;
                break;
            }
        }
    }
    mem[index] = ret ? 1 : 0;
    return ret;
}

bool wordBreak(string s, unordered_set<string> &dict) {
    vector<int> mem(s.size(), -1);
    return wordBreak(s, 0, dict, mem);
}

int main() {
    unordered_set<string> a = {"aaaa", "aaa", "aaaaaaaaaa"};
    cout << wordBreak("aaaaaaaaaaaaaa", a) << endl;
}
