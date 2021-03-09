/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (40.84%)
 * Likes:    1005
 * Dislikes: 0
 * Total Accepted:    114.7K
 * Total Submissions: 280.5K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 
 * 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 和 t 由英文字母组成
 * 
 * 
 * 
 * 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
 */

// @lc code=start
class Solution {
public:
    //滑动窗口
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        if(!n||!m){
            return "";
        }
        int hashtab[256];
        memset(hashtab,0,sizeof(int)*256);
        int neednum=m,res=0x3f3f3f3f,begin=0,end=0,resb=-1,rese=-1;
        for(int i=0;i<m;i++){
            hashtab[t[i]]++;
        }
        while(1){
            while(end<n&&neednum){
                if(hashtab[s[end]]>0){
                    neednum--;
                }
                hashtab[s[end]]--;
                end++;
            }
            if(neednum){
                break;
            }
            while(hashtab[s[begin]]<0){
                hashtab[s[begin]]++;
                begin++;
            }
            if(res>end-begin){
                resb=begin;
                rese=end;
                res=end-begin;
            }
            hashtab[s[begin]]++;
            begin++;
            neednum++;
        }
        if(resb==-1){
            return "";
        }
        else{
            return s.substr(resb,res);
        }
    }
};
// @lc code=end

