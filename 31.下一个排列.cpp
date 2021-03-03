/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (36.51%)
 * Likes:    980
 * Dislikes: 0
 * Total Accepted:    138.9K
 * Total Submissions: 380.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须 原地 修改，只允许使用额外常数空间。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,2,1]
 * 输出：[1,2,3]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,1,5]
 * 输出：[1,5,1]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==0){
            return;
        }
        int smallidx=0,bigidx=-1;
        for(int i=nums.size()-1;i>=1;i--){
            if(nums[i]>nums[i-1]){
                smallidx=i-1;
                break;
            }
        }
        for(int i=nums.size()-1;i>smallidx;i--){
            if(nums[i]>nums[smallidx]){
                bigidx=i;
                break;
            }
        }
        if(bigidx==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        int tem=nums[smallidx];
        nums[smallidx]=nums[bigidx];
        nums[bigidx]=tem;
        sort(nums.begin()+smallidx+1,nums.end());
        return;
    }
};
// @lc code=end

