class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int *dp=new int[nums.size()+10];
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
        }
        int maxnum=dp[0];
        for(int i=1;i<nums.size();i++){
            if(dp[i]>maxnum){
                maxnum=dp[i];
            }
        }
        return maxnum;
    }
};