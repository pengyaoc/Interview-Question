#include <iostream>
#include <vector>
#include <string>
using namespace std;

void partitionHelper(string& s, int index, 
                            vector<vector<bool> >& dp, vector<string> previous, vector<vector<string> >& ret)
{
    if (index >= s.size())
    {
        /*cout << "Got to the end: "<< index << endl;
        for (int i=0; i<previous.size(); i++)
        {
            for (int j=0; j<previous[i].size(); j++)
            {
                cout << previous[i][j] << " ";
            }
            cout << endl;
        }*/
        ret.push_back(previous);
    }
    for (int l=0; l<s.size()-index; l++)
    {
        if (dp[index][l])
        {
            //cout << s.substr(index, l+1) << endl;
            previous.push_back(s.substr(index, l+1));
            //cout << "index: " << index+l+1 << endl;
            partitionHelper(s, index+l+1, dp, previous, ret);
            previous.pop_back();
        }
    }
    
        /*for (int i=0; i<ret.size(); i++)
        {
            for (int j=0; j<ret[i].size(); j++)
            {
                cout << ret[i][j] << " ";
            }
            cout << endl;
        }*/
}

vector<vector<string> > partition(string s) {
    // process the string to determine which are palindrome
    int size = s.size();
    vector<vector<bool> > dp(size, vector<bool>(size, false));
    for (int l=1; l<=s.size(); l++)
    {
        for (int i=0; i<s.size()-l+1; i++)
        {
            if (l==1)
            {
                // when put in matrix, always do l-1
                dp[i][0] = true;
            }
            else if (l==2)
            {
                dp[i][1] = (s[i]==s[i+1]);
            }
            else
            {
                //cout << s[i] << " " << s[i+l-1] << " " << dp[i+1][l-3]<<endl;
                dp[i][l-1] = (s[i]==s[i+l-1]) && dp[i+1][l-3];
            }
            //cout << "dp["<<i<<","<<l-1<<"]="<<dp[i][l-1]<<endl;
        }
    }
    vector<string> previous;
    vector<vector<string> > ret;
    partitionHelper(s, 0, dp, previous, ret);
    return ret;
}

int main()
{
    string s = "efe";
    vector<vector<string> > ret = partition(s);
    cout << "ret size:" << ret.size() <<endl;
    for (int i=0; i<ret.size(); i++)
    {
        for (int j=0; j<ret[i].size(); j++)
        {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
}

