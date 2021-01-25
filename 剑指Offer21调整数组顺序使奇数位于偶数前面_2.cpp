class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size()==0){
            return nums;
        }
        int begin=0,end=nums.size()-1;
        while(begin<end){
            while(begin<end&&(nums[begin]&0x1)){
                begin++;
            }
            while(end>begin&&((nums[end]&0x1)==0)){
                end--;
            }
            if(begin<end){
                int tem=nums[begin];
                nums[begin]=nums[end];
                nums[end]=tem;
                begin++;
                end--;
            }
        }
        return nums;
    }
};