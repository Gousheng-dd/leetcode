/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (59.44%)
 * Likes:    793
 * Dislikes: 0
 * Total Accepted:    116.8K
 * Total Submissions: 196.1K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。
 * 
 * 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11
 * 不是。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 12
 * 输出：3 
 * 解释：12 = 4 + 4 + 4
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 13
 * 输出：2
 * 解释：13 = 4 + 9
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //递归，TLE
    int numSquares(int n) {
        if(n<=0){
            return 0;
        }
        int sqr[101];
        for(int i=0;i<=100;i++){
            sqr[i]=i*i;
        }
        res=0x3f3f3f3f;
        int idx=(int)sqrt(n);
        numSquares(sqr,n,idx,0);
        return res;
    }
private:
    int res;
    void numSquares(int *sqr,int n,int idx,int totnum){
        totnum+=n/sqr[idx];
        if(n%sqr[idx]==0){
            res=min(res,totnum);
            return;
        }
        numSquares(sqr,n%sqr[idx],idx-1,totnum);
        totnum-=n/sqr[idx];
        numSquares(sqr,n,idx-1,totnum);
        return ;
    }
};
// @lc code=end

