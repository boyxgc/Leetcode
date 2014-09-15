class Solution {
public:
    int numDecodings(string s) {
        
        int size = s.size();
        if(size == 0) return 0;
        
        vector<int> decos(size, 0);
        
        decos[0] = s[0] != '0';
        for(int i = 1; i < size; ++i) {
            int way1 = (s[i] != '0') * decos[i-1];
            int way2 = 0;
            if(s[i-1] > '0' && s[i-1] < '3') {
                if(s[i-1] != '2' || s[i] <= '6'){
                    if(i-2 >= 0) way2 = decos[i-2];
                    else way2 = 1;
                }
            }
            decos[i] = way1 + way2;
        }
        
        return decos[size-1];
    }
};