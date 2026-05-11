class MinStack {
public:
    vector<int> l1, l2;

    MinStack() {
        
    }
    
    void push(int val) {
        l1.push_back(val);

        // store minimum till now
        if(l2.empty())
            l2.push_back(val);
        else
            l2.push_back(min(val, l2.back()));
    }
    
    void pop() {
        l1.pop_back();
        l2.pop_back();
    }
    
    int top() {
        return l1.back();
    }
    
    int getMin() {
        return l2.back();
    }
};