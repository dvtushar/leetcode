class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int start = -1, end = -1;

        // Iterate over the array to find the start position
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                start = i;
                break;
            }
        }

        // If start is not found, return [-1, -1]
        if (start == -1)
        {
            return {-1, -1};
        }

        // Iterate from the end to find the end position
        for (int j = n - 1; j >= start; j--)
        {
            if (nums[j] == target)
            {
                end = j;
                break;
            }
        }

        return {start, end};
    }
};
