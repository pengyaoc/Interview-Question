#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, int index, unordered_set<string> &dict)
{
    for (int i=index; i<s.size(); i++)
    {
        if (dict.find(s.substr(index, i-index+1)) != dict.end() && wordBreak(s, i+1, dict))
        {
            return true;
        }
    }
    return false;
}

bool wordBreak(string s, unordered_set<string> &dict) {
    return wordBreak(s, 0, dict);
}

int main() {}
