/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (62.86%)
 * Likes:    621
 * Dislikes: 0
 * Total Accepted:    143.1K
 * Total Submissions: 227.5K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return {};
        }
        sort(nums.begin(),nums.end());
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
            if(i&&nums[i]==nums[i-1]&&!v[i-1]){
                continue;
            }
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

