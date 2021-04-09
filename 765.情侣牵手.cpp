/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 *
 * https://leetcode-cn.com/problems/couples-holding-hands/description/
 *
 * algorithms
 * Hard (66.71%)
 * Likes:    250
 * Dislikes: 0
 * Total Accepted:    25.3K
 * Total Submissions: 37.9K
 * Testcase Example:  '[0,2,1,3]'
 *
 * N 对情侣坐在连续排列的 2N 个座位上，想要牵到对方的手。 计算最少交换座位的次数，以便每对情侣可以并肩坐在一起。
 * 一次交换可选择任意两人，让他们站起来交换座位。
 * 
 * 人和座位用 0 到 2N-1 的整数表示，情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2N-2,
 * 2N-1)。
 * 
 * 这些情侣的初始座位  row[i] 是由最初始坐在第 i 个座位上的人决定的。
 * 
 * 示例 1:
 * 
 * 
 * 输入: row = [0, 2, 1, 3]
 * 输出: 1
 * 解释: 我们只需要交换row[1]和row[2]的位置即可。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: row = [3, 2, 0, 1]
 * 输出: 0
 * 解释: 无需交换座位，所有的情侣都已经可以手牵手了。
 * 
 * 
 * 说明:
 * 
 * 
 * len(row) 是偶数且数值在 [4, 60]范围内。
 * 可以保证row 是序列 0...len(row)-1 的一个全排列。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        //并查集
        int n=row.size();
        if(!n){
            return 0;
        }
        int cpnum=n/2;
        int *f=new int[cpnum];
        for(int i=0;i<cpnum;i++){
            f[i]=i;
        }
        for(int i=0;i<cpnum;i++){
            add(f,row[2*i]/2,row[2*i+1]/2);
        }
        unordered_map<int,int> mp;
        for(int i=0;i<cpnum;i++){
            int fx=getFather(f,i);
            if(mp.find(fx)!=mp.end()){
                mp[fx]++;
            }
            else{
                mp[fx]=1;
            }
        }
        int res=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            res+=it->second-1;
        }
        delete []f;
        return res;
    }
private:
    int getFather(int *f,int x){
        int fx=x;
        while(f[fx]!=fx){
            fx=f[fx];
        }
        return fx;
    }

    void add(int *f,int x,int y){
        int fx=getFather(f,x);
        int fy=getFather(f,y);
        if(fx==fy){
            return;
        }
        f[fx]=fy;
        return ;
    }
};
// @lc code=end

