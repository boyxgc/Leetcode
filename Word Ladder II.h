#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Node {
    //string str;
    vector<string> prevs;
    //Node(): str(s) {}
};
vector<vector<string> > backtrackPath(unordered_map<string, Node *>nodes, string str, unordered_map<string, vector<vector<string> > > &cache) {
    if(cache.find(str) != cache.end()) {
        return cache[str];
    }
    
    vector<vector<string> > res;
    if(nodes[str] == NULL) {
        vector<string> v;
        v.push_back(str);
        res.push_back(v);
    } else {
        Node *node = nodes[str];
        for(int i = 0; i < node->prevs.size(); ++i) {
            vector<vector<string> > v = backtrackPath(nodes, node->prevs[i], cache);
            for(int j = 0; j < v.size(); ++j) {
                v[j].push_back(str);
                res.push_back(v[j]);
            }
        }
    }
    
    cache[str] = res;
    return res;
}

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
    vector<vector<string> > res;
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
            
            for(int i = 0; i < word.size(); ++i) {
                string tmp = word;
                for(int c = 'a'; c <= 'z'; ++c) {
                    tmp[i] = c;
                    if(dict.find(tmp) == dict.end()) continue; // if not in dict
                    if(nodes_old.find(tmp) != nodes_old.end()) continue; // if already expanded in prev levels

                    Node *wordNode;
                    if(nodes.find(tmp) == nodes.end()) {
                        wordNode = new Node();//Node(tmp);
                        nodes[tmp] = wordNode;
                    } else {
                        wordNode = nodes[tmp];
                    }
                    
                    wordNode->prevs.push_back(word);
                    
                    if(tmp == end) {
                        found = true;
                    } else {
                        q2.push(tmp);
                    }
                }
            }
        }
        if(found) {
            
            unordered_map<string, vector<vector<string> > > cache;
            return backtrackPath(nodes, end, cache);
        }
        q = q2;
    }
    
    return res;
}

int main()
{
    unordered_set<string> dict;

    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");

    string start = "hit";
    string end= "cog";

    vector<vector<string> > v = findLadders(start, end, dict);

    for(int i = 0; i  < v.size(); ++i) {
        for(int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}