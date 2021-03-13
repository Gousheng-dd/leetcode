/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (44.53%)
 * Likes:    699
 * Dislikes: 0
 * Total Accepted:    93.8K
 * Total Submissions: 210.1K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [["0","1"],["1","0"]]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [["0"]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * matrix[i][j] 为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(!m){
            return 0;
        }
        int n=matrix[0].size();
        if(!n){
            return 0;
        }
        int **dp=new int*[m];
        for(int i=0;i<m;i++){
            dp[i]=new int[n];
            memset(dp[i],0,sizeof(int)*n);
        }
        int res=0;
        for(int i=0;i<m;i++){
            dp[i][0]=matrix[i][0]-'0';
            res=max(res,dp[i][0]);
        }
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i]-'0';
            res=max(res,dp[0][i]);
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    res=max(res,dp[i][j]);
                }
            }
        }
        return res*res;
    }
};
// @lc code=end

