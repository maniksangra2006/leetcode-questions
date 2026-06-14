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
    int pairSum(ListNode* head) {
        //middle
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //reverse from middle
        ListNode* prev=NULL;
        while(slow){
            ListNode * temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        int ans=0;
        ListNode* p1=head;
        ListNode* p2=prev;
        while(p2){ 
            ans=max(ans,p1->val+p2->val); 
            p1=p1->next;
            p2=p2->next;
        }
       return ans;
    }
};