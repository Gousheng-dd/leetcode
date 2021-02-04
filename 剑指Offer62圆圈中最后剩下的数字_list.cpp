class Solution {
public:
    int lastRemaining(int n, int m) {
        if(n<1||m<1){
            return -1;
        }
        list<int> cyclen;
        for(int i=0;i<n;i++){
            cyclen.push_back(i);
        }
        list<int>::iterator it=cyclen.begin(),next;
        while(cyclen.size()>1){
            for(int i=1;i<m;i++){
                it++;
                if(it==cyclen.end()){
                    it=cyclen.begin();
                }
            }
            next=++it;
            if(next==cyclen.end()){
                next=cyclen.begin();
            }
            it--;
            cyclen.erase(it);
            it=next;
        }
        return cyclen.front();
    }
};