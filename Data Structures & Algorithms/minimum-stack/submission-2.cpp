class MinStack {
public:
    vector<int> my_stack;
    vector<int> sorted_stack;
    MinStack() {
    }
    
    void push(int val) {
        if (my_stack.size() == 0)
        {
            sorted_stack.push_back(val);
        }
        else
        {
            sorted_stack.push_back(min(val, sorted_stack.back()));
        }
        my_stack.push_back(val);
    }
    
    void pop() {
        int temp = my_stack.back();
        if (sorted_stack.back() == temp)
        {
            sorted_stack.pop_back();
        }
        my_stack.pop_back();
    }
    
    int top() {
        return my_stack.back();
    }
    
    int getMin() {
        return sorted_stack.back();
    }
};
