/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 *
 * https://leetcode-cn.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (66.37%)
 * Likes:    1124
 * Dislikes: 0
 * Total Accepted:    127.1K
 * Total Submissions: 191.3K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。
 * 
 * 假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,4,2,2]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,1,3,4,2]
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,1]
 * 输出：1
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [1,1,2]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * nums.length == n + 1
 * 1 
 * nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 如何证明 nums 中至少存在一个重复的数字?
 * 你可以在不修改数组 nums 的情况下解决这个问题吗？
 * 你可以只用常量级 O(1) 的额外空间解决这个问题吗？
 * 你可以设计一个时间复杂度小于 O(n^2) 的解决方案吗？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //二分
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(!n){
            return 0;
        }
        int begin=1,end=n-1;
        while(begin<end){
            int mid=(begin+end)>>1;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid){
                    cnt++;
                }
            }
            if(cnt<=mid){
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

