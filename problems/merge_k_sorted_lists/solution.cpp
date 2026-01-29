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
class compare{
    public:
    bool operator() (ListNode* a,ListNode* b){
        return a->val >b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         priority_queue<ListNode*, vector<ListNode*>, compare> minheap; 
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                minheap.push(lists[i]);
            }
        } 
        ListNode dummy(0);
        ListNode* tail = &dummy; 
        while (!minheap.empty()) { 
            ListNode* curr = minheap.top();
            minheap.pop(); 
            tail->next = curr;
            tail = tail->next; 
            if (curr->next != NULL) {
                minheap.push(curr->next);
            }
        } 
        return dummy.next;
    }
};