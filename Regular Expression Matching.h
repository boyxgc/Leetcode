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