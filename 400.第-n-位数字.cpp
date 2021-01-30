/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 *
 * https://leetcode-cn.com/problems/nth-digit/description/
 *
 * algorithms
 * Medium (38.88%)
 * Likes:    142
 * Dislikes: 0
 * Total Accepted:    12.9K
 * Total Submissions: 33.2K
 * Testcase Example:  '3'
 *
 * 在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 位数字。
 * 
 * 
 * 
 * 注意：n 是正数且在 32 位整数范围内（n < 2^31）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：3
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：11
 * 输出：0
 * 解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        if(n<0){
            return -1;
        }
        if(n<10){
            return n;
        }
        long long dig=10;
        int num=1;
        while(n>=dig*num){
            n-=dig*num;
            if(dig==10){
                dig=90;
            }
            else{
                dig*=10;
            }
            num++;
        }
        int startnum=int(pow(10,num-1));
        int restnum=n%num;
        n/=num;
        n+=startnum;
        for(int i=1;i<num-restnum;i++){
            n/=10;
        }
        return n%10;
    }
};
// @lc code=end

