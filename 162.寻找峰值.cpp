/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 *
 * https://leetcode-cn.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (48.71%)
 * Likes:    403
 * Dislikes: 0
 * Total Accepted:    86.1K
 * Total Submissions: 176.7K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 峰值元素是指其值大于左右相邻值的元素。
 * 
 * 给你一个输入数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
 * 
 * 你可以假设 nums[-1] = nums[n] = -∞ 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,1]
 * 输出：2
 * 解释：3 是峰值元素，你的函数应该返回其索引 2。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,1,3,5,6,4]
 * 输出：1 或 5 
 * 解释：你的函数可以返回索引 1，其峰值元素为 2；
 * 或者返回索引 5， 其峰值元素为 6。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -2^31 
 * 对于所有有效的 i 都有 nums[i] != nums[i + 1]
 * 
 * 
 * 
 * 
 * 进阶：你可以实现时间复杂度为 O(logN) 的解决方案吗？
 * 
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*二分
          若mid位于上坡（nums[mid]<nums[mid+1]）则说明[mid+1,end]一定有峰值点
          若位于下坡则说明[begin,mid]一定有峰值点
        */
        int n=nums.size();
        if(!n){
            return -1;
        }
        int begin=0,end=n-1;
        while(begin<end){
            int mid=(begin+end)>>1;
            if(nums[mid]<nums[mid+1]){
                begin=mid+1;
            }
            else{
                end=mid;
            }
        }
        return begin;
    }
};
// @lc code=end

