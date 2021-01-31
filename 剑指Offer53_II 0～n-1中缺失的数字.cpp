class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }
        int n=nums.size();
        int begin=0,end=n-1,mid=(begin+end)>>1;
        while(begin<=end){
            if(nums[mid]!=mid){
                if(mid==0||nums[mid-1]==mid-1){
                    return mid;
                }
                end=mid-1;
            }
            else{
                begin=mid+1;
            }
            mid=(begin+end)>>1;
        }
        if(begin==n){
            return n;
        }
        return end-1;
    }
};