class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int maxlength = 0;
        unordered_set<char> charset;
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            if (charset.count(s[right]) == 0)
            {
                charset.insert(s[right]);
                maxlength = max(maxlength, right - left + 1);
            }
            else
            {
                while (charset.count(s[right]))
                {
                    charset.erase(s[left]);
                    left++;
                }
                charset.insert(s[right]);
            }
        }
        return maxlength;
    }
};
// ### Program Logic

// 1. **Initialization**:
//     - `n`: The length of the input string `s`.
//     - `maxlength`: To store the length of the longest substring without repeating characters.
//     - `charset`: An unordered set to keep track of characters in the current window of the substring.
//     - `left`: Left index of the current window.

// 2. **Sliding Window Technique**:
//     - Iterate through the string using the `right` index.
//     - For each character `s[right]`:
//         - If `s[right]` is not in `charset`, add it to the set and update `maxlength` if the current window size (`right - left + 1`) is greater than `maxlength`.
//         - If `s[right]` is in `charset`, there are duplicate characters in the current window. Move the `left` pointer to the right, removing characters from `charset`, until `s[right]` can be added without duplicates.

// 3. **Return the maximum length of the substring found**.

// ### Dry Run Example

// Let's use the string `"abcabcbb"` for the dry run.

// 1. **Initialization**:
//     - `s = "abcabcbb"`
//     - `n = 8`
//     - `maxlength = 0`
//     - `charset = {}`
//     - `left = 0`

// 2. **Iteration**:

//     - `right = 0`, `s[right] = 'a'`
//         - `'a'` is not in `charset`. Add `'a'` to `charset`.
//         - Update `maxlength = max(0, 0 - 0 + 1) = 1`.
//         - `charset = {'a'}`

//     - `right = 1`, `s[right] = 'b'`
//         - `'b'` is not in `charset`. Add `'b'` to `charset`.
//         - Update `maxlength = max(1, 1 - 0 + 1) = 2`.
//         - `charset = {'a', 'b'}`

//     - `right = 2`, `s[right] = 'c'`
//         - `'c'` is not in `charset`. Add `'c'` to `charset`.
//         - Update `maxlength = max(2, 2 - 0 + 1) = 3`.
//         - `charset = {'a', 'b', 'c'}`

//     - `right = 3`, `s[right] = 'a'`
//         - `'a'` is in `charset`. Move `left` until `'a'` can be added.
//             - `left = 1`, `charset = {'b', 'c'}`
//         - Add `'a'` to `charset`.
//         - `maxlength` remains `3`.
//         - `charset = {'b', 'c', 'a'}`

//     - `right = 4`, `s[right] = 'b'`
//         - `'b'` is in `charset`. Move `left` until `'b'` can be added.
//             - `left = 2`, `charset = {'c', 'a'}`
//         - Add `'b'` to `charset`.
//         - `maxlength` remains `3`.
//         - `charset = {'c', 'a', 'b'}`

//     - `right = 5`, `s[right] = 'c'`
//         - `'c'` is in `charset`. Move `left` until `'c'` can be added.
//             - `left = 3`, `charset = {'a', 'b'}`
//         - Add `'c'` to `charset`.
//         - `maxlength` remains `3`.
//         - `charset = {'a', 'b', 'c'}`

//     - `right = 6`, `s[right] = 'b'`
//         - `'b'` is in `charset`. Move `left` until `'b'` can be added.
//             - `left = 4`, `charset = {'a', 'c'}`
//             - `left = 5`, `charset = {'c'}`
//         - Add `'b'` to `charset`.
//         - `maxlength` remains `3`.
//         - `charset = {'c', 'b'}`

//     - `right = 7`, `s[right] = 'b'`
//         - `'b'` is in `charset`. Move `left` until `'b'` can be added.
//             - `left = 6`, `charset = {'b'}`
//         - Add `'b'` to `charset`.
//         - `maxlength` remains `3`.
//         - `charset = {'b'}`

// 3. **Return**:
//     - The maximum length found is `3`.

// Thus, the length of the longest substring without repeating characters in the string `"abcabcbb"` is `3`.