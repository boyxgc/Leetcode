class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        
        vector<string> words2put;
        int charscount = 0;
        for(int i = 0; i < words.size();++i) {
            string word = words[i];
            int wordsn = words2put.size();
            int tmp = charscount + wordsn/*spaces*/ + word.size();
            if(tmp > L) {
                int spaces = L - charscount;
                
                if(wordsn == 1) {
                    words2put[0] += string(spaces, ' ');
                } else {
                    int average = spaces/(wordsn-1);
                    int remain = spaces%(wordsn-1);
                    
                    for(int j = 0; j < wordsn-1; ++j) {
                        words2put[j] += string (average, ' ');
                        if(j < remain) words2put[j] += ' ';
                    }
                }
                string tmpstr = "";
                for(int j = 0; j < wordsn; ++j) {
                    tmpstr += words2put[j];
                }
                
                res.push_back(tmpstr);
                
                words2put.clear();
                charscount = 0;
                i--;
            } else {
                charscount += word.size();
                words2put.push_back(word);
                
                if(i == words.size()-1) { // last line
                    string tmpstr = "";
                    for(int j = 0; j < words2put.size(); ++j) {
                        tmpstr += words2put[j];
                        if(j < words2put.size()-1) {
                            tmpstr += ' ';
                        }
                    }
                    tmpstr += string(L-tmpstr.size(), ' ');
                    res.push_back(tmpstr);
                }
            }
        }
        
        return res;
    }
};