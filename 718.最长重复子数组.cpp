/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 *
 * https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (55.46%)
 * Likes:    417
 * Dislikes: 0
 * Total Accepted:    57.5K
 * Total Submissions: 103.6K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * 输出：3
 * 解释：
 * 长度最长的公共子数组是 [3, 2, 1] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        //dp,记dp[i][j]为A串第i位和B串第j位为结尾最长公共子数组长度
        //状态转移方程dp[i][j]=(A[i]==B[j])?dp[i-1][j-1]+1:0;
        //时间复杂度O(n*m),空间复杂度O(n*m)
        int n=A.size(),m=B.size();
        if(!n||!m){
            return 0;
        }
        int res=0;
        int **dp=new int*[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[m];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0){
                    dp[i][j]=(A[i]==B[j])?1:0;
                }
                else{
                    dp[i][j]=(A[i]==B[j])?dp[i-1][j-1]+1:0;
                }
                res=max(res,dp[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            delete []dp[i];
        }
        delete []dp;
        return res;
    }
};
// @lc code=end

