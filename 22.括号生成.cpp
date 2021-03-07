/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (76.91%)
 * Likes:    1596
 * Dislikes: 0
 * Total Accepted:    235.9K
 * Total Submissions: 306.8K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
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
    vector<string> generateParenthesis(int n) {
        if(n<=0){
            return {};
        }
        string par="";
        stack<char> s;
        generateParenthesisCore(s,n,n,par);
        return res;
    }
private:
    vector<string> res;
    void generateParenthesisCore(stack<char> &s,int left,int right,string &par){
        if(s.empty()&&left==0&&right==0){
            res.push_back(par);
            return ;
        }
        if(s.empty()){
            if(left){
                //栈空时必须填左括号
                s.push('(');
                par.push_back('(');
                generateParenthesisCore(s,left-1,right,par);
                par.pop_back();
                s.pop();
                return;
            }
            else{
                return;
            }
        }
        if(left){
            s.push('(');
            par.push_back('(');
            generateParenthesisCore(s,left-1,right,par);
            par.pop_back();
            s.pop();
        }
        if(right){
            s.pop();
            par.push_back(')');
            generateParenthesisCore(s,left,right-1,par);
            par.pop_back();
            s.push('(');
        }
        return;
    }
};
// @lc code=end

