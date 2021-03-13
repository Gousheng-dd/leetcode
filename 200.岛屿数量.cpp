/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (52.69%)
 * Likes:    1026
 * Dislikes: 0
 * Total Accepted:    215.9K
 * Total Submissions: 408.8K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 
 * grid[i][j] 的值为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        if(!m){
            return 0;
        }
        n=grid[0].size();
        if(!n){
            return 0;
        }
        int cnt=0;
        v=new bool* [m];
        for(int i=0;i<m;i++){
            v[i]=new bool[n];
            memset(v[i],0,sizeof(bool)*n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&&!v[i][j]){
                    cnt++;
                    spreadIsland(grid,i,j);
                }
            }
        }
        return cnt;
    }
private:
    bool** v;
    int m,n;
    void spreadIsland(vector<vector<char>>& grid,int x,int y){
        if(x<0||x>=m||y<0||y>=n||v[x][y]||grid[x][y]=='0'){
            return;
        }
        v[x][y]=true;
        spreadIsland(grid,x-1,y);
        spreadIsland(grid,x,y-1);
        spreadIsland(grid,x+1,y);
        spreadIsland(grid,x,y+1);
        return;
    }
};
// @lc code=end

