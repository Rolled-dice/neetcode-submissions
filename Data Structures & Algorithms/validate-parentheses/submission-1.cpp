
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s) {

            // opening brackets
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {

                // closing bracket but stack empty
                if(st.empty()) return false;

                // matching
                if((ch == ')' && st.top() == '(') ||
                   (ch == '}' && st.top() == '{') ||
                   (ch == ']' && st.top() == '[')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

// will used stack here...