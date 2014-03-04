class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        int tmp = 0;
        
        string tmpstr;
        for(int unit = 1000; unit > 0; unit = unit/10) {
            tmpstr = "";
            tmp = num/unit;
            if(tmp > 0) {
                switch (unit){
                    case 1000:
                        tmpstr = repeator(tmp, "M");// below 3999
                        break;
                    case 100:
                        tmpstr = generator(tmp,"C","D","M");
                        break;
                    case 10:
                        tmpstr = generator(tmp,"X","L","C");
                        break;
                    case 1:
                        tmpstr = generator(tmp,"I","V","X");
                        break;
                }
            }
            
            num = num%unit;
            res += tmpstr;  
        }
        
        return res;
        
    }
    
    string repeator(int n, string str) {
        string res = "";
        while(n-- > 0)
            res += str;
        return res;
    }
    
    string generator(int tmp, string one, string five, string ten) {
        string tmpstr = "";
        if(tmp < 4)
            tmpstr = repeator(tmp, one);
        else if(tmp == 4)
            tmpstr = one+five;
        else if(tmp == 5)
            tmpstr = five;
        else if(tmp < 9)
            tmpstr = five+repeator(tmp-5, one);
        else
            tmpstr = one+ten;
        return tmpstr;
    }
};