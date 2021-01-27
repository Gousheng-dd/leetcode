class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }
        int cnt=1,num=nums[0];
        for(int i=1;i<nums.size();i++){
            if(!cnt){
                num=nums[i];
                cnt=1;
            }
            else{
                if(nums[i]==num){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
        }
        if(!checkMoreThanHalf(nums,num)){
            return -1;
        }
        return num;
    }
private:
    bool checkMoreThanHalf(vector<int>& nums,int val){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                cnt++;
            }
        }
        if(cnt>nums.size()/2){
            return true;
        }
        return false;
    }
};