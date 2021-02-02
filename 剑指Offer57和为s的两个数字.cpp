class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {};
        }
        int begin=0,end=nums.size()-1;
        while(begin<end){
            if(nums[begin]+nums[end]==target){
                return {nums[begin],nums[end]};
            }
            if(nums[begin]+nums[end]>target){
                end--;
            }
            else
            {
                begin++;
            }
            
        }
        return{};
    }
};