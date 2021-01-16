/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (59.05%)
 * Likes:    431
 * Dislikes: 0
 * Total Accepted:    71.6K
 * Total Submissions: 121.1K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 * 
 * 示例 1:
 * 
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 
 * 示例 2:
 * 
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 * 
 * 说明: 你可以假设 n 不小于 2 且不大于 58。
 * 
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if(n<=2){
            return 1;
        }
        if(n==3){
            return 2;
        }
        int product[n+1];
        memset(product,0,sizeof product);
        product[0]=0;
        product[1]=1;
        product[2]=2;
        product[3]=3;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                product[i]=max(product[i],product[j]*product[i-j]);
            }
        }
        return product[n];
    }
};
// @lc code=end

