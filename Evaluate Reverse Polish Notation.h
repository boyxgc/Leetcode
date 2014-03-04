class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); ++i) {
            string s = tokens[i];
            if(s == "+") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1+num2);
            } else if (s == "-") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2-num1);
            }  else if (s == "*") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1*num2);
            } else if (s == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2/num1);
            } else {
                int num;
                istringstream(s) >> num;
                st.push(num);
            }
        }
        
        return st.top();
    }
};