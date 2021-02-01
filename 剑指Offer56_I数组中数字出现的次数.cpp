class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        int xorres=0;
        for(int i=0;i<nums.size();i++){
            xorres=xorres^nums[i];
        }
        int bitpos=0;
        for(;bitpos<32;bitpos++){
            if(xorres&1){
                break;
            }
            xorres=xorres>>1;
        }
        int num1=0,num2=0;
        for(int i=0;i<nums.size();i++){
            if(isBit1(nums[i],bitpos)){
                num1=num1^nums[i];
            }
            else{
                num2=num2^nums[i];
            }
        }
        vector<int> res;
        res.push_back(num1);
        res.push_back(num2);
        return res;
    }
private:
    bool isBit1(int num,int bitpos){
        for(int i=0;i<bitpos;i++){
            num=num>>1;
        }
        return ((num&1)==1)?true:false;
    }
};