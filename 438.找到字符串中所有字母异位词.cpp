/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (49.46%)
 * Likes:    489
 * Dislikes: 0
 * Total Accepted:    58.2K
 * Total Submissions: 117.4K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
 * 
 * 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
 * 
 * 说明：
 * 
 * 
 * 字母异位词指字母相同，但排列不同的字符串。
 * 不考虑答案输出的顺序。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * s: "cbaebabacd" p: "abc"
 * 
 * 输出:
 * [0, 6]
 * 
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * s: "abab" p: "ab"
 * 
 * 输出:
 * [0, 1, 2]
 * 
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()==0||p.size()==0||p.size()>s.size()){
            return {};
        }
        int m=s.size(),n=p.size();
        int* pcnt=new int[26];
        memset(pcnt,0,sizeof(int)*26);
        int* scnt=new int[26];
        memset(scnt,0,sizeof(int)*26);
        for(int i=0;i<n;i++){
            pcnt[p[i]-'a']++;
            scnt[s[i]-'a']++;
        }
        vector<int> res;
        if(isEqual(pcnt,scnt)){
            res.push_back(0);
        }
        for(int i=n;i<m;i++){
            scnt[s[i-n]-'a']--;
            scnt[s[i]-'a']++;
            if(isEqual(pcnt,scnt)){
                res.push_back(i-n+1);
            }
        }
        return res;
    }
private:
    bool isEqual(int *a,int *b){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

