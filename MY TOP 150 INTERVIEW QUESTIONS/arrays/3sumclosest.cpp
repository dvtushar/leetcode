class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int ans = 0;

        for (int i = 0; i < n; i++) // fixating the first element
        {
            int first = nums[i]; // first element
            int start = i + 1;
            int end = n - 1;

            while (start < end)
            {
                if (first + nums[start] + nums[end] == target)
                {
                    return target;
                }
                else if (abs(first + nums[start] + nums[end] - target) < diff)
                {
                    diff = abs(first + nums[start] + nums[end] - target);
                    ans = first + nums[start] + nums[end];
                }

                if (first + nums[start] + nums[end] > target)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
        return ans;
    }
};