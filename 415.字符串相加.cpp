/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (51.94%)
 * Likes:    342
 * Dislikes: 0
 * Total Accepted:    104.3K
 * Total Submissions: 200.7K
 * Testcase Example:  '"11"\n"123"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * num1 和num2 的长度都小于 5100
 * num1 和num2 都只包含数字 0-9
 * num1 和num2 都不包含任何前导零
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1=num1.size(),len2=num2.size();
        if(!len1){
            return num2;
        }
        if(!len2){
            return num1;
        }
        int sum=0,carry=0,idx1=len1-1,idx2=len2-1;
        string res="";
        while(idx1>=0&&idx2>=0){
            sum=num1[idx1]-'0'+num2[idx2]-'0'+carry;
            if(sum>=10){
                carry=1;
                sum-=10;
            }
            else{
                carry=0;
            }
            res.push_back(sum+'0');
            idx1--;
            idx2--;
        }
        while(idx1>=0){
            sum=num1[idx1]-'0'+carry;
            if(sum>=10){
                carry=1;
                sum-=10;
            }
            else{
                carry=0;
            }
            res.push_back(sum+'0');
            idx1--;
        }
        while(idx2>=0){
            sum=num2[idx2]-'0'+carry;
            if(sum>=10){
                carry=1;
                sum-=10;
            }
            else{
                carry=0;
            }
            res.push_back(sum+'0');
            idx2--;
        }
        if(carry){
            res.push_back(carry+'0');
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

