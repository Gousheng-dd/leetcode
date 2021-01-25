class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()==0&&popped.size()==0){
            return true;
        }
        if(pushed.size()==0||popped.size()==0){
            return false;
        }
        stack<int> s;
        while(!s.empty()){
            s.pop();
        }
        int pushidx=0,popidx=0;
        while(popidx<popped.size()){
            if(s.empty()){
                if(pushidx==pushed.size()){
                    break;
                }
                else{
                    s.push(pushed[pushidx++]);
                }
            }
            while(s.top()!=popped[popidx]&&pushidx<pushed.size()){
                s.push(pushed[pushidx++]);
            }
            if(s.top()!=popped[popidx]){
                break;
            }
            while((!s.empty())&&s.top()==popped[popidx]){
                s.pop();
                popidx++;
            }
        }
        if(popidx==popped.size()){
            return true;
        }
        return false;
    }
};