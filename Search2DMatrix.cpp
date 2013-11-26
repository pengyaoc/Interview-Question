bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int m = matrix.size();
    int n;
    if (m != 0)
        n = matrix[0].size();
    else
        return false;
    int start = 0;
    int end = m*n-1;
    int mid;
    int i,j;
    while (start <= end)
    {
        mid = (start + end)/2;
        if (matrix[mid/n][mid%n] == target)
            return true;
        else if (matrix[mid/n][mid%n] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}
