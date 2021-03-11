/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (69.37%)
 * Likes:    1039
 * Dislikes: 0
 * Total Accepted:    108.2K
 * Total Submissions: 156K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */

// @lc code=start
class Solution {
public:
    /*递推思想：当前为n个时可看做：
    1. 在n-1的搜索树的基础上加上n，其中包括以n为根和以n为结点，共2*a[n-1]
    2. 在n-1的搜索树的基础上替换：
        （1）替换掉原来的n-2个：此时没被替换的有n-1-(n-2)=1个，所以有a[1]种情况，
        而每种情况又可以看做n-2个元素的搜索树，所以有a[n-2]个。所以总共有a[1]*a[n-2];
        ...（替换掉n-i个情况同理）
        （n-2）
    综合以上两种情况可得a[n]=2*a[n-1]+a[1]*a[n-2]+a[2]*a[n-3]...+a[n-2]*a[1]
    */
    int numTrees(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int* a=new int[n+1];
        a[1]=1;
        for(int i=2;i<=n;i++){
            a[i]=2*a[i-1];
            for(int j=1;j<=i-2;j++){
                a[i]+=a[j]*a[i-1-j];
            }
        }
        int res=a[n];
        delete []a;
        return res;
    }
};
// @lc code=end

