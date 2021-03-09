/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (44.54%)
 * Likes:    827
 * Dislikes: 0
 * Total Accepted:    198.2K
 * Total Submissions: 444.5K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * intervals[i].length == 2
 * 0 i i 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //根据区间起点升序排序，逐个合并
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0){
            return {};
        }
        sort(intervals.begin(),intervals.end(),cmp);
        int begin=intervals[0][0],end=intervals[0][1];
        vector<vector<int> > res;
        for(int i=1;i<n;i++){
            if(intervals[i][0]>end){
                res.push_back({begin,end});
                begin=intervals[i][0],end=intervals[i][1];
            }
            else{
                end=max(end,intervals[i][1]);
            }
        }
        res.push_back({begin,end});
        return res;
    }
private:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
};
// @lc code=end

