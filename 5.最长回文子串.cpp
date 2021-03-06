/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (33.30%)
 * Likes:    3286
 * Dislikes: 0
 * Total Accepted:    495.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a"
 * 输出："a"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "ac"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由数字和英文字母（大写和/或小写）组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0){
            return 0;
        }
        int **isPal=new int*[n];
        for(int i=0;i<n;i++){
            isPal[i]=new int[n];
            memset(isPal[i],0,sizeof(int)*n);
        }
        int begin=0,maxlen=1;
        for(int i=0;i<n;i++){
            isPal[i][i]=1;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    if(len==2){
                        isPal[i][j]=1;
                    }
                    else{
                        isPal[i][j]=isPal[i+1][j-1];
                    }
                }
                if(isPal[i][j]){
                    begin=i,maxlen=len;
                }
            }
        }
        for(int i=0;i<n;i++){
            delete[] isPal[i];
        }
        return s.substr(begin,maxlen);
    }
};
// @lc code=end

