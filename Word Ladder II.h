#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/*
time limit excceed
class Solution {
public:
    struct Node {
        string str;
        vector<string> prevs;
        Node(string s): str(s) {}
    };
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> res;
        queue<string> q;
        unordered_map<string, Node *> nodes;
        bool found = false;
        
        nodes[start] = NULL;
        q.push(start);
        dict.insert(end);// !!!!
        
        while(!q.empty()) {
            
            unordered_map<string, Node *> nodes_old = nodes;
            queue<string> q2;
            while(!q.empty()) {
                string word = q.front();
                q.pop();
                
                unordered_set<string> inserted;
                for(int i = 0; i < word.size(); ++i) {
                    string tmp = word;
                    for(int c = 'a'; c <= 'z'; ++c) {
                        tmp[i] = c;
                        if(dict.find(tmp) == dict.end()) continue; // if not in dict
                        if(nodes_old.find(tmp) != nodes_old.end()) continue; // if already expanded in prev levels

                        Node *wordNode;
                        if(nodes.find(tmp) == nodes.end()) {
                            wordNode = new Node(tmp);
                            nodes[tmp] = wordNode;
                        } else {
                            wordNode = nodes[tmp];
                        }
                        
                        wordNode->prevs.push_back(word);
                        
                        if(tmp == end) {
                            found = true;
                        } else {
                            if(inserted.find(tmp) == inserted.end()) {
                                inserted.insert(tmp);
                                q2.push(tmp);
                            }
                        }
                    }
                }
            }
            if(found) {
                vector<string> v;
                v.push_back(end);
                backtrackPath(nodes, end, v, res);
                
                return res;
            }
            q = q2;
        }
        
        return res;
    }
    
    void backtrackPath(unordered_map<string, Node*> &nodes, string str, vector<string> &v, vector<vector<string> > &res) {
        if(nodes[str] == NULL) {
            vector<string> v_cpy(v);
            reverse(v_cpy.begin(), v_cpy.end());
            res.push_back(v_cpy);
            return;
        }
        
        Node *node = nodes[str];
        
        for(int i = 0; i < node->prevs.size(); ++i) {
            string prev = node->prevs[i];
            v.push_back(prev);
            backtrackPath(nodes, prev, v, res);
            v.pop_back();
        }
    }
};
*/
/*
// Memory Limit excceed
struct Node {
    string str;
    vector<Node *> prevs;
    Node(string s): str(s) {}
};
vector<vector<Node *> > backtrackPath(Node *node, unordered_map<Node *, vector<vector<Node *> > > &cache) {
    if(cache.find(node) != cache.end()) {
        return cache[node];
    }
    
    vector<vector<Node *> > res;
    if(node->prevs.size() == 0) {
        vector<Node *> v;
        v.push_back(node);
        res.push_back(v);
    } else {
        for(int i = 0; i < node->prevs.size(); ++i) {
            vector<vector<Node *> > v = backtrackPath(node->prevs[i], cache);
            for(int j = 0; j < v.size(); ++j) {
                v[j].push_back(node);
                res.push_back(v[j]);
            }
        }
    }
    
    cache[node] = res;
    return res;
}

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
    vector<vector<string> > res;
    queue<string> q;
    unordered_map<string, Node *> nodes;
    bool found = false;
    
    nodes[start] = new Node(start);
    q.push(start);
    dict.insert(end);// !!!!
    
    while(!q.empty()) {
        
        unordered_map<string, Node *> nodes_old = nodes;
        queue<string> q2;
        while(!q.empty()) {
            string word = q.front();
            q.pop();
            
            for(int i = 0; i < word.size(); ++i) {
                string tmp = word;
                for(int c = 'a'; c <= 'z'; ++c) {
                    tmp[i] = c;
                    if(dict.find(tmp) == dict.end()) continue; // if not in dict
                    if(nodes_old.find(tmp) != nodes_old.end()) continue; // if already expanded in prev levels

                    Node *wordNode;
                    if(nodes.find(tmp) == nodes.end()) {
                        wordNode = new Node(tmp);
                        nodes[tmp] = wordNode;
                    } else {
                        wordNode = nodes[tmp];
                    }
                    
                    wordNode->prevs.push_back(nodes[word]);
                    
                    if(tmp == end) {
                        found = true;
                    } else {
                        q2.push(tmp);
                    }
                }
            }
        }
        if(found) {
            
            unordered_map<Node *, vector<vector<Node *> > > cache;
            vector<vector<Node *> >  nv = backtrackPath(nodes[end], cache);

            for(int i = 0; i < nv.size(); ++i) {
                vector<string> v;
                for(int j = 0; j < nv[i].size(); ++j) {
                    v.push_back(nv[i][j]->str);
                }
                res.push_back(v);
            }
            return res;
        }
        q = q2;
    }
    
    return res;
}
*/
class Solution {
public:
    struct Node {
        string str;
        vector<string> prevs;
        Node(string s): str(s) {}
    };
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> res;
        unordered_set<string> q; 
        unordered_set<string> q2;// use hashset to avoid duplicate access
        unordered_map<string, Node *> nodes;
        bool found = false;
        
        nodes[start] = NULL;
        q.insert(start);
        dict.insert(end);// !!!!
        
        while(!q.empty()) {
            
            for(auto it = q.begin(); it != q.end(); ++it) {
                dict.erase(*it); // erase already used words
            }
            q2.clear();
            for(auto it = q.begin(); it != q.end(); ++it) {
                string word = *it;
                
                for(int i = 0; i < word.size(); ++i) {
                    string tmp = word;
                    for(int c = 'a'; c <= 'z'; ++c) {
                        tmp[i] = c;
                        if(dict.find(tmp) == dict.end()) continue; // if not in dict

                        Node *wordNode;
                        if(nodes.find(tmp) == nodes.end()) {
                            wordNode = new Node(tmp);
                            nodes[tmp] = wordNode;
                        } else {
                            wordNode = nodes[tmp];
                        }
                        
                        wordNode->prevs.push_back(word);
                        
                        if(tmp == end) {
                            found = true;
                        } else {
                            q2.insert(tmp);
                        }
                    }
                }
            }
            if(found) {
                vector<string> v;
                v.push_back(end);
                backtrackPath(nodes, end, v, res);
                
                return res;
            }
            q = q2;
        }
        
        return res;
    }
    
    void backtrackPath(unordered_map<string, Node*> &nodes, string str, vector<string> &v, vector<vector<string> > &res) {
        if(nodes[str] == NULL) {
            vector<string> v_cpy(v);
            reverse(v_cpy.begin(), v_cpy.end());
            res.push_back(v_cpy);
            return;
        }
        
        Node *node = nodes[str];
        
        for(int i = 0; i < node->prevs.size(); ++i) {
            string prev = node->prevs[i];
            v.push_back(prev);
            backtrackPath(nodes, prev, v, res);
            v.pop_back();
        }
    }
};