class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string res = "1";

        for (int j = 2; j <= n; ++j)
        {
            string next;
            char cur = res[0];
            int cnt = 1;

            for (int i = 1; i < res.size(); ++i)
            {
                if (res[i] == cur)
                {
                    cnt++;
                }
                else
                {
                    next += to_string(cnt) + cur;
                    cur = res[i];
                    cnt = 1;
                }
            }
            next += to_string(cnt) + cur;
            res = next;
        }
        return res;
    }
};