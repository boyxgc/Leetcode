class Solution {
public:
    int romanToInt(string s) {
        int currMaxUnit = 1;// current max unit, from right to left
        int sum = 0;
        for(int i = s.length() -1; i >= 0; i--) {
            int num = char2int(s[i]);
            if(num < currMaxUnit) 
                num = -num;
            else
                currMaxUnit = num;
                
            sum += num;
        }
        return sum;
    }
    
    int char2int(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }
};