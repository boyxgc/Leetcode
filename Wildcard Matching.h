class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char* star =NULL;
        const char*ss;
        
        while(*s) {
            if(*s == *p || *p == '?') {
                s++;
                p++;
                continue;
            }
            if(*p == '*') {
                star = p++;
                ss = s;
                continue;
            }
            if(star){
                s = ++ss;
                p = star+1;
                //star = NULL; //* represents any sequence
                continue;
            }
            return false;
        }
        while(*p == '*'){p++;}
        return !(*p);
    }
    
};