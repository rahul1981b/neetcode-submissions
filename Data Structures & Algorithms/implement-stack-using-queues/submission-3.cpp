class MyStack {
public:
    std::queue<int> my_stack;
    std::queue<int> temp_queue;
    MyStack() {
    }
    
    void push(int x) {
        if (empty())
        {
            my_stack.push(x);
            return;
        }

        int len = my_stack.size();
        for (int i = 0; i < len; i++)
        {
            int data = my_stack.front();
            my_stack.pop();
            temp_queue.push(data);
        }

        my_stack.push(x);
        len = temp_queue.size();
        for (int i = 0; i < len; i++)
        {
            int data = temp_queue.front();
            cout<<data<<endl;
            temp_queue.pop();
            my_stack.push(data);
        }
    }
    
    int pop() {
        if (!empty())
        {
            int data = my_stack.front();
            my_stack.pop();
            return data;
        }
        return -1;
    }
    
    int top() {
        return my_stack.front();
    }
    
    bool empty() {
        return (my_stack.size() == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */