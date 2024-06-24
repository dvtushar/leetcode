class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int piv = -1; // Initialize pivot

        // Find the pivot where the array is rotated
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1])
            {
                piv = mid + 1;
                break;
            }
            if (nums[mid] >= nums[low])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        // If no pivot is found, the array is not rotated
        if (piv == -1)
        {
            piv = 0;
        }

        low = 0;
        high = nums.size() - 1;

        // Determine the search range based on the pivot
        if (target >= nums[piv] && target <= nums[high])
        {
            low = piv;
        }
        else
        {
            high = piv - 1;
        }

        // Binary search in the determined range
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return -1; // Target not found
    }
};
