class Solution {
public:
    int atoi(const char *str) {
        const char *neg = NULL;
        
        while(*str == ' ') str++;
        if(!isdigit(*str)) {
            if(*str == '-'){
                neg = str;
            } else if(*str == '+') {
                neg = NULL;
            } else {
                return 0;
            }
            str++;
        }
        
        int res = 0;
        while(isdigit(*str)) {
            char c = *str;
            if(res > INT_MAX/10){
                if(neg) return INT_MIN;
                else return INT_MAX;
            }
            
            if(res == INT_MAX/10) {
                if(neg && c >= '8') return INT_MIN;
                if(!neg && c >= 7) return INT_MAX;
            }
            
            res = res*10 + c-'0';
            str++;
        }
        
        return neg ? -res : res;
    }
};