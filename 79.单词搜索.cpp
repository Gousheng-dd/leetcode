/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (43.93%)
 * Likes:    739
 * Dislikes: 0
 * Total Accepted:    131.9K
 * Total Submissions: 300K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size(),column=board[0].size();
        if(!row||!column||!word.size()){
            return false;
        }
        bool *visited=new bool[row*column];
        memset(visited,0,row*column);
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(hasPath(board,row,column,word,i,j,0,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    bool hasPath(vector<vector<char>>& board,int row,int column,string& word,int x,int y,int plen,bool* visited){
        if(x<0||x>=row||y<0||y>=column){
            return false;
        }
        if(visited[x*column+y]){
            return false;
        }
        if(board[x][y]!=word[plen]){
            return false;
        }
        if(plen==word.size()-1){
            return true;
        }
        visited[x*column+y]=true;
        bool hp=hasPath(board,row,column,word,x-1,y,plen+1,visited)
                ||hasPath(board,row,column,word,x,y-1,plen+1,visited)
                ||hasPath(board,row,column,word,x+1,y,plen+1,visited)
                ||hasPath(board,row,column,word,x,y+1,plen+1,visited);
        if(hp){
            return true;
        }
        visited[x*column+y]=false;
        return false;
    }
};
// @lc code=end

