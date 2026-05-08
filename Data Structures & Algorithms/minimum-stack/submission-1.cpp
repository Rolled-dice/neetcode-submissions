class MinStack {
public:
    vector<int> st; // main stack
    vector<int> m;  // min stack

    MinStack() {}

    void push(int val) {
        st.push_back(val);
        if (m.empty() || val <= m.back()) {
            m.push_back(val);
        }
    }

    void pop() {
        if (st.back() == m.back()) {
            m.pop_back();
        }
        st.pop_back();
    }

    int top() {
        return st.back();
    }

    int getMin() {
        return m.back();
    }
};
