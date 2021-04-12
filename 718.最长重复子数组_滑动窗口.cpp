/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 *
 * https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (55.46%)
 * Likes:    417
 * Dislikes: 0
 * Total Accepted:    57.5K
 * Total Submissions: 103.6K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * 输出：3
 * 解释：
 * 长度最长的公共子数组是 [3, 2, 1] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        /*字符串滑动匹配
          B相对于A滑动：
                  [1,2,3,2,1]                  [1,2,3,2,1]
          [3,2,1,4,7]                 -> [3,2,1,4,7]
          以A[0]和B[m-1]为起点向后匹配     以A[0]和B[m-2]为起点向后匹配
          直到滑动到以A[n-1]和B[0]为起点进行匹配
          时间复杂度O(m*n) 空间复杂度O(1)
        */
        int n=A.size(),m=B.size();
        int res=0;
        //先枚举A[0]与B[i]匹配的情况
        for(int i=0;i<m;i++){
            res=max(res,findMaxSubLength(A,B,0,i));
        }
        //枚举A[i]与B[0]匹配情况
        for(int i=0;i<n;i++){
            res=max(res,findMaxSubLength(A,B,i,0));
        }
        return res;
    }
private:
    int findMaxSubLength(vector<int>& A, vector<int>& B,int idxa,int idxb){
        int maxlen=0,nowlen=0;
        int n=A.size(),m=B.size();
        while(idxa<n&&idxb<m){
            if(A[idxa]==B[idxb]){
                nowlen++;
            }
            else{
                nowlen=0;
            }
            maxlen=max(maxlen,nowlen);
            idxa++;
            idxb++;
        }
        return maxlen;
    }
};
// @lc code=end

