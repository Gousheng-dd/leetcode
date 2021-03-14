/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 *
 * https://leetcode-cn.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (67.72%)
 * Likes:    657
 * Dislikes: 0
 * Total Accepted:    40.6K
 * Total Submissions: 59.9K
 * Testcase Example:  '[3,1,5,8]'
 *
 * 有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
 * 
 * 现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i
 * - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
 * 
 * 求所能获得硬币的最大数量。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,1,5,8]
 * 输出：167
 * 解释：
 * nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
 * coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,5]
 * 输出：10
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        if(!n){
            return 0;
        }
        int **dp=new int*[n+2];
        for(int i=0;i<n+2;i++){
            dp[i]=new int[n+2];
            memset(dp[i],0,sizeof(int)*(n+2));
        }
        for(int len=3;len<=n+2;len++){
            for(int i=0;i+len-1<n+2;i++){
                int j=i+len-1;
                for(int k=i+1;k<j;k++){
                    int left,right;
                    left=i==0?1:nums[i-1];
                    right=j==n+1?1:nums[j-1];
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+left*nums[k-1]*right);
                }
            }
        }
        int res=dp[0][n+1];
        for(int i=0;i<n+2;i++){
            delete []dp[i];
        }
        delete []dp;
        return res;
    }
};
// @lc code=end

