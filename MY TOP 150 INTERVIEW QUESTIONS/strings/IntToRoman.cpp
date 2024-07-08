class Solution
{
public:
    string intToRoman(int num)
    {
        string roman = "";
        // creating a vector pair to store roman numeral values
        vector<pair<int, string>> storeIntroman = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}};

        // Iterating through vectors and repeatedly adds corresponding symbol
        for (int i = 0; i < storeIntroman.size(); i++)
        {
            while (num >= storeIntroman[i].first)
            {
                roman += storeIntroman[i].second;
                num -= storeIntroman[i].first;
            }
        }
        return roman;
    }
};

// Step - by - Step Execution :

// i = 0,
// num = 3549 : num >= 1000 : roman += "M", num = 2549 num >= 1000 : roman += "M", num = 1549 num >= 1000 : roman += "M", num = 549 i = 1, num = 549 : num < 900(skip)i = 2, num = 549 : num >= 500 : roman += "D", num = 49 i = 3, num = 49 : num < 400(skip)i = 4, num = 49 : num < 100(skip)i = 5, num = 49 : num < 90(skip)i = 6, num = 49 : num >= 40 : roman += "XL", num = 9 i = 7, num = 9 : num < 10(skip)i = 8, num = 9 : num < 9(skip)i = 9, num = 9 : num >= 9 : roman += "IX", num = 0 Remaining iterations do not modify roman as num is now 0.