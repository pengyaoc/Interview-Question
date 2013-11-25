int minimumTotal(vector<vector<int> > &triangle) {
    if (triangle.size() == 0)
    {
        return 0;
    }
    vector<int> sum(triangle.size(), 0);
    for (int i=triangle.size()-1; i>=0; i--)
    {
        for (int j=1; j<triangle[i].size(); j++)
        {   
            sum[j-1] = min(sum[j-1]+triangle[i][j-1], sum[j]+triangle[i][j]);
        }
        
    }
    return sum[0]+triangle[0][0];
}
