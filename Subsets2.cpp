#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetsWithDup(vector<int> &s, vector<vector<int> >& ret, int index, vector<int>& current)
{
    for (int i=index; i<s.size(); i++)
    {
        if (i != index && s[i-1] == s[i])
            continue;
                    
        current.push_back(s[i]);
        ret.push_back(current);
        subsetsWithDup(s, ret, i+1, current);
        current.pop_back();
    }
}

vector<vector<int> > subsetsWithDup(vector<int> &s) {
    sort(s.begin(), s.end());
    vector<vector<int> > ret;
    vector<int> current;
    
    // empty set
    ret.push_back(current);
    
    subsetsWithDup(s, ret, 0, current);
    return ret;
}

int main()
{
    vector<int> s = {1,2,2};
    vector<vector<int> > ret = subsetsWithDup(s);
    for (int i=0; i<ret.size(); i++)
    {
        for (int j=0; j<ret[i].size(); j++)
            cout << ret[i][j] << " ";
        cout << endl;
    }
}
