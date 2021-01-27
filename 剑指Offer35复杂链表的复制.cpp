#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        copyNode(head);
        changeNode(head);
        return selectNode(head);
    }
private:
    void copyNode(Node* head){
        Node* pNode=head,*pNext,*newNode;
        while(pNode){
            pNext=pNode->next;
            newNode=new Node(pNode->val);
            pNode->next=newNode;
            newNode->next=pNext;
            pNode=pNext;
            if(pNext){
                pNext=pNext->next;
            }
        }
        return;
    }
    void changeNode(Node* head){
        Node* pNode=head,*newNode=head->next;
        while(newNode){
            if(pNode->random){
                newNode->random=pNode->random->next;
            }
            pNode=newNode->next;
            if(pNode){
                newNode=pNode->next;
            }
            else{
                newNode=NULL;
            }
        }
        return;
    }
    Node* selectNode(Node* head){
        Node* pNode=head,*newNode=head->next,*newHead=head->next;
        while(pNode&&newNode){
            pNode->next=pNode->next->next;
            pNode=pNode->next;
            if(newNode->next){
                newNode->next=newNode->next->next;
            }
            else{
                newNode->next=NULL;
            }
            newNode=newNode->next;
        }
        return newHead;
    }
};

int main()
{
    Solution s;
    Node* head=new Node(7);
    head=s.copyRandomList(head);
    cout<<head->val<<endl;
    return 0;
}