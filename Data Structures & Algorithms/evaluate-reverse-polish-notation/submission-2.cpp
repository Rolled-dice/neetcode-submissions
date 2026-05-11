class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& token : tokens) {
            if (!st.empty() &&( token == "+" || token == "-" || token == "*" || token == "/")) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b); // integer division
            } else {
                st.push(stoi(token)); // convert string to int
            }
        }
        return st.top();
    }
};
