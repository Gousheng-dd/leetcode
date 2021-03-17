/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode-cn.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (44.87%)
 * Likes:    588
 * Dislikes: 0
 * Total Accepted:    69.2K
 * Total Submissions: 154K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或
 * -中选择一个符号添加在前面。
 * 
 * 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：nums: [1, 1, 1, 1, 1], S: 3
 * 输出：5
 * 解释：
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * 一共有5种方法让最终目标和为3。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 数组非空，且长度不会超过 20 。
 * 初始的数组的和不会超过 1000 。
 * 保证返回的最终结果能被 32 位整数存下。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //背包,总价值范围为-1000<=x<=1000，修改为0~2000
    int findTargetSumWays(vector<int>& nums, int S) {
        int n=nums.size();
        if(!n){
            return 0;
        }
        if(S>1000||S<-1000){
            return 0;
        }
        int **dp=new int*[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[2001];
            memset(dp[i],0,sizeof(int)*2001);
        }
        dp[0][1000-nums[0]]+=1;
        dp[0][1000+nums[0]]+=1;
        for(int i=1;i<n;i++){
            for(int j=-1000;j<=1000;j++){
                if(dp[i-1][j+1000]>0){
                    dp[i][j+1000+nums[i]]+=dp[i-1][j+1000];
                    dp[i][j+1000-nums[i]]+=dp[i-1][j+1000];
                }
            }
        }
        int res=dp[n-1][S+1000];
        for(int i=0;i<n;i++){
            delete []dp[i];
        }
        delete []dp;
        return res;
    }
};
// @lc code=end

