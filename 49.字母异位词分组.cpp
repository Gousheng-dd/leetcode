/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (65.54%)
 * Likes:    674
 * Dislikes: 0
 * Total Accepted:    169.3K
 * Total Submissions: 258.2K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //哈希法
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        if(n==0){
            return {};
        }
        vector<pair<string,int> > strh;
        for(int i=0;i<n;i++){
            strh.push_back(make_pair(strhash(strs[i]),i));
        }
        sort(strh.begin(),strh.end(),cmp);
        vector<string> same;
        vector<vector<string> > res;
        same.push_back(strs[strh[0].second]);
        for(int i=1;i<n;i++){
            if(strh[i].first!=strh[i-1].first){
                res.push_back(same);
                same.clear();
            }
            same.push_back(strs[strh[i].second]);
        }
        res.push_back(same);
        return res;
    }
private:
    static bool cmp(pair<string,int> &a,pair<string,int> &b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }

    string strhash(string &a){
        int hashtab[26];
        memset(hashtab,0,sizeof(int)*26);
        for(int i=0;i<a.size();i++){
            hashtab[a[i]-'a']++;
        }
        string res="";
        for(int i=0;i<26;i++){
            while(hashtab[i]){
                res.push_back(i+'a');
                hashtab[i]--;
            }
        }
        return res;
    }
};
// @lc code=end

