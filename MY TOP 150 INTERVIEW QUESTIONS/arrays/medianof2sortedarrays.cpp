#include <bits/stdc++.h>
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // Merging the two sorted arrays
        vector<int> merged(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());
        // Sorting the merged array (not needed if nums1 and nums2 are already sorted)
        sort(merged.begin(), merged.end());

        int n = merged.size();
        // Check if the size of the vector is even or odd
        if (n % 2 == 0)
        {
            // If even, average the two middle values
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        }
        else
        {
            // If odd, return the middle value
            return merged[n / 2];
        }
    }
};