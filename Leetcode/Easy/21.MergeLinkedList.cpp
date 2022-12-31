/**
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
  Question Link: https://leetcode.com/problems/merge-two-sorted-lists/
**/
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        else if(list2==NULL)return list1;
        ListNode* head=NULL;
        if(list1->val<list2->val){
        head=new ListNode(list1->val);
        list1=list1->next;
        }
        else{
            head=new ListNode(list2->val);
        list2=list2->next;
        }
        ListNode*temp=head;
        
        while(list1&&list2){
            if(list1->val<list2->val){
                ListNode* newnode=new ListNode(list1->val);
                temp->next=newnode;
                temp=newnode;
                list1=list1->next;
            }
            else{
                ListNode* newnode=new ListNode(list2->val);
                temp->next=newnode;
                temp=newnode;
                list2=list2->next;
            }
        }
        while(list1){
             ListNode* newnode=new ListNode(list1->val);
                temp->next=newnode;
                temp=newnode;
                list1=list1->next;
        }
        while(list2){
            ListNode* newnode=new ListNode(list2->val);
                temp->next=newnode;
                temp=newnode;
                list2=list2->next;
        }
        return head;
    }
};
