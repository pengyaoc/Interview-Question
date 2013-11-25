#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*void wordBreak(string s, int index, string current, int spaceAdded,
                vector<string>& ret, unordered_set<string> &dict, vector<vector<bool> > &dp)
{
    string origin = current;   
    for (int j=index; j<s.size(); j++)
    {
        if (dp[index][j])
        {
            if (j+1+spaceAdded != current.size())
            {
                current.insert(j+1+spaceAdded, " ");
            }
            else
            {
                ret.push_back(current);
            }
            wordBreak(s, j+1, current, spaceAdded+1, ret, dict, dp);
        }
        current = origin;
    }
}

vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<string> ret;
    
    if (s.size() == 0)
        return ret;
        
    vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
    
    for (int i=0; i<s.size(); i++)
    {
        for (int j=i; j<s.size(); j++)
        {
            dp[i][j] = (dict.find(s.substr(i, j-i+1)) != dict.end());
        }
    }
        
    wordBreak(s, 0, s, 0, ret, dict, dp);
    return ret;
}*/

void backTrace(vector<vector<int> >& bt, int index, string s, string current, vector<string>& ret)
{
    string origin = current;
    
    if (index == -1)
    {
        ret.push_back(current);
        return;
    }
    
    for (int j=0; j<bt[index].size(); j++)
    {
        string x;
        if (current.size() != 0)
            x = " " + current;
        current = s.substr(bt[index][j], index-bt[index][j]+1) + x;
        backTrace(bt, bt[index][j]-1, s, current, ret);
        current = origin;
    }
}

vector<string> wordBreak(string s, unordered_set<string> &dict) {    
    vector<string> ret;
    if (s.size() == 0)
        return ret;
        
    vector<vector<int> > bt(s.size());
    
    for (int i=0; i<s.size(); i++)
    {
        for (int j=i; j<s.size(); j++)
        {
            if (dict.find(s.substr(i, j-i+1)) != dict.end())
            {
                bt[j].push_back(i);
            }
        }
    }
    backTrace(bt, s.size()-1, s, "", ret);
    return ret;
}

int main()
{
    unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
    string s = "catsanddog";
    vector<string> out = wordBreak(s, dict);
    for (int i=0; i<out.size(); i++)
    {
        cout << out[i] << endl;
    }
}
