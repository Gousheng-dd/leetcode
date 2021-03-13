/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (69.91%)
 * Likes:    554
 * Dislikes: 0
 * Total Accepted:    76.6K
 * Total Submissions: 109.5K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 * 
 * 示例:
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");   
 * trie.search("app");     // 返回 true
 * 
 * 说明:
 * 
 * 
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 * 
 * 
 */

// @lc code=start
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        head=new Node();
        head->isend=false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n=word.size();
        if(!n){
            return ;
        }
        Node *pNode=head;
        for(int i=0;i<n;i++){
            if(pNode->next[word[i]-'a']==NULL){
                pNode->next[word[i]-'a']=new Node();
            }
            pNode=pNode->next[word[i]-'a'];
        }
        pNode->isend=true;
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n=word.size();
        if(!n){
            return true;
        }
        Node* pNode=head;
        for(int i=0;i<n;i++){
            if(pNode->next[word[i]-'a']==NULL){
                return false;
            }
            pNode=pNode->next[word[i]-'a'];
        }
        return pNode->isend;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n=prefix.size();
        if(!n){
            return true;
        }
        Node* pNode=head;
        for(int i=0;i<n;i++){
            if(pNode->next[prefix[i]-'a']==NULL){
                return false;
            }
            pNode=pNode->next[prefix[i]-'a'];
        }
        return true;
    }
private:
    struct Node{
        bool isend;
        Node* next[26];
        Node(){
            isend=false;
            for(int i=0;i<26;i++){
                next[i]=NULL;
            }
        }
    };
    Node* head;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

