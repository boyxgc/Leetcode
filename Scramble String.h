class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
            return true;
        if(s1.size() != s2.size())
            return false;
        int size = s1.size();
        /*
        //pruning 1
        int val1 = 0;
        int val2 = 0;
        for(int i = 0; i < size; ++i) {
            val1 += s1[i]-'a';
            val2 += s2[i]-'a';
        }
        if(val1 != val2)
            return false;
            */
        //pruning 2
        int A[26];
        memset(A, 0, sizeof(int)*26);
        for(int i = 0; i < size; ++i){
            A[s1[i]-'a']++;
        }
        for(int i = 0; i < size; ++i){
            A[s2[i]-'a']--;
        }
        for(int i = 0; i < size; ++i){
            if(A[s1[i]-'a'] != 0)
                return false;
        }
        for(int i = 1; i < size; ++i) {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            if(isScramble(s11, s2.substr(0, i)) && isScramble(s12, s2.substr(i)))
                return true;
            if(isScramble(s11, s2.substr(size-i)) && isScramble(s12, s2.substr(0,size-i)))
                return true;
        }
        return false;
    }
};