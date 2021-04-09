/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (40.76%)
 * Likes:    1035
 * Dislikes: 0
 * Total Accepted:    122.1K
 * Total Submissions: 299.5K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * 
 * 
 * 
 * 进阶：你可以实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案吗？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,0]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -2^31 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //tips:长度为n的数组缺失的第一个正数范围一定在1-N+1
        //可以原地hash或者置换解决
        int n=nums.size();
        if(!n){
            return 1;
        }
        for(int i=0;i<n;i++){
            long long idx=(long long)nums[i]-1;
            while(idx>=0&&idx<n&&nums[idx]!=nums[i]){
                swap(nums[idx],nums[i]);
                idx=nums[i]-1;
            }
        }
        int i;
        for(i=0;i<n;i++){
            if(nums[i]!=i+1){
                break;
            }
        }
        return i+1;
    }
};
// @lc code=end

