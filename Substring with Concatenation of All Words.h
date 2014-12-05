#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findSubstring(string S, vector<string> &L) {
    int wordlen = L[0].size();
    vector<int> res;
    
    unordered_map<string, int> wordcount;
    for(int i = 0; i < L.size(); ++i) {
        wordcount[L[i]]++;
    }
    
    for(int i = 0; i < wordlen; ++i) {
        int count = 0;
        unordered_map<string, int> wordcount2;
        for(int begin = i, end = i; end + wordlen -1 < S.size(); end += wordlen) {
            string word = S.substr(end, wordlen);
            if(wordcount.find(word) == wordcount.end()) {
                begin = end + wordlen;
                count = 0;
                wordcount2.clear();
            } else {
                wordcount2[word]++;
                count++;
                if(wordcount2[word] > wordcount[word]) {
                    while(begin <= end) {
                        string tmp = S.substr(begin, wordlen);
                        wordcount2[tmp]--;
                        begin += wordlen;
                        count--;
                        if(tmp == word) {
                            break;
                        }
                    }
                }
                
                if(count == L.size()) {
                    res.push_back(begin);   
                }
            }
        }
    }
    
    return res;
}

int main() {

    string S = "lingmindraboofooowingdingbarrwingmonkeypoundcake";//"barfoothefoobarman";//
    string arr [] = {"fooo","barr","wing","ding","wing"};//{"foo", "bar"};//
    vector<string> L(arr, arr+5);

    vector<int> res = findSubstring(S, L);

    for(int i = 0; i < res.size(); ++i) cout << res[i] << endl;
}
/*
class Solution {
public:

    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        int wordlen = L[0].size();
        int lsize = L.size();
        if(lsize == 0)
            return ret;

        map<string, int> isShown;
        for(int i = 0; i < lsize; ++i) isShown[L[i]] += 1;
        
        for(int i = 0; i+wordlen*lsize-1 < S.size(); ++i) {
            map<string, int> map2;
            bool flag = true;
            for(int j = 0; j < lsize; ++j){
                string word = S.substr(i+j*wordlen, wordlen);
                if(isShown.find(word) == isShown.end()) {flag = false; break;}
                map2[word] += 1;
                if(map2[word] > isShown[word]) {flag = false; break;}
            }
            
            if(flag) ret.push_back(i);
            
        }
        return ret;
    }
}; */