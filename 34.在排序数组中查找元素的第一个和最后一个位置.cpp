/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.13%)
 * Likes:    832
 * Dislikes: 0
 * Total Accepted:    204.2K
 * Total Submissions: 484.1K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 进阶：
 * 
 * 
 * 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * nums 是一个非递减数组
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1,-1};
        }
        vector<int> res;
        int start=0,end=nums.size()-1;
        int left=getFirstk(nums,target,start,end);
        int right=getLastk(nums,target,start,end);
        res.push_back(left);
        res.push_back(right);
        return res;
    }
private:
    int getFirstk(vector<int>& nums,int target,int begin,int end){
        if(begin>end){
            return -1;
        }
        int mid=(begin+end)>>1;
        if(nums[mid]>target){
            end=mid-1;
        }
        else if(nums[mid]<target){
            begin=mid+1;
        }
        else{
            if((mid-1>=0&&nums[mid-1]!=target)||mid==0){
                return mid;
            }
            end=mid-1;
        }
        return getFirstk(nums,target,begin,end);
    }
    int getLastk(vector<int>& nums,int target,int begin,int end){
        if(begin>end){
            return -1;
        }
        int mid=(begin+end)>>1;
        if(nums[mid]>target){
            end=mid-1;
        }
        else if(nums[mid]<target){
            begin=mid+1;
        }
        else{
            if((mid+1<=nums.size()-1&&nums[mid+1]!=target)||mid==nums.size()-1){
                return mid;
            }
            begin=mid+1;
        }
        return getLastk(nums,target,begin,end);
    }
};
// @lc code=end

