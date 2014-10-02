class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*s == '\0') {
            if(*p == '\0'){
                return true;  
            } else if (strlen(p) >= 2 && *(p+1) == '*') {
                return isMatch(s, p+2);
            } else {
                return false;
            }
        }
        
        if(*p == '\0') return false;
        
        if(*(p+1) == '*') {
            if(*p == '.') {
                for(int i = 0; i <= strlen(s); ++i) {
                    if(isMatch(s+i, p+2)) return true;
                }
                return false;
            } else {
                int count = 0;
                const char * tmp = s;
                while(*tmp == *p) {
                    count++;
                    tmp++;
                }
                for(int i = 0; i <= count; ++i) {
                    if(isMatch(s+i, p+2)) return true;
                }
                return false;
            }
        } else {
            if(*p == '.') {
                return isMatch(s+1, p+1);
            } else {
                if(*s != *p) return false;
                return isMatch(s+1, p+1);
            }
        }
    }
};

class Solution {
public:
    int lenof(const char *s, char c){
        int len = 0;
        while(*s && (*s == c || c == '.')) {
            s++;
            len++;
        }
        return len;
    }
    
    bool isMatch(const char *s, const char *p) {
        if(!*s && !*p) return true;
        if(!*s){
            if(*(p+1) != '*') return false;
            p++;
            while(*p == '*') p++;
            return isMatch(s, p);
        }
        if(!*p)
            return false;
        if(*s != *p){
            if(*p == '.'){
                if(*(p+1) != '*')
                    return isMatch(s+1, p+1);
                bool flag = false;
                for(int i = 0; i <= lenof(s, '.'); ++i){// dfs
                    flag = isMatch(s+i, p+2);
                    if(flag) return true;
                }
                return false;
            } else {
                if(*(p+1) != '*')
                    return false;
                return isMatch(s, p+2);
            }
        } else{
            if(*(p+1) != '*')
                return isMatch(s+1, p+1);
            bool flag = false;
            for(int i = 0; i <= lenof(s, *s); ++i){
                flag = isMatch(s+i, p+2);
                if(flag) return true;
            }
            return false;
        }
    }
};