class MyStack {
    private:
    queue<int> que;

public:
    MyStack() {
    }
    
    void push(int x) {
        que.push(x);
        int n = que.size();
        for(int i = 1; i<n;i++){
            que.push(que.front());
            que.pop();
        }       
    }
    
    int pop() {
        int result = que.front();
        que.pop();
        return result;
        
    }
    
    int top() {
        return que.front();       
        
    }
    
    bool empty() {
        return que.empty();
        
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