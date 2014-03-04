class Solution {
public:
    bool isNumber(const char *s) {
        if(!(*s)) return false;
        while(*s && *s == ' ') s++;
        if(*s == '-' || *s == '+') s++;
        
        bool point = false;
        bool e = false;
        bool blank = false;
        
        if(*s == '.'){
            point = true;
            s++;
            if(!isdigit(*s)) return false;
        }
        if(!isdigit(*s)) return false;
 
        while(*s){
            if(isdigit(*s) && !blank){
                s++;
            } else {
                if(blank && *s != ' ') return false;// must all blank if there is one black
                
                if(*s == ' '){
                    blank = true;
                    s++;
                } else if(!e && !point && *s == '.'){// point shows before 'e'
                    point = true;
                    s++;
                } else if(!e && *s == 'e' 
                    && (isdigit(*(s+1)) || (*(s+1) == '-' || *(s+1) == '+') && isdigit(*(s+2)))){// e followed by digit or '+'digit or '-'digit
                    e = true;
                    s++;
                } else if((*s == '-' || *s == '+') && *(s-1) == 'e'){
                    s++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};