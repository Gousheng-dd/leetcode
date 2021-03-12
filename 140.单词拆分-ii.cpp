/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 *
 * https://leetcode-cn.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (44.48%)
 * Likes:    426
 * Dislikes: 0
 * Total Accepted:    41.7K
 * Total Submissions: 93.6K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典
 * wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
 * 
 * 说明：
 * 
 * 
 * 分隔时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * 输出:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * 示例 2：
 * 
 * 输入:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * 输出:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * 解释: 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出:
 * []
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //记忆化搜索
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size(),m=wordDict.size();
        if(!n||!m){
            return {};
        }
        for(int i=0;i<m;i++){
            ust.insert(wordDict[i]);
        }
        wordBreakCore(s,0);
        return ump[0];
    }
private:
    unordered_map<int,vector<string> >ump;
    unordered_set<string> ust;
    void wordBreakCore(string &s,int idx){
        if(ump.count(idx)){
            return;
        }
        if(idx==s.size()){
            ump[idx]={""};
            return;
        }
        ump[idx]={};
        for(int i=idx+1;i<=s.size();i++){
            string word=s.substr(idx,i-idx);
            if(ust.count(word)){
                wordBreakCore(s,i);
                for(int j=0;j<ump[i].size();j++){
                    ump[idx].push_back(ump[i][j]==""?word:word+" "+ump[i][j]);
                }
            }
        }
    }
};
// @lc code=end

