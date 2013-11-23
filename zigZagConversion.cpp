#include <iostream>

using namespace std;

// This version uses a flag called "onZig" which makes code cleaner
/*
string convert(string s, int nRows) {
    int index = 0;
    string ret;
    bool onZig = true;
    for (int i=0; i<nRows; i++)
    {
        index = i;
        onZig = true;
        while (index < s.size())
        {
            ret.append(1,s[index]);
            if (i == 0 || i == nRows-1)
            {
                index += 2*(nRows-1);
            }    
            else
            {
                index += onZig ? (nRows - i - 1)*2 : i*2;
                onZig = !onZig;
            }
        }
    }
    return ret;
}
*/

string convert(string s, int nRows) {
    int index = 0;
    string ret;
    // This line stops "Memory Limit Excceed"
    if (nRows==1) { return s; }
    for (int i=0; i<nRows; i++)
    {
        index = i;
        while (index < s.size())
        {
            ret.append(1,s[index]);
            if (i == 0 || i == nRows-1)
            {
                index += 2*(nRows-1);
            }    
            else
            {
                index += (nRows - i - 1)*2;
                if (index < s.size())
                {
                    ret.append(1,s[index]);
                    index += i*2;
                }
            }
        }
    }
    return ret;
}

int main()
{
    cout << convert("PAYPALISHIRING", 3) << endl;
}
