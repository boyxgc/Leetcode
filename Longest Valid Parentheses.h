class Solution {
public:
    struct Cell {
        char c;
        int idx;
        Cell(char ch, int i){c = ch; idx = i;}
    };

    int longestValidParentheses(string s) {
        stack<Cell> st;
        
        int longest = 0;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(c == '(') {
                Cell cell(c, i);
                st.push(cell);
            } else if(c == ')') {
                if(!st.empty() && st.top().c == '(') {
                    st.pop();
                    int len;
                    if(st.empty()) {
                        len = i+1;
                    } else {
                        len = i-st.top().idx;
                    }
                    longest = max(longest, len);
                } else {
                    Cell cell(c, i);
                    st.push(cell);
                }
            }
        }
        
        return longest;
    }
};

class Solution {
public:
    /*
    struct Node {
        char c;
        int pos;  
        Node (char ch, int p):c(ch), pos(p){}
        Node(){}
    };
    int longestValidParentheses(string s) {
        vector<int> v(s.size(), 0);
        stack<Node *> st;
        int maxsofar = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '('){
                st.push(new Node('(', i));
            } else {
                if(!st.empty()) {
                    Node *node = st.top();
                    st.pop();
                    int count = 2;
                    if(node->c == '(') {
                        if(node->pos-1 >= 0){
                            count += v[node->pos-1];
                        }
                        if(i-1 >= 0) {
                            count += v[i-1];
                        }
                        v[i] = count;
                        maxsofar = max(maxsofar, count);
                    }
                } 
            }
        }
        return maxsofar;
    } */

    int longestValidParentheses(string s) {
        if(s == "") return 0;
        stack<pair<char, int>> st;
        int maxsofar = 0;
        int t = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(')
                st.push(make_pair('(', i));
            else {// s[i] == ')'
                if(!st.empty()){
                    pair<char, int> p = st.top();
                    st.pop();
                    if(!st.empty())// look the previous unmatched '(' in the stack
                        maxsofar = max(maxsofar, i-st.top().second);
                    else
                        maxsofar = max(maxsofar, i-t+1);
                } else {
                    t = i+1;
                }
            }
        }
        return maxsofar;
    }
};