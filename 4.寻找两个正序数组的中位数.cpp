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
    //O(log(m+n)),二分
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m+n==0){
            return 0.0;
        }
        if((m+n)%2){
            return double(findKthMinNum(nums1,nums2,(m+n)/2+1));
        }
        else{
            return (findKthMinNum(nums1,nums2,(m+n)/2)+findKthMinNum(nums1,nums2,(m+n)/2+1))/2.0;
        }
    }
    
private:
    int findKthMinNum(vector<int>& nums1, vector<int>& nums2,int k){
        int m=nums1.size(),n=nums2.size();
        int idx1=0,idx2=0,next1,next2;
        while(1){
            if(idx1==m){
                return nums2[idx2+k-1];
            }
            else if(idx2==n){
                return nums1[idx1+k-1];
            }
            else if(k==1){
                return min(nums1[idx1],nums2[idx2]);
            }
            next1=min(idx1+k/2-1,m-1);
            next2=min(idx2+k/2-1,n-1);
            if(nums1[next1]<=nums2[next2]){
                k-=next1-idx1+1;
                idx1=next1+1;
            }
            else{
                k-=next2-idx2+1;
                idx2=next2+1;
            }
        }
        return 0;
    }
};
// @lc code=end

