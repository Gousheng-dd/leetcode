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
    //搜索，TLE
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size(),m=wordDict.size();
        if(!n||!m){
            return false;
        }
        return wordBreakCore(s,wordDict,0);
    }
private:
    bool wordBreakCore(string &s,vector<string>& wordDict,int idx){
        if(idx==s.size()){
            return true;
        }
        for(int i=0;i<wordDict.size();i++){
            if(idx+wordDict[i].size()<=s.size()&&s.substr(idx,wordDict[i].size())==wordDict[i]){
                bool res=wordBreakCore(s,wordDict,idx+wordDict[i].size());
                if(res){
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

