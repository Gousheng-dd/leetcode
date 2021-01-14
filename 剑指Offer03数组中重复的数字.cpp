class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //原地hash
        if(nums.empty()){
            return -1;
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]!=i){
                int idx=nums[i];
                if(nums[idx]==idx){
                    return idx;
                }
                else{
                    nums[idx]=nums[i];
                    nums[i]=idx;
                }
            }
        }
        return -1;
    }
};