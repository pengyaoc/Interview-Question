#include <iostream>
#include <algorithm>
using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "" || num2 == "")
        return "";
    string ret(10000, '0');
    int size = 1;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int temp; //Not zero would be good
    for (int i=0; i<num1.size(); i++)
    {
        for (int j=0; j<num2.size(); j++)
        {
            temp = (num1[i] - '0') * (num2[j] - '0');
            for (int idx = 0; temp != 0; idx++)
            {
                temp += ret[i+j+idx] - '0';
                ret[i+j+idx] = char(temp % 10 + '0');
                temp /= 10;
                size = i+j+idx+1;
            }
        }
    }
    ret = ret.substr(0, size);
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    cout << multiply("123","456") << endl;
}
