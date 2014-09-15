/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

class Solution {
public:
    void reverseWords(string &s) {
       
        string res = "";
        string word = "";
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' '){
                if(!word.empty()) {
                    res = word + " " + res;
                }
                word.clear();
            } else {
                word =  word + s[i];
            }
        }
        if(!word.empty()) {
            res = word + " " + res;
        }
        if(res.back() == ' ' ) res.pop_back();
        s = res;
    }
};