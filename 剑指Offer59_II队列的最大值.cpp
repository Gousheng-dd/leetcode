class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(maxq.empty()){
            return -1;
        }
        return maxq.front();
    }
    
    void push_back(int value) {
        while(!maxq.empty()&&value>maxq.back()){
            maxq.pop_back();
        }
        maxq.push_back(value);
        data.push(value);
        return;
    }
    
    int pop_front() {
        if(maxq.empty()){
            return -1;
        }
        int val=data.front();
        data.pop();
        if(val==maxq.front()){
            maxq.pop_front();
        }
        return val;
    }
private:
    queue<int> data;
    deque<int> maxq;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */