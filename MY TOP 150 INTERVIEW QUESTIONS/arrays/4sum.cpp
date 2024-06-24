class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int a = 0; a < n; a++)
        {
            for (int b = a + 1; b < n; b++)
            {
                int c = b + 1;
                int d = n - 1;
                while (c < d)
                {
                    long long sum = nums[a];
                    sum += nums[b];
                    sum += nums[c];
                    sum += nums[d];
                    if (sum < target)
                    {
                        c++;
                    }
                    else if (sum > target)
                    {
                        d--;
                    }
                    else
                    {
                        vector<int> v = {nums[a], nums[b], nums[c], nums[d]};
                        // if new quads then push to main vector
                        if (find(ans.begin(), ans.end(), v) == ans.end())
                        {
                            ans.push_back(v);
                        }
                        c++;
                        d--;
                    }
                }
            }
        }
        return ans;
    }
};

// Working with Example:
// Given nums = {1, 0, -1, 0, -2, 2} and target = 0, let's go through the loops:

// Sorted nums: {-2, -1, 0, 0, 1, 2}.
// For a = 0 (nums[a] = -2):
// For b = 1 (nums[b] = -1):
// c = 2 (nums[c] = 0), d = 5 (nums[d] = 2):
// Sum = -2 + -1 + 0 + 2 = -1 < 0, so c++.
// c = 3 (nums[c] = 0), d = 5 (nums[d] = 2):
// Sum = -2 + -1 + 0 + 2 = -1 < 0, so c++.
// c = 4 (nums[c] = 1), d = 5 (nums[d] = 2):
// Sum = -2 + -1 + 1 + 2 = 0 = 0, so add {-2, -1, 1, 2} to ans.
// For b = 2 (nums[b] = 0):
// c = 3 (nums[c] = 0), d = 5 (nums[d] = 2):
// Sum = -2 + 0 + 0 + 2 = 0 = 0, so add {-2, 0, 0, 2} to ans.
// For b = 3 (nums[b] = 0), skip as it is a duplicate of b = 2.
// For a = 1 (nums[a] = -1):
// For b = 2 (nums[b] = 0):
// c = 3 (nums[c] = 0), d = 5 (nums[d] = 2):
// Sum = -1 + 0 + 0 + 2 = 1 > 0, so d--.
// c = 3 (nums[c] = 0), d = 4 (nums[d] = 1):
// Sum = -1 + 0 + 0 + 1 = 0 = 0, so add {-1, 0, 0, 1} to ans.
// For b = 3 (nums[b] = 0), skip as it is a duplicate of b = 2.
// Continue similarly for other values of a.