class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(strcmp(needle,"") == 0)
            return haystack;
        if(strcmp(haystack,"") == 0)
            return NULL;
        char *pos_l = haystack;
        char *pos_r = haystack;
        char *pos2 = needle;
        
        while(*pos_r && *pos2){
            pos_r++;
            pos2++;
        }
        if(*pos2)
            return NULL;
        pos_r--;
        while(*pos_r){
            char *tmppos_l = pos_l;
            pos2 = needle;
            while(tmppos_l <= pos_r){
                if(*tmppos_l != *pos2)
                    break;
                tmppos_l++;
                pos2++;
            }
            if(!(*pos2))
                return pos_l;
            pos_l++;
            pos_r++;
        }
        return NULL;
    }
};