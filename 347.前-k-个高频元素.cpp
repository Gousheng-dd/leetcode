/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (61.96%)
 * Likes:    672
 * Dislikes: 0
 * Total Accepted:    140K
 * Total Submissions: 226.1K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
 * 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
 * 你可以按任意顺序返回答案。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++){
            if(ump.find(nums[i])!=ump.end()){
                ump[nums[i]]++;
            }
            else{
                ump[nums[i]]=1;
            }
        }
        priority_queue<pair<int,int> > p;
        for(auto it=ump.begin();it!=ump.end();it++){
            p.push({it->second,it->first});
        }
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(p.top().second);
            p.pop();
        }
        return res;
    }
};
// @lc code=end

