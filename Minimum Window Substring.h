class Solution {
public:
    //elegant!!
    string minWindow(string S, string T) {
        int needFind[256] = {0};
        int hasFind[256] = {0};
        for(int i = 0; i < T.size(); ++i) needFind[T[i]]++;
        
        int count = 0;
        int minWinLen = S.size()+1;
        int minWinStart = -1;
        for(int begin = 0, end = 0; end < S.size(); ++end){
            if(needFind[S[end]] == 0)
                continue; 
            
            if(hasFind[S[end]] < needFind[S[end]]) count++;
            hasFind[S[end]]++;
            
            if(count == T.size()) {
                while(needFind[S[begin]] == 0 || hasFind[S[begin]] > needFind[S[begin]]){
                    if(hasFind[S[begin]] > needFind[S[begin]])
                        hasFind[S[begin]]--;
                    begin++;
                }
                if(end-begin+1 < minWinLen){
                    minWinLen = end-begin+1;
                    minWinStart = begin;
                }
            }
        }
        if(minWinStart != -1){
            return S.substr(minWinStart, minWinLen);
        } else{
            return "";
        }
    }

    /*
    string minWindow(string S, string T) {
        map<char, int> mapT;
        map<char, int> mapS;
        for(int i = 0; i < S.size(); ++i)
            mapS[S[i]]++;
        for(int i = 0; i < T.size(); ++i)
            mapT[T[i]]++;
        
        for(auto it = mapT.begin(); it != mapT.end(); ++it){
            if(it->second > mapS[it->first]) return "";
        }
        
        int minlen = S.size();
        int minst = 0;
        
        int p = 0;
        int q = S.size()-1;
        while(q-p+1 >= T.size()) {
            if(q-p+1 < minlen){
                minlen = q-p+1;
                minst = p;
            }
            if(mapT.find(S[p]) == mapT.end()){
                mapS[S[p]] -= 1;
                p++;  //skip irrelevent s[p]
                continue;
            }
            //try to move q
            if(mapT.find(S[q]) == mapT.end()){
                mapS[S[q]] -= 1;
                q--;
            } else {// move q
                if(mapS[S[q]] - 1 >= mapT[S[q]]){
                    mapS[S[q]] -= 1;
                    q--;
                }else {// find the char S[p] to make sure new p:q covers T
                    if(mapS[S[p]] - 1 >= mapT[S[p]]){
                        mapS[S[p]] -= 1;
                        p++;
                    } else {
                        q++;
                        while(q < S.size() && S[q] != S[p]){
                            mapS[S[q]] += 1;
                            q++;
                        }
                        if(q == S.size() || S[q] != S[p]) return S.substr(minst, minlen);
                        p++;
                    }
                }
            }
            
        }
        return S.substr(minst, minlen);
    }*/
};