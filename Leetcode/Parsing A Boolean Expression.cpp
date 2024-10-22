// https://leetcode.com/problems/parsing-a-boolean-expression/

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char c : expression) {
            if(c == ',' or c == '(') continue;
            else if(c == '&' or c == '|' or c == '!' or c == 't' or c == 'f'){
                st.push(c);
            }else if(c == ')') {
                bool hasT = false, hasF = false;

                while(st.top() != '&' and st.top() != '|' and st.top() != '!') {
                    char top = st.top();
                    st.pop();

                    hasT = (top == 't');
                    hasF = (top == 'f');
                }

                char type = st.top();
                st.pop();

                if(type == '!') {
                    st.push(hasT ? 'f' : 't');
                }else if (type == '&') {
                    st.push(hasF ? 'f' : 't');
                }else {
                    st.push(hasT ? 't' : 'f');
                }
            }
        }

        return st.top() == 't';
    }
};