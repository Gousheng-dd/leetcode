/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode-cn.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (41.27%)
 * Likes:    599
 * Dislikes: 0
 * Total Accepted:    105.1K
 * Total Submissions: 249.7K
 * Testcase Example:  '[2,3,2]'
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈
 * ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        /*dp
        dp[0][i]表示第0家没偷的情况下到第i家最大价值
        状态转移方程：
            dp[0][0]=0,dp[0][1]=nums[1]
            dp[0][i]=max(dp[0][i-1],dp[0][i-2]+prices[i])
        dp[1][i]表示第0家偷了的情况下到第i家最大价值
        状态转移方程：
            dp[1][0]=nums[0],dp[1][1]=nums[1]
            2<=i<=n-2时 dp[1][i]=max(dp[1][i-1],dp[1][i-2]+prices[i])
            i==n-1时，dp[1][i]=dp[1][i-1]
        可以进行空间优化,使用几个变量代替dp数组
        */
        int n=nums.size();
        if(!n){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        int dp0i,dp0i_1=nums[1],dp0i_2=0,dp1i,dp1i_1=max(nums[0],nums[1]),dp1i_2=nums[0];
        for(int i=2;i<n-1;i++){
            dp0i=max(dp0i_1,dp0i_2+nums[i]);
            dp1i=max(dp1i_1,dp1i_2+nums[i]);
            dp0i_2=dp0i_1;
            dp0i_1=dp0i;
            dp1i_2=dp1i_1;
            dp1i_1=dp1i;
        }
        dp0i=max(dp0i_1,dp0i_2+nums[n-1]);
        //此时dp[0][n-1]=dp0i,dp[1][n-1]=dp1i_1
        return max(dp0i,dp1i_1);
    }
};
// @lc code=end

