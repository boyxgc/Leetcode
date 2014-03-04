class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        //step 1: assign each word its level
        //step 2: calculate blanks
        //step 3: output
        vector<string> ret;
        if(L == 0){
            ret.push_back("");
            return ret;
        }
        int pos = 0;
        while(pos < words.size()) {
            int orgpos = pos;
            int len = words[pos].size();
            int orglen = len;
            while(len < L && pos+1 < words.size()){// find words in this bracket
                pos++;
                orglen = len;
                len += 1 + words[pos].size();
            }
            if(len > L){
                len = orglen;
                pos--;
            }
            // now words from orgpos to pos(both bound included) are in the same bracket
            string str = "";
            int extraWs = L-len;
            if(pos < words.size()-1){// not sentence end
                if(pos == orgpos){// only one word
                    str = words[pos];
                    str.append(extraWs,' ');
                } else {// multiple words
                    int avgWs = extraWs/(pos-orgpos);
                    int leftWs = extraWs - avgWs*(pos-orgpos);
                    
                    str =words[orgpos];
                    for(int i = orgpos+1; i <= pos; ++i){
                        if(leftWs-- > 0){
                            str.append(" ");
                        }
                        str.append(avgWs, ' ');
                        str.append(" "+words[i]);
                    }
                }
            } else {//sentence end
                str =words[orgpos];
                for(int i = orgpos+1; i <= pos; ++i){
                    str += " "+words[i];
                }
                str.append(extraWs,' ');
            }
            pos++;
            ret.push_back(str);
        }
    }
};