class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if(target<=0){
            return {};
        }
        int start=1,end=2,sum=3;
        vector<vector<int> > result;
        while(end<target){
            if(sum==target){
                vector<int> res;
                for(int i=start;i<=end;i++){
                    res.push_back(i);
                }
                result.push_back(res);
                sum-=start;
                start++;
                end++;
                sum+=end;
            }
            else if(sum>target){
                sum-=start;
                start++;
            }
            else{
                end++;
                sum+=end;
            }
        }
        return result;
    }
};