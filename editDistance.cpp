#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int minDistance(string word1, string word2) {
    // edit distance dp matrix starts from "" to word1,
    // so size is word size+1
    int word1Size = word1.size();
    int word2Size = word2.size();
    
    vector<vector<int> > dp(word1Size+1, vector<int>(word2Size+1,0));
    // Set first row and column
    for (int i=0; i<=word1Size; i++)
    {
        dp[i][0] = i;
    }
    for (int i=0; i<=word2Size; i++)
    {
        dp[0][i] = i;
    }
    // fill in the matrix
    for (int i=1; i<=word1Size; i++)
    {
        for (int j=1; j<=word2Size; j++)
        {
            dp[i][j] = min(
                        dp[i][j-1]+1,   //delete
                        dp[i-1][j]+1   //insert
                        );
            dp[i][j] = min(
                        dp[i][j],
                        dp[i-1][j-1]+((word1[i-1] == word2[j-1])?0:1) //replace
                        );
        }
    }
    return dp[word1Size][word2Size];
}

int main(){}
