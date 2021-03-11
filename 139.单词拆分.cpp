/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (49.32%)
 * Likes:    864
 * Dislikes: 0
 * Total Accepted:    123.9K
 * Total Submissions: 251K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 
 * 说明：
 * 
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //动态规划
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size(),m=wordDict.size();
        if(!n||!m){
            return false;
        }
        unordered_set<string> ust;
        for(int i=0;i<m;i++){
            ust.insert(wordDict[i]);
        }
        bool* dp=new bool[n+1];
        memset(dp,0,sizeof(bool)*(n+1));
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]&&(ust.find(s.substr(j,i-j))!=ust.end())){
                    dp[i]=true;
                    break;
                }
            }
        }
        bool res=dp[n];
        delete []dp;
        return res;
    }
};
// @lc code=end

