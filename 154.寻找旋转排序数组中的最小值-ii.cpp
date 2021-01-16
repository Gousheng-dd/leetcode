/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (50.46%)
 * Likes:    220
 * Dislikes: 0
 * Total Accepted:    46K
 * Total Submissions: 91.2K
 * Testcase Example:  '[1,3,5]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 请找出其中最小的元素。
 * 
 * 注意数组中可能存在重复的元素。
 * 
 * 示例 1：
 * 
 * 输入: [1,3,5]
 * 输出: 1
 * 
 * 示例 2：
 * 
 * 输入: [2,2,2,0,1]
 * 输出: 0
 * 
 * 说明：
 * 
 * 
 * 这道题是 寻找旋转排序数组中的最小值 的延伸题目。
 * 允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()){
            return -1;
        }
        int l=0,r=nums.size()-1,mid=0;
        while (nums[l]>=nums[r]){
            if(r-l==1){//结束条件
                return nums[r];
            }
            mid=(l+r)/2;
            if(nums[mid]==nums[l]&&nums[mid]==nums[r]){//此时需要直接遍历
                int minnum=nums[0];
                for(int i=1;i<nums.size();i++){
                    minnum=min(minnum,nums[i]);
                }
                return minnum;
            }
            if(nums[mid]>=nums[l]){
                l=mid;
            }
            else if(nums[mid]<=nums[r]){
                r=mid;
            }
        }
        return nums[mid];
    }
};
// @lc code=end

