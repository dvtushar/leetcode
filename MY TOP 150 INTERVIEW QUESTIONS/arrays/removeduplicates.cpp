class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int n = nums.size();
        int j = 0; // Index of the last unique element

        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[j])
            {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};

// How the Code Works : The initial vector might look like this : [ 1, 1, 2, 2, 3 ].j starts at 0, pointing to the first element.The loop begins with i = 1 : Since nums[1](1) equals nums[0](1), j doesn't move. When i = 2 : nums[2](2) is different from nums[0](1).j increments to 1, and nums[1] is set to nums[2].The array now looks like[1, 2, 2, 2, 3].When i = 3 : nums[3](2) equals nums[1](2), so j doesn't move. When i = 4 : nums[4](3) is different from nums[1](2).j increments to 2, and nums[2] is set to nums[4].The array now looks like[1, 2, 3, 2, 3].After the loop finishes, j is 2, and the new length of the unique elements is j + 1, which is 3. The first three elements of the array([ 1, 2, 3 ]) are the unique elements.