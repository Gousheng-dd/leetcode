/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 *
 * https://leetcode-cn.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (54.12%)
 * Likes:    690
 * Dislikes: 0
 * Total Accepted:    83.5K
 * Total Submissions: 154K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 给定一个经过编码的字符串，返回它解码后的字符串。
 * 
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 * 
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 * 
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "3[a]2[bc]"
 * 输出："aaabcbc"
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "3[a2[c]]"
 * 输出："accaccacc"
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "2[abc]3[cd]ef"
 * 输出："abcabccdcdcdef"
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "abc3[cd]xyz"
 * 输出："abccdcdcdxyz"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        if(!n){
            return "";
        }
        int idx=0;
        return decodeStringCore(s,idx);
    }
private:
    string decodeStringCore(string &s,int &idx){
        string res="";
        while(idx<s.size()&&s[idx]!=']'){
            while(s[idx]>='a'&&s[idx]<='z'){
                res.push_back(s[idx]);
                idx++;
            }
            if(idx<s.size()&&s[idx]==']'){
                idx++;
                return res;
            }
            int cnt=getValue(s,idx);
            string sub=decodeStringCore(s,idx);
            for(int i=0;i<cnt;i++){
                res.append(sub);
            }
        }
        idx++;
        return res;
    }
    int getValue(string &s,int &idx){
        int res=0;
        while(s[idx]>='0'&&s[idx]<='9'){
            res*=10;
            res+=s[idx]-'0';
            idx++;
        }
        idx++;
        return res;
    }
};
// @lc code=end

