/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 *
 * https://leetcode-cn.com/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (50.14%)
 * Likes:    380
 * Dislikes: 0
 * Total Accepted:    21.3K
 * Total Submissions: 42.4K
 * Testcase Example:  '"()())()"'
 *
 * 删除最小数量的无效括号，使得输入的字符串有效，返回所有可能的结果。
 * 
 * 说明: 输入可能包含了除 ( 和 ) 以外的字符。
 * 
 * 示例 1:
 * 
 * 输入: "()())()"
 * 输出: ["()()()", "(())()"]
 * 
 * 
 * 示例 2:
 * 
 * 输入: "(a)())()"
 * 输出: ["(a)()()", "(a())()"]
 * 
 * 
 * 示例 3:
 * 
 * 输入: ")("
 * 输出: [""]
 * 
 */

// @lc code=start
class Solution {
public:
    //DFS搜索+剪枝（左括号数小于右括号不符合要求，则可以计算需要删除的左右括号数）
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        if(!n){
            return {""};
        }
        int leftnum=0,rightnum=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                leftnum++;
            }
            else if(s[i]==')'){
                if(leftnum>0){
                    leftnum--;
                }
                else{
                    rightnum++;
                }
            }
        }
        getPath(s,0,0,0,leftnum,rightnum);
        vector<string> res;
        for(auto it=usres.begin();it!=usres.end();it++){
            res.push_back(*it);
        }
        return res;
    }
private:
    unordered_set<string > usres;
    string path;
    void getPath(string &s,int idx,int leftnum,int rightnum,int left2remove,int right2tremove){
        if(idx==s.size()){
            if(leftnum==rightnum&&right2tremove==0&&left2remove==0){
                usres.insert(path);
            }
            return;
        }
        //删除当前元素
        if(s[idx]=='('){
            getPath(s,idx+1,leftnum,rightnum,left2remove-1,right2tremove);
        }
        else if(s[idx]==')'){
            getPath(s,idx+1,leftnum,rightnum,left2remove,right2tremove-1);
        }

        //保留当前元素
        path.push_back(s[idx]);
        if(s[idx]=='('){
            getPath(s,idx+1,leftnum+1,rightnum,left2remove,right2tremove);
        }
        else if(s[idx]==')'&&leftnum>rightnum){
            getPath(s,idx+1,leftnum,rightnum+1,left2remove,right2tremove);
        }
        else{
            getPath(s,idx+1,leftnum,rightnum,left2remove,right2tremove);
        }
        path.pop_back();
        return ;
    }
};
// @lc code=end

