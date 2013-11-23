#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

// At most 2 transaction

int maxProfit(vector<int> &prices) {
    if (prices.size() == 0)
        return 0;
    // one transaction what's the max profit from day 0 to day i
    vector<int> profit(prices.size(), 0);
    int lowestPrice = INT_MAX;
    for (int i=0; i<prices.size(); i++)
    {
        lowestPrice = min(prices[i], lowestPrice);
        if (i == 0)
        {
            profit[0] = 0;
            continue;
        }
        profit[i] = max(profit[i-1], prices[i] - lowestPrice);
    }
    
    // one transaction what's the max profit from day i to the last day
    // also we can add profit[i] to this profit to calc the final answer right away
    int highestPrice = INT_MIN;
    int ret = profit[prices.size()-1];
    for (int i=prices.size()-1; i>0; i--)
    {
        highestPrice = max(prices[i], highestPrice);
        ret = max(ret, profit[i-1] + highestPrice - prices[i]);
    }
    return ret;
}

int main()
{
    vector<int> a = {3,2,6,5,0,3};
    cout << maxProfit(a) <<endl;

}
