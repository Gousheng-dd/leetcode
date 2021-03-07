/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (34.62%)
 * Likes:    1197
 * Dislikes: 0
 * Total Accepted:    130.1K
 * Total Submissions: 375.6K
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s[i] 为 '(' 或 ')'
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n<=1){
            return 0;
        }
        int *dp=new int[n];
        int res=0;
        memset(dp,0,sizeof(int)*n);
        for(int i=1;i<n;i++){
            if(s[i]=='('){
                continue;
            }
            if(s[i-1]=='('){
                if(i==1){
                    dp[i]=2;
                }
                else{
                    dp[i]=dp[i-2]+2;
                }
            }
            else if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
                if(i-dp[i-1]-2>=0){
                    dp[i]=dp[i-dp[i-1]-2]+dp[i-1]+2;
                }
                else{
                    dp[i]=dp[i-1]+2;
                }
            }
            if(dp[i]>res){
                res=dp[i];
            }
        }
        return res;
    }
};
// @lc code=end

