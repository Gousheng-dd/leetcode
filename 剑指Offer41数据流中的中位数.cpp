class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int> > bigheap;
    priority_queue<int, vector<int>, greater<int> > smallheap;

    MedianFinder() {

    }
    
    void addNum(int num) {
        if((bigheap.size()+smallheap.size())&0x1){//奇数时放入小堆
            if(bigheap.size()&&num<bigheap.top()){
                bigheap.push(num);
                num=bigheap.top();
                bigheap.pop();
            }
            smallheap.push(num);
        }
        else{//偶数时放入大堆
            if(smallheap.size()&&num>smallheap.top()){
                smallheap.push(num);
                num=smallheap.top();
                smallheap.pop();
            }
            bigheap.push(num);
        }
        return;
    }
    
    double findMedian() {
        if(bigheap.size()+smallheap.size()==0){
            return 0.0;
        }
        if((bigheap.size()+smallheap.size())&0x1){
            return bigheap.top();
        }
        else{
            return (smallheap.top()+bigheap.top())/2.0;
        }
        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */