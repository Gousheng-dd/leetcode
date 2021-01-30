class Solution {
public:
    int translateNum(int num) {
        if(num<0){
            return 0;
        }
        string nums=to_string(num);
        int n=nums.size();
        int* dp=new int[n+1];
        dp[n]=1,dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            dp[i]=dp[i+1];
            if(isInRange(nums[i],nums[i+1])){
                dp[i]+=dp[i+2];
            }
        }
        int res=dp[0];
        delete[] dp;
        return res;
    }
private:
    bool isInRange(char a,char b){
        int res=(a-'0')*10+(b-'0');
        if(res>=10&&res<=25){
            return true;
        }
        return false;
    }
};