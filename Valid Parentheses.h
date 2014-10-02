class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                char match = '@';
                switch(c) {
                    case ')': match = '('; break;
                    case '}': match = '{'; break;
                    case ']': match = '['; break;
                    default: return false;
                }
                if(st.empty() || st.top() != match) return false;
                st.pop();
            }
        }
        
        return st.empty();
    }
};