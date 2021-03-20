/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (46.70%)
 * Likes:    437
 * Dislikes: 0
 * Total Accepted:    42.6K
 * Total Submissions: 90.8K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
 * 
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * 输出：4 
 * 解释：最长递增路径为 [1, 2, 6, 9]。
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * 输出：4 
 * 解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [[1]]
 * 输出：1
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
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(!m){
            return 0;
        }
        int n=matrix[0].size();
        if(!n){
            return 0;
        }
        vector<vector<int> > maxmat=vector<vector<int> >(m,vector<int>(n));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=max(res,dfs(matrix,m,n,maxmat,i,j));
            }
        }
        return res;
    }
private:
    int direct[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    int dfs(vector<vector<int>>& matrix,int m,int n,vector<vector<int>> &maxmat,int x,int y){
        if(maxmat[x][y]){
            return maxmat[x][y];
        }
        int maxres=1;
        for(int i=0;i<4;i++){
            int newx=x+direct[i][0],newy=y+direct[i][1];
            if(newx>=0&&newx<m&&newy>=0&&newy<n&&matrix[newx][newy]>matrix[x][y]){
                maxres=max(maxres,dfs(matrix,m,n,maxmat,newx,newy)+1);
            }
        }
        maxmat[x][y]=maxres;
        return maxres;
    }
};
// @lc code=end

