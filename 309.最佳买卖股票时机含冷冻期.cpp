/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (57.52%)
 * Likes:    706
 * Dislikes: 0
 * Total Accepted:    78K
 * Total Submissions: 135.2K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
 * 
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 
 * 
 * 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 
 * 
 * 示例:
 * 
 * 输入: [1,2,3,0,2]
 * 输出: 3 
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    dp
    一天的结束时可能有三个状态：1.持有一只股票；（来自：昨天也持有股票今天没卖；或者今天买了一只股票）
                        2.未持有股票，且当前卖过股票（来自：今天卖了股票）；
                        3.未持有股票且未进行任何操作（来自：昨天本来就没有股票；或者昨天卖了股票）；
    分别用dp[i][0],dp[i][1],dp[i][2]表示
    */
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(!n){
            return 0;
        }
        int **dp=new int*[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[3];
        }
        dp[0][0]=-prices[0],dp[0][1]=0,dp[0][2]=0;
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][2]-prices[i]);
            dp[i][1]=dp[i-1][0]+prices[i];
            dp[i][2]=max(dp[i-1][2],dp[i-1][1]);
        }
        int res=max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
        for(int i=0;i<n;i++){
            delete []dp[i];
        }
        delete []dp;
        return res;
    }
};
// @lc code=end

