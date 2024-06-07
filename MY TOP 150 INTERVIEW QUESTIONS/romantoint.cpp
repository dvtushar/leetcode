class Solution {
public:
    int getvalue(char c){
        switch(c){
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            case 'L' : return 50;
            default : return -1;

        }
    }
    int romanToInt(string s) {
        int res = 0;
        int i = 0;
        while(i<s.size()-1){
            if(getvalue(s[i])>=getvalue(s[i+1])){
                res += getvalue(s[i]);
            }
            else{
                res -= getvalue(s[i]);
            }
            i++;
        }
        res +=getvalue(s[i]);
        return res;
        }
};