class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }
        int bitsum[32]={0};
        int bitex=1;
        for(int i=0;i<32;i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j]&bitex){
                    bitsum[i]++;
                }
            }
            if(i!=31){
                bitex=bitex<<1;
            }
        }
        int res=0;
        bitex=1;
        for(int i=0;i<32;i++){
            if(bitsum[i]%3){
                res=res|bitex;
            }
            if(i!=31){
                bitex=bitex<<1;
            }
        }
        return res;
    }
};