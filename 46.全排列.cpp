/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (77.66%)
 * Likes:    1185
 * Dislikes: 0
 * Total Accepted:    267.4K
 * Total Submissions: 344.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return {};
        }
        vector<int> per;
        bool *v=new bool[n];
        memset(v,0,sizeof(bool)*n);
        permuteCore(nums,v,per);
        return res;
    }
private:
    vector<vector<int> > res;
    void permuteCore(vector<int>& nums,bool *v,vector<int> &per){
        if(per.size()==nums.size()){
            res.push_back(per);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!v[i]){
                per.push_back(nums[i]);
                v[i]=true;
                permuteCore(nums,v,per);
                v[i]=false;
                per.pop_back();
            }
        }
        return;
    }
};
// @lc code=end

