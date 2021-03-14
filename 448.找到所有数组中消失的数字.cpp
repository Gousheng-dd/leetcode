/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 *
 * https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (63.72%)
 * Likes:    667
 * Dislikes: 0
 * Total Accepted:    97.8K
 * Total Submissions: 153.5K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
 * 
 * 找到所有在 [1, n] 范围之间没有出现在数组中的数字。
 * 
 * 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * [4,3,2,7,8,2,3,1]
 * 
 * 输出:
 * [5,6]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //原地修改：nums[nums[i]-1]加上n，最后看谁小于等于n
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        if(!n){
            return {};
        }
        for(int i=0;i<n;i++){
            nums[(nums[i]-1)%n]+=n;
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(nums[i]<=n){
                res.push_back(i+1);
            }
        }
        return res;
    }
};
// @lc code=end

