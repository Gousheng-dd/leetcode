/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode-cn.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (64.99%)
 * Likes:    507
 * Dislikes: 0
 * Total Accepted:    84K
 * Total Submissions: 129K
 * Testcase Example:  '"abc"'
 *
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
 * 
 * 示例 2：
 * 
 * 输入："aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的字符串长度不会超过 1000 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        if(!n){
            return 0;
        }
        int res=n;
        bool** dp=new bool*[n];
        for(int i=0;i<n;i++){
            dp[i]=new bool[n];
            memset(dp[i],0,sizeof(bool)*n);
        }
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(len==2){
                    dp[i][j]=s[i]==s[j];
                }
                else{
                    dp[i][j]=s[i]==s[j]&&dp[i+1][j-1];
                }
                res+=int(dp[i][j]);
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

