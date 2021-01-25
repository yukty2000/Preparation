/* Leetcode

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

*/

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

class MyCompare {
public:
  bool operator()(ListNode *a, ListNode *b) {
    return (a->val) > (b->val);
  }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,MyCompare> q;
        int n=lists.size();
        if(n==0)
            return NULL;
        for(int i=0;i<n;i++)
        {
            struct ListNode *temp=lists[i];
            while(temp!=NULL)
            {
                q.push(temp);
                temp=temp->next;
            }
        }
        ListNode *head=NULL,*prev=NULL;
        while(!q.empty())
        {
            ListNode *temp=q.top();
            q.pop();
            if(head==NULL)
            {
                head=temp;
                prev=temp;
            }
            else
            {
                prev->next=temp;
                prev=temp;
            }
        }
        if(head!=NULL)
            prev->next=NULL;
        return head;
    }
};
