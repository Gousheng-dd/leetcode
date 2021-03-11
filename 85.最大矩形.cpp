/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (51.70%)
 * Likes:    836
 * Dislikes: 0
 * Total Accepted:    70.3K
 * Total Submissions: 135.9K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：6
 * 解释：最大矩形如上图所示。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = []
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [["0"]]
 * 输出：0
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：matrix = [["1"]]
 * 输出：1
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：matrix = [["0","0"]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * rows == matrix.length
 * cols == matrix[0].length
 * 0 
 * matrix[i][j] 为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(!n){
            return 0;
        }
        int m=matrix[0].size();
        int *height=new int[m];
        int res=0;
        memset(height,0,sizeof(int)*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else{
                    height[j]=0;
                }
            }
            res=max(res,getMaxRectangle(height,m));
        }
        return res;
    }
private:
    //单调栈,从小到大
    int getMaxRectangle(int* height,int m){
        int res=0;
        stack<int> s;
        s.push(0);
        for(int i=1;i<m;i++){
            if(s.empty()){
                s.push(i);
            }
            while(height[i]<=height[s.top()]){
                int toph=height[s.top()];
                s.pop();
                if(s.empty()){
                    int size=toph*i;
                    res=max(res,size);
                    break;
                }
                int size=toph*(i-s.top()-1);
                res=max(res,size);
            }
            s.push(i);
        }
        while(s.size()>1){
            int toph=height[s.top()];
            s.pop();
            int size=toph*(m-s.top()-1);
            res=max(res,size);
        }
        if(s.size()==1){
            res=max(res,height[s.top()]*m);
        }
        return res;
    }
};
// @lc code=end

