/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 *
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Medium (36.04%)
 * Likes:    495
 * Dislikes: 0
 * Total Accepted:    49.7K
 * Total Submissions: 137.8K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * 给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 * 
 * 请你找出符合题意的 最短 子数组，并输出它的长度。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,6,4,8,10,9,15]
 * 输出：5
 * 解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^5 
 * 
 * 
 * 
 * 
 * 进阶：你可以设计一个时间复杂度为 O(n) 的解决方案吗？
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //单调栈，从左往右找前面有比他大的（从小到大），从右往左找后面有比他小的（从大到小）
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return 0;
        }
        int begin=0x3f3f3f3f,end=-1;
        bool flag=false;
        stack<int> s;
        s.push(0);
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[s.top()]){
                s.push(i);
                continue;
            }
            while(nums[i]<nums[s.top()]){
                begin=min(begin,s.top());
                s.pop();
                flag=true;
                if(s.empty()){
                    break;
                }
            }
            s.push(i);
        }
        if(!flag){
            return 0;
        }
        while(!s.empty()){
            s.pop();
        }
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[s.top()]){
                s.push(i);
                continue;
            }
            while(nums[i]>nums[s.top()]){
                end=max(end,s.top());
                s.pop();
                if(s.empty()){
                    break;
                }
            }
            s.push(i);
        }
        return end-begin+1;
    }
};
// @lc code=end

