/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (39.44%)
 * Likes:    3751
 * Dislikes: 0
 * Total Accepted:    342.5K
 * Total Submissions: 863.4K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums1 = [0,0], nums2 = [0,0]
 * 输出：0.00000
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums1 = [], nums2 = [1]
 * 输出：1.00000
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：nums1 = [2], nums2 = []
 * 输出：2.00000
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 
 * 0 
 * 1 
 * -10^6 
 * 
 * 
 * 
 * 
 * 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
 * 
 */

// @lc code=start
class Solution {
public:
    //O(m+n)solution,类似于合并有序数组
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m+n==0){
            return 0.0;
        }
        int p1=0,p2=0,pre=0;
        while(p1<m&&p2<n){
            if(p1+p2==(m+n)/2){
                break;
            }
            if(nums1[p1]>nums2[p2]){
                p2++;
                pre=2;
            }
            else{
                p1++;
                pre=1;
            }
        }
        if(p1+p2<(m+n)/2&&p1==m){
            p2+=(m+n)/2-(p1+p2);
            pre=2;
        }
        if(p1+p2<(m+n)/2&&p2==n){
            p1+=(m+n)/2-(p1+p2);
            pre=1;
        }
        if((m+n)%2){
            if(p1==m){
                return double(nums2[p2]);
            }
            else if(p2==n){
                return double(nums1[p1]);
            }
            else{
                return nums1[p1]<=nums2[p2]?double(nums1[p1]):double(nums2[p2]);
            }
        }
        else{
            int fis;
            if(pre==1){
                fis=nums1[p1-1];
            }
            else{
                fis=nums2[p2-1];
            }
            if(p1==m){
                return (fis+nums2[p2])/2.0;
            }
            else if(p2==n){
                return (fis+nums1[p1])/2.0;
            }
            else{
                return nums1[p1]<=nums2[p2]?(fis+nums1[p1])/2.0:(fis+nums2[p2])/2.0;
            }
        }
        return 0.0;
    }
};
// @lc code=end

