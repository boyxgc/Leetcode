class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!haystack || !needle) return NULL;
        int lenh = strlen(haystack);
        int lenn = strlen(needle);
        if( lenh < lenn) return NULL;
        
        for(int i = 0; i < lenh - lenn +1; ++i) {
            if(check(haystack+i, needle)) {
                return haystack+i;
            }
        }
        
        return NULL;
    }
    
    bool check(char *h, char *n) {
        while(*h != '\0' && *n != '\0') {
            if(*h != *n) return false;
            h++;
            n++;
        }
        return true;
    }
};