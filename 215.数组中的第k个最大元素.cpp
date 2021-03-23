/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.79%)
 * Likes:    962
 * Dislikes: 0
 * Total Accepted:    285.9K
 * Total Submissions: 442.5K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k||!n){
            return 0;
        }
        k--;
        int mid,begin=0,end=n-1;
        while(begin<=end){
            mid=partition(nums,begin,end);
            if(mid==k){
                return nums[k];
            }
            if(mid>k){
                end=mid-1;
            }
            else{
                begin=mid+1;
            }
        }
        return -1;
    }
private:
    int partition(vector<int> &nums,int begin,int end){
        int target=nums[begin];
        int left=begin,right=end;
        while(left<right){
            while(left<right&&nums[right]<=target){
                right--;
            }
            nums[left]=nums[right];
            while(left<right&&nums[left]>=target){
                left++;
            }
            nums[right]=nums[left];
        }
        nums[left]=target;
        return left;
    }
};
// @lc code=end

