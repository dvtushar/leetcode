#include <bits/stdc++.h>
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // swap to make a transpose first then reverse the order of array.

        int n = matrix.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};