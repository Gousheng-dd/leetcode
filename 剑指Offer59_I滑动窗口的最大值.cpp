class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()==0||k<=0||nums.size()<k){
            return {};
        }
        deque<int> winmax;
        vector<int> res;
        for(int i=0;i<k;i++){
            while(!winmax.empty()&&nums[i]>=nums[winmax.back()]){
                winmax.pop_back();
            }
            winmax.push_back(i);
        }
        for(int i=k;i<nums.size();i++){
            res.push_back(nums[winmax.front()]);
            while(!winmax.empty()&&nums[i]>=nums[winmax.back()]){
                winmax.pop_back();
            }
            if(!winmax.empty()&&(i-winmax.front())>=k){
                winmax.pop_front();
            }
            winmax.push_back(i);
        }
        res.push_back(nums[winmax.front()]);
        return res;
    }
};