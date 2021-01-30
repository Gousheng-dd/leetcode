class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.size()==0){
            return -1;
        }
        int m=grid.size(),n=grid[0].size();
        int* dp=new int[n+10];
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            dp[i]=dp[i+1]+grid[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            dp[n-1]+=grid[i][n-1];
            for(int j=n-2;j>=0;j--){
                dp[j]=max(dp[j+1],dp[j])+grid[i][j];
            }
        }
        int res=dp[0];
        delete[] dp;
        return res;
    }
};