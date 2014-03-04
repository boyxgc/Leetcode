class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int size = 0;
        const char *s1 = s;
        while(*(s1++)) {
            size++;
        }
        
        int lastword = size-1;
        while(lastword >= 0 && s[lastword] == ' ')
            lastword--;
        int lastwordsize = 0;
        while(lastword >= 0 && s[lastword] != ' '){
            lastwordsize++;
            lastword--;
        }
            
        return lastwordsize;
    }
};