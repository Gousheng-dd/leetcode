class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> datastack;
    stack<int> minstack;
    MinStack() {
        
    }
    
    void push(int x) {
        datastack.push(x);
        if(minstack.empty()){
            minstack.push(x);
            return;
        }
        int nowmin=minstack.top();
        nowmin=(nowmin<x)?nowmin:x;
        minstack.push(nowmin);
        return ;
    }
    
    void pop() {
        if((!datastack.empty())&&(!minstack.empty()))
        {
            datastack.pop();
            minstack.pop();
        }
        return;
    }
    
    int top() {
        return datastack.top();
    }
    
    int min() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */