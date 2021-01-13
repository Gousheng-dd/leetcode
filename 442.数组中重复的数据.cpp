/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 *
 * https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (68.26%)
 * Likes:    324
 * Dislikes: 0
 * Total Accepted:    28.5K
 * Total Submissions: 41.8K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
 * 
 * 找到所有出现两次的元素。
 * 
 * 你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？
 * 
 * 示例：
 * 
 * 
 * 输入:
 * [4,3,2,7,8,2,3,1]
 * 
 * 输出:
 * [2,3]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()){
            return res;
        }
        for(int i=0;i<nums.size();i++){
            int idx=abs(nums[i]);
            if(nums[idx-1]>0){//没出现过置为负数
                nums[idx-1]=-nums[idx-1];
            }
            else{//出现过则加入res
                res.push_back(idx);
            }
        }
        return res;
    }
};
// @lc code=end

