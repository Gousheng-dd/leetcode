/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (79.62%)
 * Likes:    1042
 * Dislikes: 0
 * Total Accepted:    206.4K
 * Total Submissions: 259.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[[],[0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * nums 中的所有元素 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(!nums.size()){
            return {};
        }
        vector<int> subs;
        subsetsCore(nums,subs,0);
        return res;
    }
private:
    vector<vector<int > > res;
    void subsetsCore(vector<int> &nums,vector<int> subs,int idx){
        res.push_back(subs);
        for(int i=idx;i<nums.size();i++){
            subs.push_back(nums[i]);
            subsetsCore(nums,subs,i+1);
            subs.pop_back();
        }
        return ;
    }
};
// @lc code=end

