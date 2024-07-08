#include <bits/stdc++.h>

class Solution
{
public:
    int check(string s, int p1, int p2, int &st, int &en)
    {
        int count = 0;

        if (p1 == p2)
        {
            count++;
            p1--;
            p2++;
        }

        while (p1 >= 0 and p2 < s.length())
        {
            if (s[p1] != s[p2])
            {
                st = p1 + 1;
                en = p2 - 1;
                return count;
            }
            else
            {
                p1--;
                p2++;
                count += 2;
            }
        }
        st = p1 + 1;
        en = p2 - 1;
        return count;
    }
    string longestPalindrome(string s)
    {

        int st = -1;
        int en = -1;

        int len = 0;

        // it will contain starting point of palindromic subs
        int final_s = -1;
        // it will contain the end point of palindromic subs
        int final_e = -1;

        for (int i = 0; i < s.length(); i++)
        {

            // giving longest palindromic subs of odd length
            int x = check(s, i, i, st, en);
            if (x > len)
            {
                len = x;
                final_s = st;
                final_e = en;
            }
            // giving longest palindromic subs of even length
            int y = check(s, i, i + 1, st, en);
            if (y > len)
            {
                len = y;
                final_s = st;
                final_e = en;
            }
        }

        return s.substr(final_s, final_e - final_s + 1);
    }
};