/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 *
 * https://leetcode-cn.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Medium (47.68%)
 * Likes:    467
 * Dislikes: 0
 * Total Accepted:    49.7K
 * Total Submissions: 104.2K
 * Testcase Example:  '"bcabc"'
 *
 * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 * 
 * 注意：该题与 1081
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
 * 相同
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "bcabc"
 * 输出："abc"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbacdcbc"
 * 输出："acdb"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //单调栈+hash，栈中保持从小到大
    string removeDuplicateLetters(string s) {
        int n=s.size();
        if(n<=1){
            return s;
        }
        int hashtab[30],in[30];
        memset(hashtab,0,sizeof(int)*30);
        memset(in,0,sizeof(int)*30);
        stack<int> st;
        for(int i=1;i<n;i++){
            hashtab[s[i]-'a']++;
        }
        st.push(0);
        in[s[0]-'a']=1;
        for(int i=1;i<n;i++){
            if(st.empty()){
                st.push(i);
                hashtab[s[i]-'a']--;
                in[s[i]-'a']=1;
                continue;
            }
            if(in[s[i]-'a']){
                hashtab[s[i]-'a']--;
                continue;
            }
            while(s[i]<=s[st.top()]&&hashtab[s[st.top()]-'a']){
                in[s[st.top()]-'a']=0;
                st.pop();
                if(st.empty()){
                    break;
                }
            }
            st.push(i);
            in[s[i]-'a']=1;
            hashtab[s[i]-'a']--;
        }
        string res(st.size(),' ');
        for(int i=st.size()-1;i>=0;i--){
            res[i]=s[st.top()];
            st.pop();
        }
        return res;
    }
};
// @lc code=end

