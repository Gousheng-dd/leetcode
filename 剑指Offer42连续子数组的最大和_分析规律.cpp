class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int maxsum=nums[0],nowsum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nowsum<0){
                nowsum=nums[i];
            }
            else{
                nowsum+=nums[i];
            }
            if(nowsum>maxsum){
                maxsum=nowsum;
            }
        }
        return maxsum;
    }
};