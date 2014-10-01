class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end || start.size() != end.size()) return 0;
        
        unordered_set<string> q;
        
        q.insert(start);
        dict.insert(end);
        
        int level = 1;
        while(!q.empty()) {
            level++;
            for(auto it = q.begin(); it != q.end(); ++it) {
                dict.erase(*it);
            }
            unordered_set<string> tmpq;
            for(auto it = q.begin(); it != q.end(); ++it) {
                for(int i = 0; i < (*it).size(); ++i) {
                    string tmpword = *it;
                    for(char c = 'a'; c <= 'z'; ++c) {
                        tmpword[i] = c;
                        if(dict.find(tmpword) == dict.end()) continue;
                        if(tmpword == end) return level;
                        tmpq.insert(tmpword);
                    }
                }
            }
            q = tmpq;
        }
        
        return 0;
    }
};

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end || start.size() != end.size()) return 0;
        
        unordered_set<string> trans;
        queue<string> q;
        q.push(start);
        trans.insert(start);
        
        int level = 1;
        while(!q.empty()) {
            level ++;
            queue<string> q2;
            while(!q.empty()) {
                string front = q.front();
                q.pop();
                for(int i = 0; i < front.size(); ++i) {
                    string top = front;
                    for(char ch = 'a'; ch <= 'z'; ++ch) {
                        top[i] = ch;
                        if(trans.find(top) != trans.end()) continue;
                        if(dict.find(top) == trans.end()) continue;
                        if(top == end) {
                            return level;
                        }
                        trans.insert(top);
                        q2.push(top);
                    }
                }
            }
            q = q2;
        }
        
        return 0;
    }
};

// bi-direction BFS
class Solution {
public:
    struct Node {
      string word;
      int level;
      Node() {}
      Node(string s,int l){
          word = s;
          level = l;
      }
    };
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        map<string ,bool> flag_map;
        for(auto it = dict.begin(); it != dict.end(); ++it) {
            flag_map.insert(pair<string, bool>(*it, false));
        }
        
        queue<Node> q1;
        queue<Node> q2;
        
        Node n1(start, 1);
        q1.push(n1);
        //flag_map[start] = true;
        Node n2(end, 1);
        q2.push(n2);
        //flag_map[end] = true;
        
        while(!q1.empty() && !q2.empty() ) {
            string word = q1.front().word;
            int level1 = q1.front().level;
            int level2;
            q1.pop();

            if(!flag_map[word]) {
                flag_map[word] = true;
                level2 = inQueue(word, q2);
                if(level2 > 0) {
                    return level1+level2-1;
                }
                for(int i = 0; i < word.length(); ++i) {
                    string tmpword = word;
                    for(char c = 'a'; c <= 'z'; ++c) {
                        tmpword[i] = c;
                        if(tmpword == end)
                                return level1+1;
                        if(dict.find(tmpword) != dict.end()) {
                            if(!flag_map[tmpword]){
                                Node tmpnode(tmpword, level1+1);
                                //flag_map[tmpword] = true;
                                q1.push(tmpnode);
                            }
                        }
                    }
                }
            }
            
            word = q2.front().word;
            level2 = q2.front().level;
            
            q2.pop();
            if(!flag_map[word]) {
                flag_map[word] = true;
                level1 = inQueue(word, q1);
                if(level1 > 0) {
                    return level1+level2-1;
                }
                for(int i = 0; i < word.length(); ++i) {
                    string tmpword = word;
                    for(char c = 'a'; c <= 'z'; ++c) {
                        tmpword[i] = c;
                        if(tmpword == start)
                                return level2+1;
                        if(dict.find(tmpword) != dict.end()) {
                            if(!flag_map[tmpword]){
                                Node tmpnode(tmpword, level2+1);
                                //flag_map[tmpword] = true;
                                q2.push(tmpnode);
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
    
    int inQueue(string s, queue<Node> q) {
        while(!q.empty()) {
            Node n = q.front();
            q.pop();
            if(s == n.word)
                return n.level;
        }
        return 0;
    }
};