class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
        return;
    }
    
    int deleteHead() {
        int t;
        if(!s2.empty()){
            t=s2.top();
            s2.pop();
            return t;
        }
        if(s1.empty()){
            return -1;
        }
        while (s1.size()>1)
        {
            t=s1.top();
            s1.pop();
            s2.push(t);
        }
        t=s1.top();
        s1.pop();
        return t;
        
    }
private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */