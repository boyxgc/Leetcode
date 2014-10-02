class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int> > st; // <character, index>
        
        int longest = 0;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(c == '(') {
                st.push(make_pair(c, i));
            } else if(c == ')') {
                if(!st.empty() && st.top().first == '(') {
                    st.pop();
                    int len;
                    if(st.empty()) {
                        len = i+1;
                    } else {
                        len = i-st.top().second;
                    }
                    longest = max(longest, len);
                } else {
                    st.push(make_pair(c, i));
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