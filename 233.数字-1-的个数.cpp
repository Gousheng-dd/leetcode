/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 *
 * https://leetcode-cn.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (38.38%)
 * Likes:    192
 * Dislikes: 0
 * Total Accepted:    13.1K
 * Total Submissions: 33.9K
 * Testcase Example:  '13'
 *
 * 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 13
 * 输出：6
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 0
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        if(n<0){
            return -1;
        }
        long long digit=1;
        int cnt=0,high=n/10,low=0,cur=n%10;
        while(high||cur){
            if(cur==0){
                cnt+=high*digit;
            }
            else if(cur==1){
                cnt+=high*digit+low+1;
            }
            else{
                cnt+=(high+1)*digit;
            }
            low+=digit*cur;
            cur=high%10;
            high/=10;
            digit*=10;
        }
        return cnt;
    }
};
// @lc code=end

