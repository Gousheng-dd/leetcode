/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (56.05%)
 * Likes:    1164
 * Dislikes: 0
 * Total Accepted:    228.6K
 * Total Submissions: 407.8K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        vector<string> res;
        string comb="";
        genLetterCombination(digits,0,comb,res);
        return res;
    }
private:
    string diglet[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void genLetterCombination(string &digits,int idx,string &comb,vector<string> &res){
        if(idx==digits.size()){
            res.push_back(comb);
            return;
        }
        int num=digits[idx]-'2';
        for(int i=0;i<diglet[num].size();i++){
            comb.push_back(diglet[num][i]);
            genLetterCombination(digits,idx+1,comb,res);
            comb.pop_back();
        }
        return;
    }
};
// @lc code=end

