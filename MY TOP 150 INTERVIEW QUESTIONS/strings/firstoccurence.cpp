class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++)
        {
            int j = 0;
            for (; j < m; j++)
            {
                if (needle[j] != haystack[i + j])
                {
                    break;
                }
            }
            if (j == m)
            {
                return i;
            }
        }
        return -1;
    }
};

// Step-by-Step Execution:

// i = 0, haystack[0 + 0] = 'h' vs needle[0] = 'l' : Characters do not match.Inner loop breaks.i = 1, haystack[1 + 0] = 'e' vs needle[0] = 'l' : Characters do not match.Inner loop breaks.i = 2, haystack[2 + 0] = 'l' vs needle[0] = 'l' : Characters match.Continue to j = 1. haystack[2 + 1] = 'l' vs needle[1] = 'l' : Characters match.Inner loop completes(j == m).j == m is true, so return i = 2.