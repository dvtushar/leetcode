class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int s = 0, e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        int ans;
        while (s <= e)
        {
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
            {
                ans = mid + 1;
                s = mid + 1;
            }
            else
                e = mid - 1;
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};