/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (55.04%)
 * Likes:    459
 * Dislikes: 0
 * Total Accepted:    43K
 * Total Submissions: 78K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 * 
 * 丑数就是质因数只包含 2, 3, 5 的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 
 * 说明:  
 * 
 * 
 * 1 是丑数。
 * n 不超过1690。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0){
            return -1;
        }
        int* uglynum=new int[n+10];
        int *ugly2,*ugly3,*ugly5;
        ugly2=ugly3=ugly5=uglynum+1;
        int cnt=1;
        uglynum[1]=1;
        while(cnt<n){
            int u2=(*ugly2)*2,u3=(*ugly3)*3,u5=(*ugly5)*5;
            uglynum[++cnt]=min(u2,u3,u5);
            while((*ugly2)*2<=uglynum[cnt]){
                ugly2++;
            }
            while((*ugly3)*3<=uglynum[cnt]){
                ugly3++;
            }
            while((*ugly5)*5<=uglynum[cnt]){
                ugly5++;
            }
        }
        return uglynum[n];
    }
private:
    int min(int a,int b,int c){
        int res=a<b?a:b;
        return res<c?res:c;
    }
};
// @lc code=end

