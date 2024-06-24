class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int j = 0; // Pointer for the position of the next element to keep

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[j] = nums[i];
                j++;
            }
        }

        return j; // The new length of the array
    }
};
